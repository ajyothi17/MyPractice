#include <linux/init.h>
#include <linux/module.h>

int simpleInit(void)
{
	printk(KERN_ALERT "in init function");

	return 0;
}

void simpleExit(void)
{
	printk(KERN_ALERT "in exit function");
}

module_init(simpleInit);
module_exit(simpleExit);
