// Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
#ifndef UTILS_H_
#define UTILS_H_

#include "types.h"

int CheckCard(card_t card);

int CheckIndex(doubly_linked_list_t *list, unsigned int deck_index);

void AddDeck(doubly_linked_list_t *set_of_decks, int cards_nr);

void DelDeck(doubly_linked_list_t *set_of_decks, unsigned int deck_index);

void SplitDeck(doubly_linked_list_t *set_of_decks, doubly_linked_list_t *deck,
			   unsigned int deck_index, unsigned int split_index);

void ShowDeck(doubly_linked_list_t *deck, unsigned int deck_index);

void SortDeck(doubly_linked_list_t *deck);

#endif  // UTILS_H_
