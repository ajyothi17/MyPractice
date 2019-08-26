/** System Includes **/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>


#include <asm/current.h>
#include <asm/highmem.h>
#include <linux/compiler.h>
#include <linux/errno.h>
#include <linux/export.h>
#include <linux/syscalls.h>
#include <asm/cpufeature.h>



#include <linux/kernel.h>
#include <linux/mm_types.h>
#include <linux/mm.h>
#include <asm/page.h>
#include <linux/path.h>
MODULE_LICENSE("Dual BSD/GPL");

/** contents **/
#define DEVNAME "my_mmap"
#define ZERO 0
#define ONE 1   //Number of device numbers

//Functions Declarations for syscall definition
int myMmapOpen(struct inode *inode, struct file *filep);
int myMmapRelease(struct inode *in, struct file *fp);
int myMmap(struct file *filp, struct vm_area_struct *vma);

//Initialization routines
static int myInit(void);
static void myExit(void);

struct file_operations fops={
	.owner = THIS_MODULE,
	.open = myMmapOpen,
	.release = myMmapRelease,
	.mmap = myMmap
};

/*Global variables */
int majNo;
static dev_t mydev; //encodes major number and minor number
struct cdev *my_cdev; //holds character device driver descriptor
static char *kmalloc_ptr;
static char *kmalloc_area;

//class and device structures
static struct class *mychar_class;
static struct device *mychar_device;

/*
*myOpen:open function of the pseudo driver
*
*/
int myMmapOpen(struct inode *inode, struct file *filep)
{
	printk(KERN_INFO "open successful\n");
	return ZERO;
}

/*
*myRelease : class function of the pseudo driver
*
*/
int myMmapRelease(struct inode *in,struct file *fp)
{
	printk(KERN_INFO "File released\n");
	return ZERO;
}

int myMmap(struct file *filp, struct vm_area_struct *vma)
{
	unsigned long length;
	int ret;

	printk("mmap function being called...\n");
	
	length = vma->vm_end - vma->vm_start;

	/** Restrict to size of device memory */
	if (length > PAGE_SIZE)
		return -EIO;

	kmalloc_ptr = kmalloc(PAGE_SIZE, GFP_KERNEL);
	if(!kmalloc_ptr){
		printk(KERN_INFO "kmalloc() failed\n");
		myExit();
	}

	kmalloc_area = (char *) (((unsigned long) kmalloc_ptr + (PAGE_SIZE - ONE)) & PAGE_MASK); 
	memset(kmalloc_ptr, ZERO, PAGE_SIZE);
	
	ret = remap_pfn_range(vma, vma->vm_start, virt_to_phys ((void *) ((unsigned long) kmalloc_area)) >> PAGE_SHIFT, vma->vm_end - vma->vm_start, vma->vm_page_prot);
	if (ret){
		return -EAGAIN;
	}

	return ZERO;
}
static int __init myInit(void)
{
	int ret = -ENODEV;
	int status;
	printk(KERN_INFO "Initializing mmap driver\n");

	//Allocating device number
	status = alloc_chrdev_region(&mydev, ZERO, ONE, DEVNAME);
	if(status < ZERO)
	{
		printk(KERN_NOTICE "Device numbers allocation failed: %d\n",status);
		goto err;
	}
	printk(KERN_INFO "major number allocated :%d\n",MAJOR(mydev));
	
	cdev_init(my_cdev, &fops);
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
		printk(KERN_ERR "class_create failed");
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
	
	err:
		return ret;

}

/*
*myExit :cleanup function to the kernel module
*
*/

static void myExit(void)
{
	printk(KERN_INFO "exiting the mmap driver");

	if(kmalloc_ptr){
		kfree(kmalloc_ptr);
	}

	device_destroy(mychar_class, mydev);
	class_destroy(mychar_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, ONE);
	return ;
}

module_init (myInit);
module_exit(myExit);
