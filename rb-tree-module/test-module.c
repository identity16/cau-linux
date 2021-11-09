#define BILLION 1000000000
#define FALSE 0
#define TRUE 1

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/rbtree.h>
#include <linux/slab.h> // for kmalloc
#include <linux/time.h>

struct my_type {
    struct rb_node node;
    int key;
    int value;
};

int __init rb_tree_module_init(void) {
	printk("Hello, Module\n");

	return 0;
}

void __exit rb_tree_module_cleanup(void) {
	printk("Bye Module\n");
}

module_init(rb_tree_module_init);
module_exit(rb_tree_module_cleanup);
MODULE_LICENSE("GPL");
