/** System Includes **/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <asm/delay.h>
#include <linux/mutex.h>

#define ZERO 0
#define ONE 1
#define DEVNAME "ParallelPort"
#define PORT 0x378
#define DELAY 500
#define ERR 1

MODULE_LICENSE("Dual BSD/GPL");

//Functions Declarations for syscall definition
int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
ssize_t myWrite(struct file *filp, char __user *buf, size_t count, loff_t *offset);

//Initialization routines
static int myInit(void);
static void myExit(void);

struct file_operations parallelPort={
	.owner = THIS_MODULE,
	.open = myOpen,
	.write = myWrite,
	.release = myRelease
};

//DEFINE_MUTEX(lock);

/*Global variables */
int majNo;
static dev_t mydev; //encodes major number and minor number
struct cdev *my_cdev; //holds character device driver descriptor

//class and device structures
static struct class *mychar_class;
static struct device *mychar_device;

/*
*myOpen:open function of the pseudo driver
*
*/
int myOpen(struct inode *inode, struct file *filep)
{
	printk(KERN_INFO "open successful\n");
	return ZERO;
}

/*
*myRelease : class function of the pseudo driver
*
*/
int myRelease(struct inode *in,struct file *fp)
{
	printk(KERN_INFO "File released\n");
	return ZERO;
}

ssize_t myWrite(struct file *filp, char __user *buf, size_t count, loff_t *offset)
{
//	mutex_lock(&lock);
    
	outb(*buf, PORT);
    mdelay(DELAY);

//	mutex_unlock(&lock);

    return count;
}

static int __init myInit(void)
{
	int ret = -ENODEV;
	int status;

	printk(KERN_INFO "Initializing Character Device\n");

	request_region(PORT, ONE, DEVNAME);
	
	//Allocating device number
	status = alloc_chrdev_region(&mydev, ZERO, ONE, DEVNAME);
	if(status < ZERO)
	{
		printk(KERN_NOTICE "Device numbers allocation failed: %d\n",status);
		goto err;
	}
	printk(KERN_INFO "major number allocated :%d\n",MAJOR(mydev));

/*	my_cdev = cdev_alloc();
	if(my_cdev == NULL)
	{
		printk(KERN_ERR "cdev_alloc failed");
		goto err_cdev_alloc;
	}*/
	cdev_init(my_cdev, &parallelPort);
	my_cdev->owner = THIS_MODULE;

	status = cdev_add(my_cdev, mydev, ONE);
	if(status)
	{
		printk(KERN_ERR "cdev_add failed");
		goto err_cdev_add;
	}

	//create class and entry in sysfs

	mychar_class = class_create( THIS_MODULE, DEVNAME);
	if(IS_ERR(mychar_class))
	{
		printk(KERN_ERR "class_crete failed");
		goto err_class_create;
	}

	//create mychar_device in sysfs and add entry in /dev

	mychar_device = device_create(mychar_class, NULL, mydev, NULL, DEVNAME);
	if(IS_ERR(mychar_device))
	{
		printk(KERN_ERR "device_create failed");
		goto err_device_create;
	}

	return ZERO;

	err_device_create:
		class_destroy(mychar_class);

	err_class_create:
		cdev_del(my_cdev);

	err_cdev_add:
		kfree(my_cdev);
	
//	err_cdev_alloc:
//		unregister_chrdev_region(mydev, ONE);

	err:
		return ret;

}

/*
*myExit :cleanup function to the kernel module
*
*/

static void myExit(void)
{
	release_region(PORT, ONE);
	printk(KERN_INFO "exiting the character driver");
	device_destroy(mychar_class, mydev);
	class_destroy(mychar_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, ONE);
	return ;
}

module_init (myInit);
module_exit(myExit);
