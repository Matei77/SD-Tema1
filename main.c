// Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers.h"

#define LEN 21

int main(void)
{
	char command[LEN];
	doubly_linked_list_t *set_of_decks;
	set_of_decks = dll_create(sizeof(doubly_linked_list_t));

	while (1) {
		scanf(" %20s", command);

		if (strcmp(command, "ADD_DECK") == 0) {
			AddDeck(set_of_decks);
		} else if (strcmp(command, "DEL_DECK") == 0) {
			DelDeck(set_of_decks);
		}
	}
	return 0;
}