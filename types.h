// Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
#ifndef TYPES_H
#define TYPES_H

#define SYMBOL_LEN 10

typedef struct dll_node_t {
	void *data;
	struct dll_node_t *prev, *next;
} dll_node_t;

typedef struct doubly_linked_list_t {
	dll_node_t *head, *tail;
	unsigned int data_size;
	unsigned int size;
} doubly_linked_list_t;

typedef struct card_t {
	int value;
	char symbol[SYMBOL_LEN];
} card_t;

#endif