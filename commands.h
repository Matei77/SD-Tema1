// Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "types.h"

void AddDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					char *argv[]);

void DelDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					char *argv[]);

void DelCardCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					char *argv[]);

void AddCardsCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					 char *argv[]);

void DeckNumberCommand(doubly_linked_list_t *set_of_decks, unsigned int argc);

void DeckLenCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					char *argv[]);

void ShuffleDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
						char *argv[]);

void MergeDecksCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					   char *argv[]);

void SplitDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					  char *argv[]);

void ReverseDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
						char *argv[]);

void ShowDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					 char *argv[]);

void ShowAllCommand(doubly_linked_list_t *set_of_decks, unsigned int argc);

void ExitCommand(doubly_linked_list_t *set_of_decks, unsigned int argc);

void SortDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc,
					 char *argv[]);

#endif  // COMMANDS_H_
