#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/slab.h>
#include <linux/delay.h>

#define TRUE    1
#define FALSE   0

int running = FALSE;
int grade = 0;

int test_thread(void *_arg) {
    int *arg = (int *)_arg;
    int i, thread_grade;
    
    while(!kthread_should_stop()) {
        // WAITING FOR NEXT GAME...
        while(!__sync_lock_test_and_set(&running, running));
        int sum = 0;

        for(i=0; i<10000; i++) {
            sum += i;
        }

        thread_grade = __sync_fetch_and_add(&grade, 1);
        
        printk("argument: %d, grade: %d\n", *arg, thread_grade);
        if(thread_grade == 4) {
            __sync_val_compare_and_swap(&thread_grade, 4, 0);
            __sync_lock_test_and_set(&running, FALSE);
        }
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