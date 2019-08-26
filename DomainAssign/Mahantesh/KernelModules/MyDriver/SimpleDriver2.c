#include <linux/init.h>
#include <linux/module.h>

int myOpen1(struct inode *inode, struct file *filep);
int myRelease1(struct inode *in,struct file *fp);

int myFunction(void)
{
    printk(KERN_INFO "in %s function\n", __FUNCTION__);
	myOpen1(NULL, NULL);
	myRelease1(NULL, NULL);

    return 0;
}

int simpleInit2(void)
{
	printk(KERN_ALERT"in %s function\n", __FUNCTION__);
	
	myFunction();

	return 0;
}

void simpleExit2(void)
{
	printk(KERN_ALERT "in %s function\n", __FUNCTION__);
}

module_init(simpleInit2);
module_exit(simpleExit2);
