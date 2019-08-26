#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/bcd.h>
//#include <linux/bin.h>
#include <asm/current.h>
#include <asm/highmem.h>
#include <linux/compiler.h>
#include <linux/errno.h>
#include <linux/export.h>
#include <linux/syscalls.h>
//#include <asm/cpufeature.h>



#include <linux/kernel.h>
#include <linux/mm_types.h>
#include <linux/mm.h>
#include <asm/page.h>
#include <linux/path.h>

#include <linux/i2c.h>

static int mpu_probe(struct i2c_client *client, const struct i2c_device_id *id);
int myopen(struct inode *inode, struct file *filep);
int myrelease(struct inode *in, struct file *fp);
static ssize_t myread(struct file *file_ptr, char __user *buff, size_t count, loff_t *pos);

unsigned int bin2dec(unsigned int bin_val)
{
    unsigned int temp = bin_val;
    unsigned int dec_val = 0;
    int base = 1;
    int rem;

    while(temp > 0){
        rem = temp % 10;
        dec_val = dec_val + (rem * base);
        temp = temp / 10;
        base = base * 2;
    }

    return dec_val;
}

MODULE_LICENSE("Dual BSD/GPL");

static dev_t my_dev;
struct cdev *my_cdev;
static struct class *mychar_class;
static struct device *mychar_device;

struct file_operations fops={
    .owner = THIS_MODULE,
	.open = myopen,
	.read = myread,
	.release = myrelease,
};

static const struct i2c_device_id mpu_ids[] = {
	{ "mpu6050", 0 },
	{ }
};

MODULE_DEVICE_TABLE(i2c, mpu_ids);

static struct i2c_driver mpu_i2c_driver = {
    .driver = {
        .name   = "mpu6050",
        .owner  = THIS_MODULE,
    },
    .probe      = mpu_probe,
//    .remove     = mpu_remove,
    .id_table   = mpu_ids,
};

struct my_i2c{
	struct i2c_client *client;
	unsigned int addr;
	unsigned int buf[8];
}my_i2c;

int myopen(struct inode *inode, struct file *filep)
{
    printk(KERN_INFO "Device opened successfully\n");

    return 0;
}

int myrelease(struct inode *in, struct file *fp)
{
    printk(KERN_INFO "File realeased \n");

    return 0;
}

static ssize_t myread(struct file *file_ptr, char __user *buf, size_t count, loff_t *pos)
{
/*
	// Setting the ACCEL_CONFIG
	int ret;
	unsigned char offset = 0x1c;

	my_msg[0].addr = my_i2c.addr;
	my_msg[0].flags = 0;
	my_msg[0].buf = &offset;
	my_msg[0].len = 1;

	ret = i2c_transfer((my_i2c.client)->adapter, my_msg, 1);
	if(ret < 0)
	{
		printk(KERN_ERR "i2c_master_transfer failed\n");
	}
*/

	// Test Case for MPU-6050
	unsigned char read_buf[10];
	unsigned int res[20];
	struct i2c_msg my_msg[2];
	unsigned char offset =  0x0D;
	int ret;

	printk(KERN_INFO "Reading the device\n");
	my_msg[0].addr = my_i2c.addr;
	my_msg[0].flags = 0;
	my_msg[0].buf = &offset;
	my_msg[0].len = 1;

		
	my_msg[1].addr = my_i2c.addr;
	my_msg[1].flags = I2C_M_RD;
	my_msg[1].buf = read_buf;
	my_msg[1].len = 3;
	

	ret = i2c_transfer((my_i2c.client)->adapter, my_msg, 2);
	if(ret < 0)
	{
		printk(KERN_ERR "i2c_master_transfer failed \n");
	}


	printk("-----------------------------------------------\n");
	printk("Test Case for MPU-6050\n");


	res[0] = bin2dec(read_buf[0] & 0x1f);
	res[1] = read_buf[1] & 0x1f;
	res[2] = read_buf[2] & 0x1f;

	printk("------------------------------------------------\n");
	printk(KERN_INFO "Gyrometer reading on X-axis = %d\n", res[0]);
	printk(KERN_INFO "Gyrometer reading on X-axis = %d\n", res[1]);
	printk(KERN_INFO "Gyrometer reading on X-axis = %d\n", res[2]);

	res[3] = (read_buf[0] & 0xE0) >> 5;
	res[4] = (read_buf[1] & 0xE0) >> 5;
	res[5] = (read_buf[2] & 0xE0) >> 5;

	printk("-----------------------------------------------\n");
	printk(KERN_INFO "Accleration reading on X-axis = %d\n", res[3]);
	printk(KERN_INFO "Accleration reading on X-axis = %d\n", res[4]);
	printk(KERN_INFO "Accleration reading on X-axis = %d\n", res[5]);
	
	if(copy_to_user(buf, res, 6))
		printk(KERN_INFO "Copy to user failed\n");
	else	
		printk(KERN_INFO "Copy to user success\n");	


	//Actual reading of the MPU-6050
	printk("\n\n******************************************\n");
	printk(KERN_INFO "Actual reading of MPU-6050\n");
	
	offset = 0x3B;	

	my_msg[0].addr = my_i2c.addr;
	my_msg[0].flags = 0;
	my_msg[0].buf = &offset;
	my_msg[0].len = 1;

	my_msg[1].addr = my_i2c.addr;
	my_msg[1].flags =  I2C_M_RD;
	my_msg[1].buf = read_buf;
	my_msg[1].len = 6;

	
	ret = i2c_transfer((my_i2c.client)->adapter, my_msg, 2);
	if(ret < 0)
	{
		printk(KERN_ERR "i2c_master_receive failed\n");
	}

	res[0] = read_buf[0];
	res[1] = read_buf[1];
	res[0] = (res[0] << 8) | res[1];
	res[2] = read_buf[2];
	res[3] = read_buf[3];
	res[1] = (res[2] << 8) | res[3];
	res[4] = read_buf[4];
	res[5] = read_buf[5];
	res[3] = (res[4] << 8) | res[5];
	
	printk("------------------------------------------\n");
	printk("-----------Acceloremeter reading-----------\n");
	printk("X = %d\t Y = %d\t Z = %d\t", res[0], res[1], res[2]);

	
	offset = 0x43;


	my_msg[0].addr = my_i2c.addr;
	my_msg[0].flags = 0;
	my_msg[0].buf = &offset;
	my_msg[0].len = 1;

	my_msg[1].addr = my_i2c.addr;
	my_msg[1].flags = I2C_M_RD;
	my_msg[1].buf = read_buf;
	my_msg[1].len = 6;
	

	ret = i2c_transfer((my_i2c.client)->adapter, my_msg, 2);
	if(ret < 0)
	{
		printk(KERN_ERR "i2c_master_receive failed\n");
	}
	

	res[6] = read_buf[0] & 0xff;
	res[7] = read_buf[1] & 0xff;
	res[6] = (res[6] << 8) | res[7];
	res[8] = read_buf[0] & 0xff;
	res[9] = read_buf[0] & 0xff;
	res[7] = (res[8] << 8) | res[9];
	res[10] = read_buf[1] && 0xff;
	res[11] = read_buf[1] && 0xff;
	res[8] = (res[10] << 8) | res[11];
	
	printk("-------------------------------------------\n");
	printk("-----------Gyrometer reading---------------\n");
	printk("X = %d\t Y = %d\t Z = %d\t", res[6], res[7], res[8]);


	return 0;
}

	
	
/*

ssize_t mywrite(struct file *fp, const char __user *buf, size_t count, loof_t *f_pos)
{
	struct i2c_msg my_msg;
	unsigned char offset = 0x00;
	int ret;

	printk(KERN_INFO "Writing into the device\n");
	my_msg.addr = my_i2c.addr;
	my_msg.flags = 0;
	my_msg.buf = &offset;
	my_msg.len = 1;


	ret = i2c_master_send(client, my_msg, 1);
	if( ret < 0)
	{
		printk(KERN_ERR "i2c_master_send receive\n");
	}

	return 0;
}
*/

static int __init my_init(void)
{
	int status;

	status = i2c_add_driver(&mpu_i2c_driver);

	if(status){
		printk(KERN_INFO "driver not added\n");
		return status;
	}	

	printk(KERN_INFO "driver added\n");

	return 0;	
}


static int mpu_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	int status;

	printk(KERN_INFO "detecting device\n");

	status = alloc_chrdev_region(&my_dev, 0, 1, "mpu6050");
	if(status < 0)
	{	
		printk(KERN_NOTICE "Device number allocation failed: %d\n", status);
		goto err;
	}

	cdev_init(my_cdev, &fops);
    my_cdev->owner = THIS_MODULE;

    status = cdev_add(my_cdev, my_dev, 1);
    if(status)
    {
        printk(KERN_ERR "cdev_add failed");
		goto err_cdev_add;
	}

    //create class and entry in sysfs

    mychar_class = class_create( THIS_MODULE, "mpu6050");
    if(IS_ERR(mychar_class))
    {
        printk(KERN_ERR "class_crete failed");
        goto err_class_create;
    }

    //create mychar_device in sysfs and add entry in /dev

    mychar_device = device_create(mychar_class, NULL, my_dev, NULL, "mpu6050");
    if(IS_ERR(mychar_device))
    {
        printk(KERN_ERR "device_create failed");
        goto err_device_create;
    }

	status = i2c_check_functionality(client->adapter, I2C_FUNC_I2C);

	if(!status)
	{
		printk(KERN_ALERT "Required I2C functionality not supported\n");
		return -ENODEV;
	}	

	printk(KERN_ALERT "Required I2C functionality done\n");

    return 0;

    err_device_create:
        class_destroy(mychar_class);

    err_class_create:
        cdev_del(my_cdev);

    err_cdev_add:
        kfree(my_cdev);

    err:
        return status;	
}

static void __exit my_exit(void)
{
	printk(KERN_INFO "exiting device\n");
	device_destroy(mychar_class, my_dev);
	cdev_del(my_cdev);
	unregister_chrdev_region(my_dev, 1);

	return ;
}

module_init(my_init);
module_exit(my_exit);
