#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

struct file_operations myFileOperations = {
	.owner = THIS_MODULE,
	.open = myOpen,
	.read = myRead,
	.write = myWrite,
	.release = myClose,
};

int major;

int myInit(void)
{
	printk(KERN_ALERT"in %s function\n", __FUNCTION__);

	printk(KERN_ALERT"registering char dev\n");

	major = register_chrdev(0, "Simple Char Driver", myFileOperations);

	if(major < 0){
		printk(KERN_ALERT"register char device driver failed\n");
	}

	printk(KERN_ALERT"Register char device success, Major num: %d\n", major);

	return 0;
}

void myExit(void)
{
	printk(KERN_ALERT"in %s function\n", __FUNCTION__);

	if(unregister_chrdev(major, "Simple Char Driver") < 0)
		printk(KERN_ALERT"error in unregister char dev\n");

	printk(KERN_ALERT"unregister char dev success\n");
}

module_init(myInit);
module_exit(myExit);
