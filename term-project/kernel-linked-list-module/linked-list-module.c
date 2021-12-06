#define BILLION 1000000000

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/slab.h> // for kmalloc
#include <linux/ktime.h>
#include <linux/timekeeping.h>


struct my_node {
	struct list_head list;
	int data;
};

void test_linked_list(int count);

unsigned long long calclock(struct timespec64 *spclock, unsigned long long *total_time, unsigned long long *total_count);

int __init linked_list_module_init(void) {
    printk("[KERNEL Linked List]\n");
	test_linked_list(1000);
	test_linked_list(10000);
	test_linked_list(100000);
	test_linked_list(1000000);

	return 0;
}

void __exit linked_list_module_cleanup(void) {
	printk("Bye Module\n");
}

module_init(linked_list_module_init);
module_exit(linked_list_module_cleanup);
MODULE_LICENSE("GPL");

void add_to_linked_list(int count) {
	struct list_head my_list;
	int i;

	/* Variables for time calcualtion */
	struct timespec64 spclock[2];
	unsigned long long list_time;
	unsigned long long list_count;
	unsigned long long delay;	
	
	/* Initialize List */
	INIT_LIST_HEAD(&my_list);

	ktime_get_real_ts64(&spclock[0]);
	
	/* add list element */
	for(i=0; i<count; i++) {
		struct my_node *new = kmalloc(sizeof(struct my_node), GFP_KERNEL);
		new->data = i;
		list_add(&new->list, &my_list);
	}


	ktime_get_real_ts64(&spclock[1]);

	delay = calclock(spclock, &list_time, &list_count);
	printk("Add for %d times, delay: %llu\n", count, delay);

}

void test_linked_list(int count) {
	struct list_head my_list;
	struct my_node *tmp;
	struct my_node *current_node;
	int i;
    long sum;

	/* Variables for time calcualtion */
	struct timespec64 spclock[2];
	unsigned long long list_time;
	unsigned long long list_count;
	unsigned long long delay;	

	printk("==========[%d]=========\n", count);
	/* Initialize List */
	INIT_LIST_HEAD(&my_list);

	
	/* add list element */
    ktime_get_real_ts64(&spclock[0]);

	for(i=0; i<count; i++) {
		struct my_node *new = kmalloc(sizeof(struct my_node), GFP_KERNEL);
		new->data = i;
		list_add(&new->list, &my_list);
	}
    ktime_get_real_ts64(&spclock[1]);
	delay = calclock(spclock, &list_time, &list_count);
	printk("Add for %d times, delay: %llu\n", count, delay);

	
	/* Search number in list */
    sum = 0;
	ktime_get_real_ts64(&spclock[0]);

	list_for_each_entry_safe(current_node, tmp, &my_list, list) {
        sum += current_node->data;
	}

	ktime_get_real_ts64(&spclock[1]);

	delay = calclock(spclock, &list_time, &list_count);
	printk("Traverse %d entries, sum: %ld, delay: %llu\n", count, sum, delay);

	
	/* remove elements from list */
    ktime_get_real_ts64(&spclock[0]);

	list_for_each_entry_safe(current_node, tmp, &my_list, list) {
		list_del(&current_node->list);
		kfree(current_node);
	}

	ktime_get_real_ts64(&spclock[1]);

	delay = calclock(spclock, &list_time, &list_count);
	printk("Delete for %d times, delay: %llu\n", count, delay);
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
