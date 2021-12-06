#define BILLION 1000000000

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h> // for kmalloc
#include <linux/ktime.h>
#include <linux/timekeeping.h>
#include "list.h"

void test_linked_list(int count);

unsigned long long calclock(struct timespec64 *spclock, unsigned long long *total_time, unsigned long long *total_count);

int __init cau_linked_list_module_init(void) {
    printk("[CUSTOM Linked List]\n");
	test_linked_list(1000);
	test_linked_list(10000);
	test_linked_list(100000);
	test_linked_list(1000000);

	return 0;
}

void __exit cau_linked_list_module_cleanup(void) {
	printk("Bye Module\n");
}

module_init(cau_linked_list_module_init);
module_exit(cau_linked_list_module_cleanup);
MODULE_LICENSE("GPL");

void test_linked_list(int count) {
	struct cau_list_head *my_list = kmalloc(sizeof(struct cau_list_head), GFP_KERNEL);
	struct cau_list_node *tmp;
	struct cau_list_node *current_node;
	int i, data;
    long sum;

	/* Variables for time calcualtion */
	struct timespec64 spclock[2];
	unsigned long long list_time;
	unsigned long long list_count;
	unsigned long long delay;
	
	printk("==========[%d]=========\n", count);
	/* Initialize List */
	CAU_INIT_LIST_HEAD(my_list);

	
	/* add list element */
	ktime_get_real_ts64(&spclock[0]);

	for(i=0; i<count; i++) {
		struct cau_list_node *new = kmalloc(sizeof(struct cau_list_node), GFP_KERNEL);
		cau_list_add(new, i, my_list->start, my_list);
	}
	
	ktime_get_real_ts64(&spclock[1]);
    
    delay = calclock(spclock, &list_time, &list_count);
	printk("Add for %d times, delay: %llu\n", count, delay);
	
    
	/* Search number in list */
    ktime_get_real_ts64(&spclock[0]);

    sum = 0;
	cau_list_for_each_entry_ordered(current_node, tmp, my_list) {
        data = cau_list_get_data(current_node, my_list);
        sum += data;
	}

	ktime_get_real_ts64(&spclock[1]);

	delay = calclock(spclock, &list_time, &list_count);
	printk("Traverse(ordered) %d entries, sum: %ld, delay: %llu\n", count, sum, delay);
	
    /* Search number in list */
    ktime_get_real_ts64(&spclock[0]);
	
    sum = 0;
	cau_list_for_each_data_unordered(i, my_list) {
        data = my_list->data_arr[i];
        sum += data;
	}

	ktime_get_real_ts64(&spclock[1]);

	delay = calclock(spclock, &list_time, &list_count);
	printk("Traverse(unordered) %d entries, sum: %ld, delay: %llu\n", count, sum, delay);

	
	/* remove elements from list */
    ktime_get_real_ts64(&spclock[0]);
	
    cau_list_for_each_entry_ordered(current_node, tmp, my_list) {
		cau_list_del(current_node, my_list);
		kfree(current_node);
	}

	ktime_get_real_ts64(&spclock[1]);

	delay = calclock(spclock, &list_time, &list_count);
	printk("Delete for %d times, delay: %llu\n", count, delay);

    CAU_FREE_LIST_HEAD(my_list);
}


unsigned long long calclock(struct timespec64 *spclock, unsigned long long *total_time, unsigned long long *total_count) {
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
