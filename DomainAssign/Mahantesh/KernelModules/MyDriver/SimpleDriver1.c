#include <linux/init.h>
#include <linux/module.h>

int myOpen1(struct inode *inode, struct file *filep)
{
    printk(KERN_INFO "in %s function\n", __FUNCTION__);

    return 0;
}

int myRelease1(struct inode *in,struct file *fp)
{
	printk(KERN_ALERT"in %s function\n", __FUNCTION__);
    
	return 0;
}

int simpleInit1(void)
{
	printk(KERN_ALERT"in %s function\n", __FUNCTION__);
	
//	myOpen(NULL, NULL);

	return 0;
}

void simpleExit1(void)
{
	printk(KERN_ALERT "in %s function\n", __FUNCTION__);
}

module_init(simpleInit1);
module_exit(simpleExit1);
EXPORT_SYMBOL(myOpen1);
EXPORT_SYMBOL(myRelease1);
