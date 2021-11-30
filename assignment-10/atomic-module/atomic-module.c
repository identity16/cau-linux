#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/slab.h>
#include <linux/delay.h>

#define TRUE    1
#define FALSE   0

int grade = 0;
int runningThreads[4] = {1, 1, 1, 1};

int test_thread(void *_arg) {
    int *arg = (int *)_arg;
    
    int t_grade = __sync_fetch_and_add(&grade, 1);
    
    __sync_lock_test_and_set(&runningThreads[*arg], FALSE); 

    printk("I'm Alive!! %d, grade: %d\n", *arg, t_grade);

    __sync_val_compare_and_swap(&grade, 4, -1);

    if(grade == -1) {
	printk("All Threads are done!\n");
    }
    
    kfree(arg);
    return 0;
}

void thread_create(void) {
    int i;
    /* thread create */
    for(i=0; i<4; i++) {
        int *arg = (int *)kmalloc(sizeof(int), GFP_KERNEL);
        *arg = i;
        kthread_run(&test_thread, (void *)arg, "test_thread");
    }
}

int __init atomic_module_init(void) {
    thread_create();

    printk(KERN_EMERG "Hello Module!\n");
	return 0;
}

void __exit atomic_module_cleanup(void) {
	printk("Bye Module\n");
}

module_init(atomic_module_init);
module_exit(atomic_module_cleanup);
MODULE_LICENSE("GPL");
