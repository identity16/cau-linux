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

#define BILLION 1000000000
#define MAX_COUNT 100000

int counter;
spinlock_t counter_lock;
struct timespec spclock[2];
struct task_struct *thread1, *thread2, *thread3, *thread4;
unsigned long long delay;

struct my_node {
	struct list_head list;
	int data;
};

struct list_head my_list;

unsigned long long calclock(struct timespec *spclock);

static int writer_function(void *data) {
    // INSERT
    while(counter < MAX_COUNT) {
        struct my_node *new = kmalloc(sizeof(struct my_node), GFP_KERNEL);

        spin_lock(&counter_lock);
        counter++;
        new->data = counter;
        list_add(&new->list, &my_list);

        if(counter == MAX_COUNT) {
            getnstimeofday(&spclock[1]);

            delay = calclock(spclock);
            printk("spinlock linked list insertion: %lluns\n", delay);
            getnstimeofday(&spclock[0]);
        }
        spin_unlock(&counter_lock);
    }

    __sync_val_compare_and_swap(&counter, MAX_COUNT, 0);

    // SEARCH
    int finding_num = 47182;
    struct my_node *current, *prev;
    prev = my_list;

    while(counter < MAX_COUNT) {
        spin_lock(&counter_lock);
        counter++;
        current = prev->list;
        prev = current;

        if(current->data == finding_num || counter == MAX_COUNT) {
            getnstimeofday(&spclock[1]);

            delay = calclock(spclock);
            printk("spinlock linked list search: %lluns\n", delay);
            counter = MAX_COUNT;

            getnstimeofday(&spclock[0]);
            spin_unlock(&counter_lock);
            break;
        }

        spin_unlock(&counter_lock);
    }

    __sync_val_compare_and_swap(&counter, MAX_COUNT, 0);

    do_exit(0);
}

static int __init spinlock_mod_init(void) {
    printk("%s, Entering module\n", __func__);
    
    counter = 0;
    
    INIT_LIST_HEAD(&my_list);

	getnstimeofday(&spclock[0]);
    spin_lock_init(&counter_lock);
    thread1 = kthread_run(writer_function, NULL, "writer_function");
    thread2 = kthread_run(writer_function, NULL, "writer_function");
    thread3 = kthread_run(writer_function, NULL, "writer_function");
    thread4 = kthread_run(writer_function, NULL, "writer_function");

    return 0;
}

static void __exit spinlock_mod_exit(void) {
    printk("%s, Exiting module\n", __func__);
}

module_init(spinlock_mod_init);
module_exit(spinlock_mod_exit);

MODULE_LICENSE("GPL");


unsigned long long calclock(struct timespec *spclock) {
	long temp, temp_n;
	unsigned long long timedelay = 0;

	if (spclock[1].tv_nsec >= spclock[0].tv_nsec) {
		temp = spclock[1].tv_sec - spclock[0].tv_sec;
		temp_n = spclock[1].tv_nsec - spclock[0].tv_nsec;
		timedelay = BILLION * temp + temp_n;
	} else {
		temp = spclock[1].tv_sec - spclock[0].tv_sec + 1;
		temp_n = BILLION + spclock[1].tv_nsec - spclock[0].tv_nsec;
		timedelay = BILLION * temp + temp_n;
	}

	return timedelay;
}
