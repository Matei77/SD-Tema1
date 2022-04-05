// Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
#include "commands.h"
#include "linked_list.h"
#include "types.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function checks if the arguments of the command are valid and, if this
// is the case, adds a new deck to the list of decks
void AddDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					char *argv[])
{
	// check number of arguments
	if (argc != 1) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	char *endptr;
	long cards_nr = strtol(argv[0], &endptr, 10);
	// check if the provided value is not a number
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// add the new deck
	AddDeck(set_of_decks, cards_nr);

	printf("The deck was successfully created with %ld cards.\n", cards_nr);
}

// This function deletes a deck from the list of decks
void DelDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					char *argv[])
{
	// check number of arguments
	if (argc != 1) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	char *endptr;
	unsigned long deck_index = strtoul(argv[0], &endptr, 10);
	// check if the provided index is not a number
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// check if the deck index is not valid
	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the %ld deck list.\n");
		return;
	}

	// delete the deck
	DelDeck(set_of_decks, deck_index);
	printf("The deck %ld was successfully deleted.\n", deck_index);
}

// This function deletes a card from a deck, given the index of the card and
// the index of the deck
void DelCard(doubly_linked_list_t *set_of_decks, unsigned int argc,
			 char *argv[])
{
	if (argc != 2) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	char *endptr;
	unsigned long deck_index = strtoul(argv[0], &endptr, 10);
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}
	unsigned long card_index = strtoul(argv[1], &endptr, 10);
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	// Find the deck from which the card will be removed
	dll_node_t *deck = set_of_decks->head;
	for (unsigned int i = 0; i < deck_index; i++, deck = deck->next)
		;

	if (!CheckIndex((doubly_linked_list_t *)(deck->data), card_index)) {
		printf("The provided index is out of bounds for deck %ld.\n",
			   deck_index);
		return;
	}
	if ((doubly_linked_list_t *)(deck->data) == 1) {
		dll_node_t *deck = dll_remove_nth_node(set_of_decks, deck_index);
		dll_free((doubly_linked_list_t **)(&deck->data));
	} else {
		dll_node_t *card = dll_remove_nth_node(
			(doubly_linked_list_t *)(deck->data), card_index);
		free(card->data);
		free(card);
	}
	printf("The card was successfully deleted from deck %ld.\n", deck_index);
}

void AddCards(doubly_linked_list_t *set_of_decks, unsigned int argc,
			  char *argv[])
{
	if (argc != 2) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	char *endptr;
	unsigned long deck_index = strtoul(argv[0], &endptr, 10);
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}
	unsigned long cards_nr = strtoul(argv[1], &endptr, 10);
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	dll_node_t *deck = set_of_decks->head;
	for (unsigned int i = 0; i < deck_index; i++, deck = deck->next)
		;

	card_t card;

	int i = 0;
	while (i < cards_nr) {
		// TODO: use fgets for reading the values
		scanf("%d %9s", &card.value, card.symbol);

		if (CheckCard(card)) {
			dll_add_nth_node((doubly_linked_list_t *)(deck->data),
							 ((doubly_linked_list_t *)(deck->data))->size,
							 &card);
			++i;
		} else
			printf("The provided card is not a valid one.\n");
	}

	printf("The cards wre successfully added to deck %ld\n", deck_index);
}

void DeckNumber(doubly_linked_list_t *set_of_decks, unsigned int argc)
{
	if (argc != 0) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	printf("The number of decks is %ld.\n", set_of_decks->size);
}

void DeckLen(doubly_linked_list_t *set_of_decks, unsigned int argc,
			 char *argv[])
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

	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	dll_node_t *deck = set_of_decks->head;
	for (unsigned int i = 0; i < deck_index; i++, deck = deck->next)
		;

	unsigned int length = ((doubly_linked_list_t *)(deck->data))->size;

	printf("The length of deck %ld is %ld.\n", deck_index, length);
}

void ShuffleDeck(doubly_linked_list_t *set_of_decks, unsigned int argc,
				 char *argv[])
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

	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	dll_node_t *deck_it = set_of_decks->head;
	for (unsigned int i = 0; i < deck_index; i++, deck_it = deck_it->next)
		;

	doubly_linked_list_t *current_deck =
		(doubly_linked_list_t *)(deck_it->data);
	unsigned int halfsize = current_deck->size / 2;
	dll_node_t *middle_of_deck = current_deck->head;

	for (unsigned int i = 0; i < halfsize;
		 i++, middle_of_deck = middle_of_deck->next)
		;

	current_deck->head->prev = current_deck->tail;
	current_deck->tail->next = current_deck->head;

	current_deck->tail = middle_of_deck->prev;
	current_deck->head = middle_of_deck;

	middle_of_deck->prev->next = NULL;
	middle_of_deck->prev = NULL;

	printf("The deck %ld was successfully shuffled.\n", deck_index);
}

void MergeDecks(doubly_linked_list_t *set_of_decks, unsigned int argc,
				char *argv[])
{
	// Check arguments
	if (argc != 2) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	char *endptr;
	unsigned long deck_index1 = strtoul(argv[0], &endptr, 10);
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}
	unsigned long deck_index2 = strtoul(argv[1], &endptr, 10);
	if (argv[1] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	if (!CheckIndex(set_of_decks, deck_index1) ||
		!CheckIndex(set_of_decks, deck_index2)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	// Find first deck
	dll_node_t *deck_it = set_of_decks->head;
	for (unsigned int i = 0; i < deck_index1; i++, deck_it = deck_it->next)
		;
	doubly_linked_list_t *deck1 = ((doubly_linked_list_t *)(deck_it->data));

	// Find second deck
	for (unsigned int i = 0; i < deck_index2; i++, deck_it = deck_it->next)
		;
	doubly_linked_list_t *deck2 = ((doubly_linked_list_t *)(deck_it->data));

	// Merge decks
	doubly_linked_list_t *new_deck = dll_create(sizeof(card_t));
	dll_node_t *card_it1 = deck1->head, *card_it2 = deck2->head;
	while (card_it1 && card_it2) {
		dll_add_nth_node(new_deck, new_deck->size, card_it1->data);
		dll_add_nth_node(new_deck, new_deck->size, card_it2->data);
		card_it1 = card_it1->next;
		card_it2 = card_it2->next;
	}

	while (card_it1) {
		dll_add_nth_node(new_deck, new_deck->size, card_it1->data);
		card_it1 = card_it1->next;
	}

	while (card_it2) {
		dll_add_nth_node(new_deck, new_deck->size, card_it2->data);
		card_it2 = card_it2->next;
	}

	DelDeck(set_of_decks, deck_index1);
	DelDeck(set_of_decks, deck_index2);

	dll_add_nth_node(set_of_decks, set_of_decks->size, new_deck);

	printf("The deck %ld and the deck %ld were successfully merged.\n",
		   deck_index1, deck_index2);
}

void SplitDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					  char *argv[])
{
	// check number of arguments
	if (argc != 2) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	char *endptr;
	unsigned long deck_index = strtoul(argv[0], &endptr, 10);
	// check if the provided value is not a number
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}
	unsigned long split_index = strtoul(argv[1], &endptr, 10);
	// check if the provided value is not a number
	if (argv[1] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// check if the deck index is not valid
	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	// find the deck from which the card will be removed
	dll_node_t *deck_it = set_of_decks->head;
	for (unsigned int i = 0; i < deck_index; i++, deck_it = deck_it->next)
		;

	// check if the split_index is not valid
	if (!CheckIndex((doubly_linked_list_t *)(deck_it->data), split_index)) {
		printf("The provided index is out of bounds for deck %ld.\n",
			   deck_index);
		return;
	}

	// check if a deck will be empty after split
	if (split_index == ((doubly_linked_list_t *)(deck_it->data))->size - 1 ||
		split_index == 0) {
		printf("The %ld was successfully split by index %ld.\n", deck_index,
			   split_index);
		return;
	}

	// split deck
	SplitDeck(set_of_decks, (doubly_linked_list_t *)(deck_it->data), deck_index,
			  split_index);

	printf("The %ld was successfully split by index %ld.\n", deck_index,
		   split_index);
}

void ReverseDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
						char *argv[])
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

	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	dll_node_t *deck_it = set_of_decks->head;
	for (unsigned int i = 0; i < deck_index; i++, deck_it = deck_it->next)
		;
	doubly_linked_list_t *deck = (doubly_linked_list_t*)(deck_it->data);

	dll_node_t *card_it	= deck->head;
	dll_node_t *aux;

	for(unsigned int i = 0; i < deck->size; i++) {
		aux = card_it->next;
		card_it->next = card_it->prev;
		card_it->prev = aux;
		card_it = aux;
	}

	aux = deck->head;
	deck->head = deck->tail;
	deck->tail = aux;

	printf("The deck %ld was successfully reversed.\n", deck_index);
}

void ShowDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
						char *argv[])
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

	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	dll_node_t *deck_it = set_of_decks->head;
	for (unsigned int i = 0; i < deck_index; i++, deck_it = deck_it->next)
		;
	doubly_linked_list_t *deck = (doubly_linked_list_t*)(deck_it->data);

	ShowDeck(deck, deck_index);
}

void ShowAllCommand(doubly_linked_list_t *set_of_decks, unsigned int argc)
{
	if (argc != 0) {
		printf("Invalid command. Please try again.\n");
		return;
	}
	dll_node_t *deck_it = set_of_decks->head;
	for (unsigned int i = 0; i < set_of_decks->size; ++i) {
		doubly_linked_list_t *deck = (doubly_linked_list_t*)(deck_it->data);
		ShowDeck(deck, i);
		printf("...\n");
	}
}

void ExitCommand(doubly_linked_list_t *set_of_decks, unsigned int argc)
{
	if (argc != 0) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	while (set_of_decks->size) {
		DelDeck(set_of_decks, 0);
	}
	dll_free(&set_of_decks);
}