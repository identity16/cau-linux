#define BILLION 1000000000

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h> // for kmalloc
#include <linux/time.h>
#include "list.h"

void search_from_linked_list(int count);

unsigned long long calclock(struct timespec *spclock, unsigned long long *total_time, unsigned long long *total_count);

int __init linked_list_module_init(void) {
	search_from_linked_list(10000);
	search_from_linked_list(100000);
	search_from_linked_list(1000000);
	search_from_linked_list(10000000);
	search_from_linked_list(100000000);

	return 0;
}

void __exit linked_list_module_cleanup(void) {
	printk("Bye Module\n");
}

module_init(linked_list_module_init);
module_exit(linked_list_module_cleanup);
MODULE_LICENSE("GPL");

void search_from_linked_list(int count) {
	struct list_node *my_list = kmalloc(sizeof(struct list_node), GFP_KERNEL);
	struct list_node *tmp;
	struct list_node *current_node;
	int i;

	/* Variables for time calcualtion */
	struct timespec spclock[2];
	unsigned long long list_time;
	unsigned long long list_count;
	unsigned long long delay;	
	
	printk("==========[%d]=========\n", count);
	/* Initialize List */
	CAU_INIT_LIST_HEAD(my_list);

	
	/* add list element */
	getnstimeofday(&spclock[0]);

	for(i=0; i<count; i++) {
		struct list_node *new = kmalloc(sizeof(struct list_node), GFP_KERNEL);
		new->data = i;
		cau_list_add(new, my_list);
	}
	
	getnstimeofday(&spclock[1]);
    
    delay = calclock(spclock, &list_time, &list_count);
	printk("Add for %d times, delay: %llu\n", count, delay);
	
    
	/* Search number in list */
    getnstimeofday(&spclock[0]);
	
	cau_list_for_each_entry_safe(current_node, tmp, my_list) {
		if(current_node->data == 0) {
			printk("Traverse Done!");
            break;
		}
	}

	getnstimeofday(&spclock[1]);

	delay = calclock(spclock, &list_time, &list_count);
	printk("Search from %d entries, delay: %llu\n", count, delay);

	
	/* remove elements from list */
    getnstimeofday(&spclock[0]);
	
    cau_list_for_each_entry_safe(current_node, tmp, my_list) {
		cau_list_del(current_node);
		kfree(current_node);
	}

	getnstimeofday(&spclock[1]);

	delay = calclock(spclock, &list_time, &list_count);
	printk("Delete for %d times, delay: %llu\n", count, delay);
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
