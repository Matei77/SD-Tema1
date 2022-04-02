// Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
#include "commands.h"
#include "error_checks.h"
#include "linked_list.h"
#include "types.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This function adds a new deck to the list of decks
void AddDeck(doubly_linked_list_t *set_of_decks, unsigned int argc, char *argv[])
{
	if (argc != 1) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	char *endptr;
	long cards_nr = strtol(argv[0], &endptr, 10);
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	doubly_linked_list_t *deck = dll_create(sizeof(card_t));
	card_t card;

	int i = 0;
	while (i < cards_nr) {
		scanf("%d %9s", &card.value, card.symbol);

		if (CheckCard(card)) {
			dll_add_nth_node(deck, deck->size, &card);
			++i;
		} else
			printf("The provided card is not a valid one.\n");
	}

	dll_add_nth_node(set_of_decks, set_of_decks->size, deck);

	printf("The deck was successfully created with %ld cards.\n", cards_nr);
}

// This function deletes a deck from the list of decks
void DelDeck(doubly_linked_list_t *set_of_decks, unsigned int argc, char *argv[])
{
	if (argc != 1) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	char *endptr;
	unsigned long deck_index = strtoul(argv[0], &endptr, 10);
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}
	
	if (!CheckIndex(set_of_decks, (unsigned int)deck_index)) {
		printf("The prvided index is out of bounds for the deck list.\n");
		return;
	}
	dll_node_t *deck = dll_remove_nth_node(set_of_decks, deck_index);
	dll_free((doubly_linked_list_t**)(&deck->data));
	printf("The deck %ld was successfully deleted.\n", deck_index);
}
