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
		fgets(command_line, LEN - 1, stdin);
		char *token = strtok(command_line, " \n");
		char *command = token;
		argc = 0;
		if (token != NULL)
			token = strtok(NULL, " \n");
		while (token != NULL) {
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
			}
		}
	}
	return 0;
}