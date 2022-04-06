// Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers.h"

#define COMMAND_LEN 30
#define MAX_ARG_COUNT 5

void ParseCommand(char *command_line, char **command, char *argv[],
				  unsigned int *argc);

int main(void)
{
	doubly_linked_list_t *set_of_decks;
	set_of_decks = dll_create(sizeof(doubly_linked_list_t));

	unsigned int argc;
	char command_line[COMMAND_LEN], *command = NULL, *argv[MAX_ARG_COUNT];

	while (1) {
		// parse command and arguments
		ParseCommand(command_line, &command, argv, &argc);

		if (command != NULL) {
			if (strcmp(command, "ADD_DECK") == 0) {
				AddDeckCommand(set_of_decks, argc, argv);
			} else if (strcmp(command, "DEL_DECK") == 0) {
				DelDeckCommand(set_of_decks, argc, argv);
			} else if (strcmp(command, "DEL_CARD") == 0) {
				DelCardCommand(set_of_decks, argc, argv);
			} else if (strcmp(command, "ADD_CARDS") == 0) {
				AddCardsCommand(set_of_decks, argc, argv);
			} else if (strcmp(command, "DECK_NUMBER") == 0) {
				DeckNumberCommand(set_of_decks, argc);
			} else if (strcmp(command, "DECK_LEN") == 0) {
				DeckLenCommand(set_of_decks, argc, argv);
			} else if (strcmp(command, "SHUFFLE_DECK") == 0) {
				ShuffleDeckCommand(set_of_decks, argc, argv);
			} else if (strcmp(command, "MERGE_DECKS") == 0) {
				MergeDecksCommand(set_of_decks, argc, argv);
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
			} else {
				printf("Invalid command. Please try again.\n");
			}
		}
	}
}

void ParseCommand(char *command_line, char **command, char *argv[],
				  unsigned int *argc)
{
	fgets(command_line, COMMAND_LEN - 1, stdin);

	char *token = strtok(command_line, " \n");
	*command = token;

	if (token != NULL)
		token = strtok(NULL, " \n");

	*argc = 0;
	while (token != NULL && (*argc) <= MAX_ARG_COUNT) {
		argv[(*argc)] = token;
		(*argc)++;
		token = strtok(NULL, " \n");
	}
}
