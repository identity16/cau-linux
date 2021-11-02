#include <linux/kernel.h>

asmlinkage long sys_mycall(void) {
	printk("System Call Made By Wonjun Shin\n");

	return 20170223;
}
