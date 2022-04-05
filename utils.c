// Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
#include "utils.h"
#include "types.h"
#include "linked_list.h"

#include <string.h>

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
void AddDeck(doubly_linked_list_t *set_of_decks, unsigned int cards_nr)
{
	doubly_linked_list_t *deck = dll_create(sizeof(card_t));
	card_t card;

	int i = 0;
	while (i < cards_nr) {
		// TODO: use fgets for reading the values
		scanf("%d %9s", &card.value, card.symbol);

		if (CheckCard(card)) {
			dll_add_nth_node(deck, deck->size, &card);
			++i;
		} else
			printf("The provided card is not a valid one.\n");
	}

	dll_add_nth_node(set_of_decks, set_of_decks->size, deck);
}

// This function deletes the deck at position <deck_index> from the list of
// decks and frees the memory allocated for it
void DelDeck(doubly_linked_list_t *set_of_decks, unsigned int deck_index)
{
	dll_node_t *deck = dll_remove_nth_node(set_of_decks, deck_index);
	dll_free((doubly_linked_list_t **)(&deck->data));
}

void SplitDeck(doubly_linked_list_t *set_of_decks, doubly_linked_list_t *deck,
			   unsigned int deck_index, unsigned int split_index)
{
	doubly_linked_list_t *new_deck = dll_create(sizeof(card_t));
	dll_node_t *card_it = deck->head;
	for (unsigned int i = 0; i < deck_index; i++, card_it = card_it->next)
		;
	while (card_it) {
		dll_add_nth_node(new_deck, new_deck->size, card_it->data);
		card_it = card_it->next;
	}

	dll_add_nth_node(set_of_decks, deck_index+1, new_deck);
}

void ShowDeck(doubly_linked_list_t *deck, unsigned int deck_index)
{
	dll_node_t *card = deck->head;
	printf("Deck %ld:\n", deck_index);
	while(card) {
		printf("\t%d %s\n", ((card_t *)(card->data))->value,  ((card_t *)(card->data))->symbol);
		card = card->next;
	}
}