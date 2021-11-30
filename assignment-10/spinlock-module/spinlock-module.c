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

struct my_node *current_node, *prev_node;
struct list_head my_list;

unsigned long long calclock(struct timespec *spclock);

static int writer_function(void *data) {
    // INSERT
    while(counter < MAX_COUNT) {
        struct my_node *new = kmalloc(sizeof(struct my_node), GFP_KERNEL);

        spin_lock(&counter_lock);
        new->data = counter;
        list_add(&new->list, &my_list);

        if(counter == MAX_COUNT - 1) {
            getnstimeofday(&spclock[1]);

            delay = calclock(spclock);
            printk("spinlock linked list insert: %lluns\n", delay);
            getnstimeofday(&spclock[0]);

            current_node = list_first_entry(&my_list, struct my_node, list);
        }

        counter++;
    

        spin_unlock(&counter_lock);
    }

    // SEARCH
    int finding_num = 47182;

    while(counter < MAX_COUNT * 2) {
        spin_lock(&counter_lock);

        if(current_node->data == finding_num || counter == MAX_COUNT * 2 - 1) {
            getnstimeofday(&spclock[1]);

            delay = calclock(spclock);
            printk("spinlock linked list search: %lluns\n", delay);
            counter = MAX_COUNT * 2;

            current_node = list_first_entry(&my_list, struct my_node, list);
            
            getnstimeofday(&spclock[0]);
            spin_unlock(&counter_lock);
            break;
        } else {
            counter++;
        }

        current_node = list_next_entry(current_node, list);


        spin_unlock(&counter_lock);
    }

    // REMOVE
     while(counter < MAX_COUNT * 3) {
        spin_lock(&counter_lock);

        list_del(&current_node->list);
		kfree(current_node);

        if(counter == MAX_COUNT * 3 - 1) {
            getnstimeofday(&spclock[1]);

            delay = calclock(spclock);
            printk("spinlock linked list remove: %lluns\n", delay);
        }

        counter++;
        current_node = list_next_entry(current_node, list);

        spin_unlock(&counter_lock);
    }

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
