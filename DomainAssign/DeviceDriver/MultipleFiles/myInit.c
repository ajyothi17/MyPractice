#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

int simpleInit(void)
{
	printk(KERN_INFO "in init function\n");

	return 0;
}

module_init(simpleInit);
