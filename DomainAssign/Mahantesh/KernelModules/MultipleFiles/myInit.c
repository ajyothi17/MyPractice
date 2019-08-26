#include <linux/init.h>
#include <linux/module.h>

int simpleInit(void)
{
	printk(KERN_ALERT"in %s function\n", __FUNCTION__);

	return 0;
}

/*
void simpleExit(void)
{
	printk(KERN_ALERT "in %s function\n", __FUNCTION__);
}
*/
module_init(simpleInit);
//module_exit(simpleExit);
