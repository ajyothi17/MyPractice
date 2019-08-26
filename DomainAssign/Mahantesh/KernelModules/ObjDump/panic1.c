/*  
 *  null-pointer.c - A not so simple kernel module to crash kernel.
 */

#include <linux/module.h>    /* Needed by all modules */
#include <linux/kernel.h>    /* Needed for KERN_INFO */
#include <linux/slab.h>    /* Needed for KERN_INFO */

char *p=NULL;

int init_module(void)
{
    printk(KERN_INFO "We is gonna KABOOM now!\n");
//    p=(char *) kmalloc(4,GFP_KERNEL);
    *p = 1; // movb (0x01) (%iEAX)
    return 0;
}

void cleanup_module(void)
{
    printk(KERN_INFO "Goodbye world.\n");
} 
