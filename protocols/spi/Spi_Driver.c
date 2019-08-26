/*****************************************************************************/
/*****************************************************************************/
/*                      Linux SPI Driver for ADC                             */
/*****************************************************************************/
/******************************************************************************

				   Interfacing ADC with Raspberry Pi
				Model  : Raspberry Pi 3 - B
				ADC    : MCP3202 (12bit, SPI Support)
		 		
				Author : Aditya Nandkumar Hambar
						 Software Engineer,
						 GlobalEdge Software Limited, Bangalore

				Date   : 7th March 2018

******************************************************************************/
/******************************************************************************

		This is a Linux SPI driver module for interfacing ADC MCP3202
		with Raspberry Pi Board. This program uses /drivers/spi/spi.c.
		This program reads the conversion value given by the ADC chip.

******************************************************************************/
/*****************************************************************************/


// Header includes
#include <linux/init.h>
#include <linux/module.h>
#include <linux/ioctl.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/list.h>
#include <linux/errno.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/compat.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/cdev.h>
#include <linux/spi/spi.h>
#include <linux/spi/spidev.h>
#include <linux/uaccess.h>
#include <linux/interrupt.h>

// Macros
#define MINOR_NO 10		// for minor number
#define NO_of_Dev 1		// for number of device

// License
MODULE_LICENSE("GPL");
MODULE_INFO(intree, "Y");

// Function declarations 
static int mySpiInit(void);
static void mySpiExit(void);
int mySpiOpen(struct inode *, struct file *);
int mySpiRelease(struct inode *, struct file *);
ssize_t mySpiRead(struct file *, char __user *, size_t, loff_t *);

// Global variables
char *devname = "SPI_ADC";		// Device name
int majNo;
static dev_t SpiDev;			// Encodes Major & Minor number
struct cdev *SpiCDev;			// Contains character device driver discriptor

// Class and Device structure pointers
static struct class *spichar_class;
static struct device *spichar_device;

// Device data structure
struct ADC_SPI{
    struct spi_device *spi;		// SPI Device pointer
    struct device *dev;			// Device pointer
    struct mutex lock;			// Mutex variable
};
static struct ADC_SPI *mydev;

// The probe() routine
static int ADC_SPI_probe(struct spi_device *spi)
{
	/* This function called at each device initialization */
    printk(KERN_INFO "Probe function called...\n:");
    mydev = kzalloc(sizeof *mydev, GFP_KERNEL);
    if (!mydev)
        return -ENOMEM;
    
    mydev->spi = spi;
    mydev->dev = &spi->dev;

    mutex_init(&mydev->lock);
	spi_set_drvdata(spi, mydev);

    return 0;
}

// Read Function for reading ADC data
ssize_t mySpiRead(struct file *fp, char __user *b, size_t count, loff_t *pos)
{
	unsigned char buf[3] = {0x00, 0x00, 0x00}; // Receiver Buffer
	unsigned char cmd[3] = {0x01, 0xA0, 0x00}; // Transmitter Buffer
	struct spi_device *spi = mydev->spi;
	// SPI transfer structure
	struct spi_transfer t = {
		.tx_buf = cmd,
		.rx_buf = buf,
		.len = 3,
        .bits_per_word = 8,
    };
	
	int status;
	int result = 0;
	char *ptr = (char*)&result;

	// Actual read procedure.
	struct spi_message  m; 			// SPI message structure
    spi_message_init(&m);			// Initialization of message
    spi_message_add_tail(&t, &m);	// Addition of message at the tail of list
    status = spi_sync(spi, &m);		// Sync the buffers

	if(status == 0){
		printk("Data received successfully\n");
		*ptr = buf[2];
		ptr++;
		*ptr = buf[1];
		result = result & 0x000FFF;

		status = copy_to_user((int *)buf, &result, sizeof(int));	
		if(status == 0){
			printk("Value copied to user space\n");
		}
		else{
			printk("Copying to user space failed\n");
		}
	}
	else{
		printk("Data received failed...\n");
	}
	return 0;
}

// Remove function for SPI driver module
static int ADC_SPI_remove(struct spi_device *spi)
{
    struct ADC_SPI *mydev = spi_get_drvdata(spi);
    kfree(mydev);
    return 0;
}

// Entry in id table
static const struct of_device_id ADC_SPI_id[] = {
	{.compatible = "ADC_SPI", },
	{}
};

MODULE_DEVICE_TABLE(of, ADC_SPI_id);

// SPI Driver structure
static struct spi_driver ADC_SPI_driver = {
	.driver = {
		.name   = "ADC_SPI",
		.owner  = THIS_MODULE,
		.of_match_table = of_match_ptr(ADC_SPI_id),
	},
	.probe  = ADC_SPI_probe,
	.remove = ADC_SPI_remove,	
};

// File operation structure for character device
struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = mySpiOpen,
	.release = mySpiRelease,
	.read = mySpiRead,
};

// Open function for device
int mySpiOpen(struct inode *inode, struct file *filep)
{
    printk(KERN_INFO "OPEN SUCCESSFULLY\n");
    return 0;
}

// Release function for device
int mySpiRelease(struct inode *in, struct file *fp)
{
    printk(KERN_INFO "FILE RELEASED\n");
    return 0;
}

// Initialization rotine for driver module
static int __init mySpiInit(void)
{
	int ret = -ENODEV;
	int status;

	printk(KERN_INFO "Initializing Device...\n");
	// Allocation Major & Minor number
	status = alloc_chrdev_region(&SpiDev, MINOR_NO, NO_of_Dev, devname);
	if(status < 0){
		printk(KERN_INFO "Device allocation failed...\n");
		goto err;
	}
	else
		printk(KERN_INFO "Major Number allocated = %d\n", MAJOR(SpiDev));
	// Allocating memory for charcter device
	SpiCDev = cdev_alloc();
	if(SpiCDev == NULL){
		printk(KERN_INFO "cdev_alloc failed...\n");
		goto err_cdev_alloc;
	}
	else {
		printk(KERN_ERR "cdev_alloc SUCSESS \n");
	}
	// Initialization of character device with file operation structure
	cdev_init(SpiCDev, &fops);
	SpiCDev -> owner = THIS_MODULE;
	// Adding character device to the list
	status = cdev_add(SpiCDev, SpiDev, NO_of_Dev);
	if(status < 0){
		printk(KERN_INFO "cdev_add failed...\n");
		goto err_cdev_add;
	}
	else {
		printk(KERN_ERR "cdev_add SUCSESS");
	}
	// Creating class and an entry in sysfs
	spichar_class = class_create(THIS_MODULE, devname);
	if(IS_ERR(spichar_class)){
		printk(KERN_INFO "class_create failed...\n");
		goto err_class_create;
	}
	else {
		printk(KERN_ERR "class_create() SUCSESS........\n");
	}
	// Creating device and device entry in /dev directory
	spichar_device = device_create(spichar_class, NULL, SpiDev, NULL, devname);
	if(IS_ERR(spichar_device)){
		printk(KERN_INFO "device_create failed...\n");
		goto err_device_create;
	}
	else {
		printk(KERN_ERR "device_create() SUCSESS");
	}
	// SPI Driver registration
	status = spi_register_driver(&ADC_SPI_driver);
	if(status < 0){
		printk(KERN_INFO "spi_register_driver failed...\n");
		goto err_spi_register_driver;
	}
	printk(KERN_INFO "Driver added successfully...\n");
	return 0;

// Error routines
err_spi_register_driver:
	device_destroy(spichar_class, SpiDev);

err_device_create:
	class_destroy(spichar_class);

err_class_create:
	cdev_del(SpiCDev);

err_cdev_add:
	kfree(SpiCDev);

err_cdev_alloc:
	unregister_chrdev_region(SpiDev, NO_of_Dev);

err:
	return ret;
}

// Wind up routine for driver module
static void __exit mySpiExit(void)
{
	printk(KERN_INFO "Exiting the Driver...\n");
	spi_unregister_driver(&ADC_SPI_driver);
	device_destroy(spichar_class, SpiDev);
	class_destroy(spichar_class);	
	cdev_del(SpiCDev);
	unregister_chrdev_region(SpiDev, NO_of_Dev);
}

// Module init and exit
module_init(mySpiInit);
module_exit(mySpiExit);

// License
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Aditya Hambar");


/*****************************************************************************/
/*                               END OF FILE                                 */
/*****************************************************************************/
