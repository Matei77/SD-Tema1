// Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
#ifndef UTILS_H_
#define UTILS_H_

#include "types.h"

int CheckCard(card_t card);

int CheckIndex(doubly_linked_list_t *list, unsigned int deck_index);

void ReadCardsToDeck(doubly_linked_list_t *deck, int cards_nr);

void DelDeck(doubly_linked_list_t *set_of_decks, unsigned int deck_index);

void ShuffleDeck(doubly_linked_list_t *deck);

void MergeDecks(doubly_linked_list_t *set_of_decks, unsigned int deck_index1,
				unsigned int deck_index2);

void SplitDeck(doubly_linked_list_t *set_of_decks, doubly_linked_list_t *deck,
			   unsigned int deck_index, unsigned int split_index);

void ReverseDeck(doubly_linked_list_t *deck);

void ShowDeck(doubly_linked_list_t *deck, unsigned int deck_index);

void SortDeck(doubly_linked_list_t *deck);

#endif  // UTILS_H_
