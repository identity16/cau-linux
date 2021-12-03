#define BILLION 1000000000

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h> // for kmalloc
#include <linux/time.h>
#include "list.h"

void add_to_linked_list(int count);
void remove_from_linked_list(int count);
void search_from_linked_list(int count, int num);

unsigned long long calclock(struct timespec *spclock, unsigned long long *total_time, unsigned long long *total_count);

int __init linked_list_module_init(void) {
	add_to_linked_list(1000);
	add_to_linked_list(10000);
	add_to_linked_list(100000);


	search_from_linked_list(1000, 749);
	search_from_linked_list(10000, 3711);
	search_from_linked_list(100000, 86032);

	remove_from_linked_list(1000);
	remove_from_linked_list(10000);
	remove_from_linked_list(100000);

	return 0;
}

void __exit linked_list_module_cleanup(void) {
	printk("Bye Module\n");
}

module_init(linked_list_module_init);
module_exit(linked_list_module_cleanup);
MODULE_LICENSE("GPL");

void add_to_linked_list(int count) {
	struct list_node *my_list = kmalloc(sizeof(struct list_node), GFP_KERNEL);
	int i;

	/* Variables for time calcualtion */
	struct timespec spclock[2];
	unsigned long long list_time;
	unsigned long long list_count;
	unsigned long long delay;	
	
	/* Initialize List */
	CAU_INIT_LIST_HEAD(my_list);

	getnstimeofday(&spclock[0]);
	
	/* add list element */
	for(i=0; i<count; i++) {
		struct list_node *new = kmalloc(sizeof(struct list_node), GFP_KERNEL);
		new->data = i;
		cau_list_add(new, my_list);
	}


	getnstimeofday(&spclock[1]);

	delay = calclock(spclock, &list_time, &list_count);
	printk("Add for %d times, delay: %llu\n", count, delay);

}

void search_from_linked_list(int count, int num) {
	struct list_node *my_list = kmalloc(sizeof(struct list_node), GFP_KERNEL);
	struct list_node *tmp;
	struct list_node *current_node;
	int i;

	/* Variables for time calcualtion */
	struct timespec spclock[2];
	unsigned long long list_time;
	unsigned long long list_count;
	unsigned long long delay;	
	
	/* Initialize List */
	CAU_INIT_LIST_HEAD(my_list);

	
	/* add list element */
	for(i=0; i<count; i++) {
		struct list_node *new = kmalloc(sizeof(struct list_node), GFP_KERNEL);
		new->data = i;
		cau_list_add(new, my_list);
	}
	
	getnstimeofday(&spclock[0]);
	
	/* Search number in list */
	cau_list_for_each_entry_safe(current_node, tmp, my_list) {
		if(current_node->data == num) {
			printk("found: %d\n", num);
            break;
		}
	}

	getnstimeofday(&spclock[1]);

	delay = calclock(spclock, &list_time, &list_count);
	printk("Search from %d entries, delay: %llu\n", count, delay);
}

void remove_from_linked_list(int count) {
    struct list_node *my_list = kmalloc(sizeof(struct list_node), GFP_KERNEL);
	struct list_node *tmp;
	struct list_node *current_node;
	int i;

	/* Variables for time calcualtion */
	struct timespec spclock[2];
	unsigned long long list_time;
	unsigned long long list_count;
	unsigned long long delay;	
	
	/* Initialize List */
	CAU_INIT_LIST_HEAD(my_list);

	
	/* add list element */
	for(i=0; i<count; i++) {
		struct list_node *new = kmalloc(sizeof(struct list_node), GFP_KERNEL);
		new->data = i;
		cau_list_add(new, my_list);
	}
	
	getnstimeofday(&spclock[0]);
	
	/* remove elements from list */
	cau_list_for_each_entry_safe(current_node, tmp, my_list) {
		cau_list_del(current_node, my_list);
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
