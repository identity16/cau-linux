#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

int __init atomic_module_init(void) {
    printk("Hello Module!\n");

	return 0;
}

void __exit atomic_module_cleanup(void) {
	printk("Bye Module\n");
}

module_init(atomic_module_init);
module_exit(atomic_module_cleanup);
MODULE_LICENSE("GPL");