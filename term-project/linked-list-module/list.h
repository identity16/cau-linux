#ifndef _LIST_H
#define _LIST_H

struct list_node {
	struct list_node *prev;
	struct list_node *next;
	void *data;
};


static inline void INIT_LIST_HEAD(struct list_node *list) {
	list->next = list;
	list->prev = list;
}

// Add
static inline void __list_add(struct list_node *new,
			      struct list_node *prev,
			      struct list_node *next) {
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void list_add(struct list_node *new, struct list_node *head) {
	__list_add(new, head, head->next);
}

// Delete
static inline void __list_del(struct list_node *prev, struct list_node *next)
{
	next->prev = prev;
	prev->next = next;
}

static inline void list_del(struct list_node *entry)
{
	__list_del_entry(entry->prev, entry->next);
	entry->next = NULL;
	entry->prev = NULL;
}

// For Each
#define list_for_each_entry_safe(pos, n, head)\
	for (pos = head, \
		n = head->next;	\
        n != head; \
        pos = n, n = n->next)
