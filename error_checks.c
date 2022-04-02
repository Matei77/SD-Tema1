// Copyright Ionescu Matei-Stefan - 313CAb - 2021-2022
#include "error_checks.h"
#include "types.h"

#include <string.h>

// This function returns 1 if a card is valid and 0 otherwise
int CheckCard(card_t card)
{
	if (card.value < 1 || card.value > 14)
		return 0;

	if (strcmp(card.symbol, "HEART") == 0 &&
		strcmp(card.symbol, "SPADE") == 0 &&
		strcmp(card.symbol, "DIAMOND") == 0 && 
		strcmp(card.symbol, "CLUB") == 0)
		return 0;

	return 1;
}

// This function return 1 if an index is valid and 0 otherwise
int CheckIndex(doubly_linked_list_t *list, unsigned int deck_index)
{
	if (list->size > deck_index)
		return 1;
	return 0;
}
