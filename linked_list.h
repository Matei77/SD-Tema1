// Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "types.h"

doubly_linked_list_t *dll_create(unsigned int data_size);

void dll_add_nth_node(doubly_linked_list_t *list, unsigned int n,
					  const void *new_data);

dll_node_t *dll_remove_nth_node(doubly_linked_list_t *list, unsigned int n);

void dll_free(doubly_linked_list_t **pp_list);

dll_node_t *get_nth_node(doubly_linked_list_t *list, unsigned int n);

#endif  // LINKED_LIST_H_
