// Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
#ifndef UTILS_H
#define UTILS_H

#include "types.h"

int CheckCard(card_t card);

int CheckIndex(doubly_linked_list_t *list, unsigned int deck_index);

void AddDeck(doubly_linked_list_t *set_of_decks, unsigned int cards_nr);

void DelDeck(doubly_linked_list_t *set_of_decks, unsigned int deck_index);

void ShowDeck(doubly_linked_list_t *deck, unsigned int deck_index);

#endif