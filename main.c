// Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers.h"

#define LEN 30
#define MAX_ARG_COUNT 10

int main(void)
{
	doubly_linked_list_t *set_of_decks;
	set_of_decks = dll_create(sizeof(doubly_linked_list_t));

	char command_line[LEN];
	unsigned int argc;
	char *argv[MAX_ARG_COUNT];

	while (1) {

		// parse command and arguments
		fgets(command_line, LEN - 1, stdin);
		char *token = strtok(command_line, " \n");
		char *command = token;
		argc = 0;
		if (token != NULL)
			token = strtok(NULL, " \n");
		while (token != NULL && argc <= MAX_ARG_COUNT) {
			argv[argc] = token;
			argc++;
			token = strtok(NULL, " \n");
		}
		if (command != NULL) {
			if (strcmp(command, "ADD_DECK") == 0) {
				AddDeckCommand(set_of_decks, argc, argv);
			} else if (strcmp(command, "DEL_DECK") == 0) {
				DelDeckCommand(set_of_decks, argc, argv);
			} else if (strcmp(command, "DEL_CARD") == 0) {
				DelCard(set_of_decks, argc, argv);
			} else if (strcmp(command, "ADD_CARDS") == 0) {
				AddCards(set_of_decks, argc, argv);
			} else if (strcmp(command, "DECK_NUMBER") == 0) {
				DeckNumber(set_of_decks, argc);
			} else if (strcmp(command, "DECK_LEN") == 0) {
				DeckLen(set_of_decks, argc, argv);
			} else if (strcmp(command, "SHUFFLE_DECK") == 0) {
				ShuffleDeck(set_of_decks, argc, argv);
			} else if (strcmp(command, "MERGE_DECKS") == 0) {
				MergeDecks(set_of_decks, argc, argv);
			} else if (strcmp(command, "SPLIT_DECK") == 0) {
				SplitDeckCommand(set_of_decks, argc, argv);
			} else if (strcmp(command, "REVERSE_DECK") == 0) {
				ReverseDeckCommand(set_of_decks, argc, argv);
			} else if (strcmp(command, "SHOW_DECK") == 0) {
				ShowDeckCommand(set_of_decks, argc, argv);
			} else if (strcmp(command, "SHOW_ALL") == 0) {
				ShowAllCommand(set_of_decks, argc);
			} else if (strcmp(command, "SORT_DECK") == 0) {
				SortDeckCommand(set_of_decks, argc, argv);
			} else if (strcmp(command, "EXIT") == 0) {
				ExitCommand(set_of_decks, argc);
				return 0;
			} else
				printf("Invalid command. Please try again.\n");
		}
	}
}