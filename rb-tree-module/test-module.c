#define BILLION 1000000000
#define FALSE 0
#define TRUE 1

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/rbtree.h>
#include <linux/slab.h> // for kmalloc
#include <linux/time.h>

struct my_type {
    struct rb_node node;
    int key;
    int value;
};


struct my_type {
	struct rb_node node;
	int key;
	int value;
};

int rb_insert(struct rb_root *root, struct my_type *data);
struct my_type *rb_search(struct rb_root *root, int key);
int rb_delete(struct rb_root *mytree, int key);

void add_to_rb_tree(int count);
void remove_from_rb_tree(int count);
void search_from_rb_tree(int count, int num);

unsigned long long calclock(struct timespec *spclock, unsigned long long *total_time, unsigned long long *total_count);

int __init rb_tree_module_init(void) {
	add_to_rb_tree(1000);
	add_to_rb_tree(10000);
	add_to_rb_tree(100000);


	search_from_rb_tree(1000, 749);
	search_from_rb_tree(10000, 3711);
	search_from_rb_tree(100000, 86032);

	remove_from_rb_tree(1000);
	remove_from_rb_tree(10000);
	remove_from_rb_tree(100000);

	return 0;
}

void __exit rb_tree_module_cleanup(void) {
	printk("Bye Module\n");
}

module_init(rb_tree_module_init);
module_exit(rb_tree_module_cleanup);
MODULE_LICENSE("GPL");

int rb_insert(struct rb_root *root, struct my_type *data) {
	struct rb_node **new = &(root->rb_node), *parent = NULL;

	/* Figure out "where" to put new node */
	while(*new) {
		struct my_type *this = container_of(*new, struct my_type, node);
		parent = *new;
		if(this->key > data->key) {
			new = &((*new)->rb_left);
		} else if(this->key < data->key) {
			new = &((*new)->rb_right);
		} else {
			return FALSE;
		}
	}

	rb_link_node(&data->node, parent, new);
	rb_insert_color(&data->node, root);

	return TRUE;
}

struct my_type *rb_search(struct rb_root *root, int key) {
	struct rb_node *node = root->rb_node;

	while(node) {
		struct my_type *data = container_of(node, struct my_type, node);
		if(data->key > key) {
			node = node->rb_left;
		} else if(data->key < key) {
			node = node->rb_right;
		} else {
			return data;
		}
	}
	
	return NULL;
}

int rb_delete(struct rb_root *mytree, int key) {
	struct my_type *data = rb_search(mytree, key);

	if(data) {
		rb_erase(&data->node, mytree);
		kfree(data);

		return TRUE;
	}

	return FALSE;
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

void add_to_rb_tree(int count) {
	struct rb_root my_tree = RB_ROOT;
	int i;

	/* Variables for time calcualtion */
	struct timespec spclock[2];
	unsigned long long tree_time;
	unsigned long long tree_count;
	unsigned long long delay;
	
	getnstimeofday(&spclock[0]);
	
	/* add node */
	for(i=0; i<count; i++) {
		struct my_type *new = kmalloc(sizeof(struct my_type), GFP_KERNEL);
		new->value = i * 2;
		new->key = i;

		rb_insert(&my_tree, new);
	}


	getnstimeofday(&spclock[1]);

	delay = calclock(spclock, &tree_time, &tree_count);
	printk("Add for %d times, delay: %llu\n", count, delay);

}

void search_from_rb_tree(int count, int num) {
	struct rb_root my_tree;
	int i;

	/* Variables for time calcualtion */
	struct timespec spclock[2];
	unsigned long long tree_time;
	unsigned long long tree_count;
	unsigned long long delay;	
	
	struct my_type *find_node = rb_search(&my_tree, num);
	
	/* add node */
	for(i=0; i<count; i++) {
		struct my_type *new = kmalloc(sizeof(struct my_type), GFP_KERNEL);
		new->value = i * 2;
		new->key = i;
		rb_insert(&my_tree, new);
	}
	
	
	getnstimeofday(&spclock[0]);
	
	/* Search number in tree */
	if(!find_node) {
		printk("not found\n");
	} else {
		printk("found: %d\n", find_node->key);
	}

	getnstimeofday(&spclock[1]);

	delay = calclock(spclock, &tree_time, &tree_count);
	printk("Search from %d entries, delay: %llu\n", count, delay);
}

void remove_from_rb_tree(int count) {
	struct rb_root my_tree;
	int i;

	/* Variables for time calcualtion */
	struct timespec spclock[2];
	unsigned long long tree_time;
	unsigned long long tree_count;
	unsigned long long delay;	
	

	/* add node */
	for(i=0; i<count; i++) {
		struct my_type *new = kmalloc(sizeof(struct my_type), GFP_KERNEL);
		new->value = i * 2;
		new->key = i;
		rb_insert(&my_tree, new);
	}
		
	getnstimeofday(&spclock[0]);
	
	/* remove elements from tree */
	for(i=0; i<count; i++) {
		rb_delete(&my_tree, i);
	}

	getnstimeofday(&spclock[1]);

	delay = calclock(spclock, &tree_time, &tree_count);
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
