#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/list.h>
#include <linux/time.h>

int counter;
spinlock_t counter_lock;
struct task_struct *thread1, *thread2;

struct my_node {
	struct list_head list;
	int data;
};

struct list_head my_list;

static int writer_function(void *data) {
    while(counter < 100000) {
        struct my_node *new = kmalloc(sizeof(struct my_node), GFP_KERNEL);

        spin_lock(&counter_lock);
        counter++;
        new->data = counter;
        list_add(&new->list, &my_list);

        printk("%s, counter: %d, pid: %u\n", __func__, counter, current->pid);
        spin_unlock(&counter_lock);

        msleep(500);
    }
    do_exit(0);
}

static int __init spinlock_mod_init(void) {
    printk("%s, Entering module\n", __func__);
    
    counter = 0;
    
    INIT_LIST_HEAD(&my_list);

    spin_lock_init(&counter_lock);
    thread1 = kthread_run(writer_function, NULL, "writer_function");
    thread2 = kthread_run(writer_function, NULL, "writer_function");

    return 0;
}

static void __exit spinlock_mod_exit(void) {
    // kthread_stop(thread1);
    // kthread_stop(thread2);
    printk("%s, Exiting module\n", __func__);
}

module_init(spinlock_mod_init);
module_exit(spinlock_mod_exit);

MODULE_LICENSE("GPL");