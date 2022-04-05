// Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
#include "utils.h"
#include "linked_list.h"
#include "types.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int CompareCards(card_t *card1, card_t *card2);


// This function returns 1 if a card is valid and 0 otherwise
int CheckCard(card_t card)
{
	if (card.value < 1 || card.value > 14)
		return 0;

	if (strcmp(card.symbol, "HEART") != 0 &&
		strcmp(card.symbol, "SPADE") != 0 &&
		strcmp(card.symbol, "DIAMOND") != 0 && strcmp(card.symbol, "CLUB") != 0)
		return 0;

	return 1;
}

// This function return 1 if an index is valid and 0 otherwise
int CheckIndex(doubly_linked_list_t *list, unsigned int deck_index)
{
	if (list->size > deck_index)
		return 1;
	return 0;
}

// This function creates a new deck with a number of <cards_nr> cards that will
// be provided by the user via stdin
void AddDeck(doubly_linked_list_t *set_of_decks, int cards_nr)
{
	doubly_linked_list_t *deck = dll_create(sizeof(card_t));
	card_t card;

	int i = 0;
	while (i < cards_nr) {
		char card_line[CARD_LEN];
		char *value = NULL, *symbol = NULL;

		fgets(card_line, CARD_LEN - 1, stdin);

		char *token = strtok(card_line, " \n");
		value = token;

		if (token != NULL) {
			token = strtok(NULL, " \n");
			symbol = token;
		}

		if (value != NULL && symbol != NULL) {
			strncpy(card.symbol, symbol, SYMBOL_LEN - 1);
			char *endptr;
			card.value = strtol(value, &endptr, 10);
			if (value != endptr && *endptr == '\0') {
				if (CheckCard(card)) {
					dll_add_nth_node(deck, deck->size, &card);
					++i;
				} else
					printf("The provided card is not a valid one.\n");
			} else
				printf("The provided card is not a valid one.\n");
		}
	}

	dll_add_nth_node(set_of_decks, set_of_decks->size, deck);
	free(deck);
}

// This function deletes the deck at position <deck_index> from the list of
// decks and frees the memory allocated for it
void DelDeck(doubly_linked_list_t *set_of_decks, unsigned int deck_index)
{
	dll_node_t *deck = dll_remove_nth_node(set_of_decks, deck_index);
	doubly_linked_list_t *current_deck = (doubly_linked_list_t *)(deck->data);
	dll_free(&current_deck);
	free(deck);
}

void SplitDeck(doubly_linked_list_t *set_of_decks, doubly_linked_list_t *deck,
			   unsigned int deck_index, unsigned int split_index)
{
	doubly_linked_list_t *new_deck = dll_create(sizeof(card_t));
	dll_node_t *card_it = deck->head;
	for (unsigned int i = 0; i < split_index; i++, card_it = card_it->next)
		;
	while (card_it) {
		dll_add_nth_node(new_deck, new_deck->size, card_it->data);
		card_it = card_it->next;
	}
	while (deck->size > split_index) {
		dll_node_t *card = dll_remove_nth_node(deck, split_index);
		free(card->data);
		free(card);
	}

	dll_add_nth_node(set_of_decks, deck_index + 1, new_deck);
	free(new_deck);
}

void ShowDeck(doubly_linked_list_t *deck, unsigned int deck_index)
{
	dll_node_t *card = deck->head;
	printf("Deck %u:\n", deck_index);
	while (card) {
		printf("\t%d %s\n", ((card_t *)(card->data))->value,
			   ((card_t *)(card->data))->symbol);
		card = card->next;
	}
}

void SortDeck(doubly_linked_list_t *deck)
{
	for (dll_node_t *card_it1 = deck->head; card_it1->next; card_it1 = card_it1->next)
		for (dll_node_t *card_it2 = card_it1->next; card_it2; card_it2 = card_it2->next)
		{
			if (!CompareCards((card_t *)(card_it1->data), (card_t *)(card_it2->data))) {
				void *aux = card_it1->data;
				card_it1->data = card_it2->data;
				card_it2->data = aux;
			}
		}
}

// This function returns 1 if <card1> is smaller than <card2> and 0 otherwise
int CompareCards(card_t *card1, card_t *card2)
{
	if (card1->value < card2->value)
		return 1;
	else if (card1->value > card2->value)
		return 0;
	else {
		int s1, s2;
		char *symbols[] = {"HEART", "SPADE", "DIAMOND", "CLUB"};
		for (int i = 0; i <=3; i++) {
			if (strcmp(card1->symbol, symbols[i]) == 0)
				s1 = i;
			if (strcmp(card2->symbol, symbols[i]) == 0)
				s2 = i;
		}

		if (s1 <= s2)
			return 1;
		else
			return 0;
	}
}