#define BILLION 1000000000

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/slab.h> // for kmalloc
#include <linux/time.h>
#include <linux/spinlock.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>

#define INSERT 0
#define SEARCH 1
#define DELETE 2

struct my_node {
	struct list_head list;
	int data;
};

int thread_done = 0;
int list_num = 1;

unsigned long long delay[3] = {0,};

spinlock_t list_lock;
struct task_struct *thread1, *thread2, *thread3, *thread4;

void insert_linked_list(struct list_head *ptr_head);
void perform_linked_list();

unsigned long long calclock(struct timespec *spclock, unsigned long long *total_time, unsigned long long *total_count);

int __init spinlock_module_init(void) {
    printk("===== Spinlock =====\n");
    spin_lock_init(&list_lock);

	perform_linked_list();
	return 0;
}

void __exit spinlock_module_cleanup(void) {
	printk("Bye Module\n");
}

module_init(spinlock_module_init);
module_exit(spinlock_module_cleanup);
MODULE_LICENSE("GPL");

void insert_linked_list(struct list_head *ptr_head) {
    while(TRUE) {
        spin_lock(&list_lock);
        if(list_num <= 100000) {
            struct my_node *new = kmalloc(sizeof(struct my_node), GFP_KERNEL);
            new->data = i;
            list_add(&new->list, ptr_head);
            list_num += 1;
            spin_unlock(&list_lock);
        } else {
            spin_unlock(&list_lock);
            break;
        }
	}

    __sync_fetch_and_add(&thread_done, 1);
}


void perform_linked_list() {
	struct list_head my_list;
	struct my_node *tmp;
	struct my_node *current_node;
	int i;

	/* Variables for time calcualtion */
	struct timespec spclock[2];
	unsigned long long list_time;
	unsigned long long list_count;
	
	/* Initialize List */
	INIT_LIST_HEAD(&my_list);

	
	/* add list element */
    getnstimeofday(&spclock[0]);
    thread1 = kthread_run(insert_linked_list, &my_list, "insert_linked_list");
    thread2 = kthread_run(insert_linked_list, &my_list, "insert_linked_list");
    thread3 = kthread_run(insert_linked_list, &my_list, "insert_linked_list");
    thread4 = kthread_run(insert_linked_list, &my_list, "insert_linked_list");

    while(thread_done < 4);
    getnstimeofday(&spclock[1]);
    kthread_stop(thread1);
    kthread_stop(thread2);
    kthread_stop(thread3);
    kthread_stop(thread4);

    thread_done = 0;
    list_num = 1;

	delay[INSERT] = calclock(spclock, &list_time, &list_count);
    printk("linked list insert time: %lluns\n", delay[INSERT])
}


unsigned long long calclock(struct timespec *spclock, unsigned long long *total_time, unsigned long long *total_count) {
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

	__sync_fetch_and_add(total_time, timedelay);
	__sync_fetch_and_add(total_count, 1);
	return timedelay;
}
