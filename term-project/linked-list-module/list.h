#ifndef _CAU_LIST_H
#define _CAU_LIST_H

struct list_node {
	struct list_node *prev;
	struct list_node *next;
	int data;
};


static inline void CAU_INIT_LIST_HEAD(struct list_node *list) {
	list->next = list;
	list->prev = list;
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

static inline void cau_list_add(struct list_node *new, struct list_node *head) {
	__cau_list_add(new, head, head->next);
}

// Delete
static inline void __cau_list_del(struct list_node *prev, struct list_node *next)
{
	next->prev = prev;
	prev->next = next;
}

static inline void cau_list_del(struct list_node *entry)
{
	__cau_list_del(entry->prev, entry->next);
    
	entry->next = entry;
	entry->prev = entry;
}

// For Each
#define cau_list_for_each_entry_safe(pos, n, head)\
	for (pos = head->next, \
		n = pos->next;	\
        pos != head; \
        pos = n, n = n->next)

#endif