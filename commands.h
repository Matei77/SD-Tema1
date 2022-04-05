// Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
#ifndef COMMANDS_H
#define COMMANDS_H

#include "types.h"

void AddDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc, char *argv[]);

void DelDeckCommand(doubly_linked_list_t *set_of_decks, unsigned int argc, char *argv[]);

void AddCards(doubly_linked_list_t *set_of_decks, unsigned int argc, char *argv[]);

#endif
