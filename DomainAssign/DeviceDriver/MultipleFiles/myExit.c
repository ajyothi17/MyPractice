#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

void simpleExit(void)
{
	printk(KERN_ALERT "in exit function\n");
}

module_exit(simpleExit);
