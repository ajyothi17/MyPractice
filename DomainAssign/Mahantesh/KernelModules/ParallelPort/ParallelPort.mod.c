#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x2501f820, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x242994f, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x2ab3cc9d, __VMLINUX_SYMBOL_STR(__release_region) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xf0e8833, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x1a5b9866, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x85e389b1, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x6da6cb75, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x44ef118a, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xdbedd6a2, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x9416e1d8, __VMLINUX_SYMBOL_STR(__request_region) },
	{ 0xc02c0b2a, __VMLINUX_SYMBOL_STR(ioport_resource) },
	{ 0xeae3dfd6, __VMLINUX_SYMBOL_STR(__const_udelay) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "24834790C80B11F08D6F3F7");
