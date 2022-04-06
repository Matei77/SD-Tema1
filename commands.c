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

	// transform the command's first argument string to integer
	char *endptr;
	int cards_nr = strtol(argv[0], &endptr, 10);

	// check if the provided value was not a number
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// create a new deck
	doubly_linked_list_t *deck = dll_create(sizeof(card_t));

	// read the cards and add them to the new deck
	ReadCardsToDeck(deck, cards_nr);

	// add the new deck to the set of decks
	dll_add_nth_node(set_of_decks, set_of_decks->size, deck);
	free(deck);

	printf("The deck was successfully created with %d cards.\n", cards_nr);
}

// This function checks if the arguments of the command are valid and, if this
// is the case, deletes a deck from the list of decks
void DelDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					char *argv[])
{
	// check number of arguments
	if (argc != 1) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// transform the command's first argument string to integer
	char *endptr;
	unsigned int deck_index = strtoul(argv[0], &endptr, 10);

	// check if the provided value was not a number
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// check if the deck index is not valid
	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	// delete the deck
	DelDeck(set_of_decks, deck_index);

	printf("The deck %u was successfully deleted.\n", deck_index);
}

// This function checks if the arguments of the command are valid and, if this
// is the case, deletes a card from a deck
void DelCardCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					char *argv[])
{
	// check number of arguments
	if (argc != 2) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// transform the command's first argument string to integer
	char *endptr;
	unsigned int deck_index = strtoul(argv[0], &endptr, 10);

	// check if the provided value was not a number
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}
	// transform the command's second argument string to integer
	unsigned int card_index = strtoul(argv[1], &endptr, 10);

	// check if the provided value was not a number
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// check if the deck index is not valid
	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	// get the deck from which the card will be removed
	dll_node_t *deck_node = get_nth_node(set_of_decks, deck_index);
	doubly_linked_list_t *deck = (doubly_linked_list_t *)(deck_node->data);

	// check if the card index is not valid
	if (!CheckIndex(deck, card_index)) {
		printf("The provided index is out of bounds for deck %u.\n",
			   deck_index);
		return;
	}

	// check if removing the card will empty the deck
	if (deck->size == 1) {
		DelDeck(set_of_decks, deck_index);
	} else {
		dll_node_t *card = dll_remove_nth_node(deck, card_index);
		free(card->data);
		free(card);
	}

	printf("The card was successfully deleted from deck %u.\n", deck_index);
}

// This function checks if the arguments of the command are valid and, if this
// is the case, adds cards to a deck
void AddCardsCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					 char *argv[])
{
	// check number of arguments
	if (argc != 2) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// transform the command's first argument string to integer
	char *endptr;
	unsigned int deck_index = strtoul(argv[0], &endptr, 10);

	// check if the provided value was not a number
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}
	// transform the command's second argument string to integer
	int cards_nr = strtol(argv[1], &endptr, 10);

	// check if the provided value was not a number
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// check if the deck index is not valid
	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	// get the deck in which the cards will be added
	dll_node_t *deck_node = get_nth_node(set_of_decks, deck_index);
	doubly_linked_list_t *deck = (doubly_linked_list_t *)(deck_node->data);

	// read the cards and add them to the deck
	ReadCardsToDeck(deck, cards_nr);

	printf("The cards were successfully added to deck %u.\n", deck_index);
}

// This function checks if the arguments of the command are valid and, if this
// is the case, prints the number of decks
void DeckNumberCommand(doubly_linked_list_t *set_of_decks, unsigned int argc)
{
	// check number of arguments
	if (argc != 0) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	printf("The number of decks is %u.\n", set_of_decks->size);
}

// This function checks if the arguments of the command are valid and, if this
// is the case, prints the length of a deck
void DeckLenCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					char *argv[])
{
	// check number of arguments
	if (argc != 1) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// transform the command's first argument string to integer
	char *endptr;
	unsigned int deck_index = strtoul(argv[0], &endptr, 10);

	// check if the provided value was not a number
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// check if the deck index is not valid
	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	// get the deck we should find the length for
	dll_node_t *deck_node = get_nth_node(set_of_decks, deck_index);

	unsigned int length = ((doubly_linked_list_t *)(deck_node->data))->size;

	printf("The length of deck %u is %u.\n", deck_index, length);
}

// This function checks if the arguments of the command are valid and, if this
// is the case, shuffles a deck by switching the first half of the deck with the
// second one
void ShuffleDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
						char *argv[])
{
	// check number of arguments
	if (argc != 1) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// transform the command's first argument string to integer
	char *endptr;
	unsigned int deck_index = strtoul(argv[0], &endptr, 10);

	// check if the provided value was not a number
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// check if the deck index is not valid
	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	// get the deck which will be shuffled
	dll_node_t *deck_node = get_nth_node(set_of_decks, deck_index);
	doubly_linked_list_t *deck = (doubly_linked_list_t *)(deck_node->data);

	// shuffle the deck
	ShuffleDeck(deck);

	printf("The deck %u was successfully shuffled.\n", deck_index);
}

// This function checks if the arguments of the command are valid and, if this
// is the case, merges two decks together
void MergeDecksCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					   char *argv[])
{
	// check number of arguments
	if (argc != 2) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// transform the command's first argument string to integer
	char *endptr;
	unsigned int deck_index1 = strtoul(argv[0], &endptr, 10);

	// check if the provided value was not a number
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}
	// transform the command's second argument string to integer
	unsigned int deck_index2 = strtoul(argv[1], &endptr, 10);

	// check if the provided value was not a number
	if (argv[1] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// check if the deck indexes are not valid
	if (!CheckIndex(set_of_decks, deck_index1) ||
		!CheckIndex(set_of_decks, deck_index2)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	// merge the decks
	MergeDecks(set_of_decks, deck_index1, deck_index2);

	printf("The deck %u and the deck %u were successfully merged.\n",
		   deck_index1, deck_index2);
}

// This function checks if the arguments of the command are valid and, if this
// is the case, splits a deck into two
void SplitDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					  char *argv[])
{
	// check number of arguments
	if (argc != 2) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// transform the command's first argument string to integer
	char *endptr;
	unsigned int deck_index = strtoul(argv[0], &endptr, 10);

	// check if the provided value was not a number
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}
	// transform the command's second argument string to integer
	unsigned int split_index = strtoul(argv[1], &endptr, 10);

	// check if the provided value was not a number
	if (argv[1] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// check if the deck index is not valid
	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	// get the deck witch will be split
	dll_node_t *deck_node = get_nth_node(set_of_decks, deck_index);
	doubly_linked_list_t *deck = (doubly_linked_list_t *)(deck_node->data);

	// check if the split_index is not valid
	if (!CheckIndex(deck, split_index)) {
		printf("The provided index is out of bounds for deck %u.\n",
			   deck_index);
		return;
	}

	// check if a deck will be empty after split
	if (split_index == 0) {
		printf("The deck %u was successfully split by index %u.\n", deck_index,
			   split_index);
		return;
	}

	// split deck
	SplitDeck(set_of_decks, deck, deck_index, split_index);

	printf("The deck %u was successfully split by index %u.\n", deck_index,
		   split_index);
}

// This function checks if the arguments of the command are valid and, if this
// is the case, reverses a deck
void ReverseDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
						char *argv[])
{
	// check number of arguments
	if (argc != 1) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// transform the command's first argument string to integer
	char *endptr;
	unsigned int deck_index = strtoul(argv[0], &endptr, 10);

	// check if the provided value was not a number
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// check if the deck index is not valid
	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	// get the deck that will be reversed
	dll_node_t *deck_node = get_nth_node(set_of_decks, deck_index);
	doubly_linked_list_t *deck = (doubly_linked_list_t *)(deck_node->data);

	// reverse the deck
	ReverseDeck(deck);

	printf("The deck %u was successfully reversed.\n", deck_index);
}

// This function checks if the arguments of the command are valid and, if this
// is the case, shows a deck
void ShowDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					 char *argv[])
{
	// check number of arguments
	if (argc != 1) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// transform the command's first argument string to integer
	char *endptr;
	unsigned int deck_index = strtoul(argv[0], &endptr, 10);

	// check if the provided value was not a number
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// check if the deck index is not valid
	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	// get the deck that will be shown
	dll_node_t *deck_node = get_nth_node(set_of_decks, deck_index);
	doubly_linked_list_t *deck = (doubly_linked_list_t *)(deck_node->data);

	// show the cards
	ShowDeck(deck, deck_index);
}

// This function checks if the arguments of the command are valid and, if this
// is the case, shows all decks
void ShowAllCommand(doubly_linked_list_t *set_of_decks, unsigned int argc)
{
	// check number of arguments
	if (argc != 0) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// show all decks
	dll_node_t *deck_it = set_of_decks->head;
	for (unsigned int i = 0; i < set_of_decks->size; ++i) {
		doubly_linked_list_t *deck = (doubly_linked_list_t *)(deck_it->data);
		ShowDeck(deck, i);
		deck_it = deck_it->next;
	}
}

// This function checks if the arguments of the command are valid and, if this
// is the case, frees the memory allocated for all decks
void ExitCommand(doubly_linked_list_t *set_of_decks, unsigned int argc)
{
	// check number of arguments
	if (argc != 0) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// deletes all decks
	while (set_of_decks->size) {
		DelDeck(set_of_decks, 0);
	}
	dll_free(&set_of_decks);
}

// This function checks if the arguments of the command are valid and, if this
// is the case, sorts a deck
void SortDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					 char *argv[])
{
	// check number of arguments
	if (argc != 1) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// transform the command's first argument string to integer
	char *endptr;
	unsigned int deck_index = strtoul(argv[0], &endptr, 10);

	// check if the provided value was not a number
	if (argv[0] == endptr || *endptr != '\0') {
		printf("Invalid command. Please try again.\n");
		return;
	}

	// check if the deck index is not valid
	if (!CheckIndex(set_of_decks, deck_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	// get the deck that will be sorted
	dll_node_t *deck_node = get_nth_node(set_of_decks, deck_index);
	doubly_linked_list_t *deck = (doubly_linked_list_t *)(deck_node->data);

	// sort the deck
	SortDeck(deck);

	printf("The deck %u was successfully sorted.\n", deck_index);
}
