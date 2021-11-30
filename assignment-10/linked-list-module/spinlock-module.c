#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>

int counter;
spinlock_t counter_lock;
struct task_struct *thread1, *thread2;

static int writer_function(void *data) {
    while(!kthread_should_stop()) {
        spin_lock(&counter_lock);
        counter++;
        printk("%s, counter: %d, pid: %u\n", __func__, counter, current->pid);
        spin_unlock(&counter_lock);
        msleep(500);
    }
    do_exit(0);
}

static int __init spinlock_mod_init(void) {
    printk("%s, Entering module\n", __func__);
    counter = 0;
    spin_lock_init(&counter_lock);
    thread1 = kthread_run(writer_function, NULL, "writer_function");
    thread2 = kthread_run(writer_function, NULL, "writer_function");

    return 0;
}

static void __exit spinlock_mod_exit(void) {
    kthread_stop(thread1);
    kthread_stop(thread2);
    printk("%s, Exiting module\n", __func__);
}

module_init(spinlock_mod_init);
module_exit(spinlock_mod_exit);

MODULE_LICENSE("GPL");