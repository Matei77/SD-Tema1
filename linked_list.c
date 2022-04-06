// Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
#include "linked_list.h"
#include "types.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function creates a linked list with a given data_size
doubly_linked_list_t *dll_create(unsigned int data_size)
{
	doubly_linked_list_t *list = malloc(sizeof(doubly_linked_list_t));
	if (!list) {
		printf("Memory allocation failed.\n");
		exit(-1);
	}

	list->head = NULL;
	list->tail = NULL;
	list->data_size = data_size;
	list->size = 0;

	return list;
}

// This function adds a node to a linked list, in the n position. If the n
// position is greater than the list size, it will add the element to the end
// of the list
void dll_add_nth_node(doubly_linked_list_t *list, unsigned int n,
					  const void *new_data)
{
	if (!list)
		return;

	if (n > list->size)
		n = list->size;

	dll_node_t *node = malloc(sizeof(dll_node_t));
	if (!node) {
		printf("Memory allocation failed.\n");
		exit(-1);
	}
	node->data = malloc(list->data_size);
	if (!node->data) {
		printf("Memory allocation failed.\n");
		exit(-1);
	}

	memcpy(node->data, new_data, list->data_size);

	if (n == 0) {
		if (!list->head) {
			node->next = NULL;
			node->prev = NULL;
			list->tail = node;
		} else {
			node->next = list->head;
			node->prev = NULL;
			list->head->prev = node;
		}
		list->head = node;
	} else if (n == list->size) {
		node->next = NULL;
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
	} else {
		dll_node_t *it = list->head;
		for (unsigned int i = 0; i < n - 1; i++, it = it->next) { }
		node->next = it->next;
		node->next->prev = node;
		node->prev = it;
		it->next = node;
	}

	list->size++;
}

// This function removes the node in the n position from the list. If the n
// position is greater than the list size, it will remove the last node
dll_node_t *dll_remove_nth_node(doubly_linked_list_t *list, unsigned int n)
{
	if (!list || !list->head)
		return NULL;

	if (n > list->size - 1)
		n = list->size - 1;

	dll_node_t *node;

	if (list->size == 1) {
		node = list->head;
		list->head = NULL;
		list->tail = NULL;
	} else if (n == 0) {
		node = list->head;
		list->head->next->prev = NULL;
		list->head = list->head->next;
	} else if (n == list->size - 1) {
		node = list->tail;
		list->tail->prev->next = NULL;
		list->tail = list->tail->prev;
	} else {
		dll_node_t *it = list->head;
		for (unsigned int i = 0; i < n - 1; i++, it = it->next) { }
		node = it->next;
		it->next->next->prev = it;
		it->next = it->next->next;
	}
	list->size--;

	return node;
}

// This function will free the memory allocated for a list
void dll_free(doubly_linked_list_t **pp_list)
{
	if (!(*pp_list))
		return;

	if (!(*pp_list)->head) {
		free(*pp_list);
		return;
	}

	dll_node_t *node = (*pp_list)->head;
	dll_node_t *next;

	while (node != NULL) {
		next = node->next;
		free(node->data);
		free(node);
		node = next;
	}

	free(*pp_list);
}

// This function will return the nth node from a list
dll_node_t *get_nth_node(doubly_linked_list_t *list, unsigned int n)
{
	dll_node_t *it = list->head;
	for (unsigned int i = 0; i < n; i++, it = it->next) { }

	return it;
}
