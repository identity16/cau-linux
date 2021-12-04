#ifndef _CAU_LIST_H
#define _CAU_LIST_H

#define CAPACITY 100000

#include <linux/slab.h> // for kmalloc

struct cau_list_head {
    struct list_node *start;
    int *data_arr;
    int size;
}

struct list_node {
	struct list_node *prev;
	struct list_node *next;
	int data_idx;
};


static inline void CAU_INIT_LIST_HEAD(struct cau_list_head *head) {
    struct list_node *start = kmalloc(sizeof(struct list_node), GFP_KERNEL);
	start->next = start;
	start->prev = start;

    head->size = 0;
    head->start = start;
    head->data_arr = kmalloc(sizeof(int) * CAPACITY, GFP_KERNEL);
}

// Add
static inline void __cau_list_add(struct list_node *new,
			      struct list_node *prev,
			      struct list_node *next) {
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void __cau_list_add_arr(struct list_node *new, int data, struct cau_list_head *head) {
    if(head->size >= CAPACITY && size % CAPACITY == 0) {
        head->data_arr = krealloc(head->data_arr, sizeof(int) * CAPACITY * (size / CAPACITY + 1), GFP_KERNEL);
    }

    head->data_arr[head->size] = data;
    new->data_idx = head->size;
}

static inline void cau_list_add(struct list_node *new, int data, struct list_node *current, struct cau_list_head *head) {
	__cau_list_add(new, current, current->next);
    __cau_list_add_arr(new, data, head);
    head->size++;
}

// Delete
static inline void __cau_list_del(struct list_node *prev, struct list_node *next)
{
	next->prev = prev;
	prev->next = next;
}

static inline void __cau_list_del_arr(struct list_node *entry, struct cau_list_head *head) {
    head->data_arr[entry->data_idx] = head->data_arr[head->size];
    entry->data_idx = -1;
    
    if(head->size > CAPACITY && size % CAPACITY == 1) {
        head->data_arr = krealloc(head->data_arr, sizeof(int) * CAPACITY * (size / CAPACITY + 1), GFP_KERNEL);
    }
}

static inline void cau_list_del(struct list_node *entry, struct cau_list_head *head)
{
	__cau_list_del(entry->prev, entry->next);
	__cau_list_del_arr(entry, head);
    
	entry->next = entry;
	entry->prev = entry;
    head->size--;
}

static inline int cau_list_get_data(struct list_node *entry, struct cau_list_head *head) {
    return head->data_arr[entry->data_idx];
}

// For Each
#define cau_list_for_each_entry(pos, n, data, head)\
	for (pos = head->start->next, \
		n = pos->next,  \
        data = cau_list_get_data(pos, head);	\
        pos != head->start;    \
        pos = n, n = n->next)

#define cau_list_for_each_data_unordered(idx, data, head)\
	for (idx = 0;  \
        idx < head->size;    \
        idx++)


#endif