**Name: Ionescu Matei-Ștefan**  
**Group: 313CAb**

# Homework #1 - Now You See Me

## Description:

The program starts by reading commands from the keyboard.  
The supported commands are:

1. **ADD_DECK \<number_of_cards>**

	*This command adds a new deck of cards to the set of decks.*

	When the *ADD_DECK* command is given, the *AddDeckCommand* function will be
	called and it will check if the command's argument is valid. If this is the
	case, it will read the *\<number_of_cards>* valid cards from keyboard and
	add them to a new deck that will be placed at the end of the set of decks.

2. **DEL_DECK \<deck_index>**
	
	*This command deletes a deck from the set.*
	
	When the *DEL_DECK* command is given, the *DelDeckCommand* function will be
	called and it will check if the command's argument is valid. If this is the
	case, it will delete the deck at the *\<deck_index>* position from the set
	of decks and it will free the memory allocated for it.

3. **DEL_CARD \<deck_index> \<card_index>**
	
	*This command deletes a card from a deck.*
	
	When the *DEL_CARD* command is given, the *DelCardCommand* function will be
	called and it will check if the command's arguments are valid. If this is
	the case, it will find the deck at the *\<deck_index>* position in the set
	and it will remove the card at the *\<card_index>* position from it and it
	will free the memory allocated for the card.

4. **ADD_CARDS \<deck_index> \<number_of_cards>** 

	*This command adds cards to a deck.*

	When the *ADD_CARDS* command is given, the *AddCardsCommand* function will
	be called and it will check if the command's arguments are valid. If this is
	the case, it will find the deck at position *\<deck_index>* and it will read
	and add *\<number_of_cards>* cards to it.

5. **DECK_NUMBER**

	*This command shows the numbers of decks in set.*

	When the *DECK_NUMBER* command is given, the *DeckNumberCommand* function
	will be called and it will check if the number of arguments is correct. If
	this is the case, it will show the number of decks currently in set.

6. **DECK_LEN \<deck_index>**

	*This command shows the length of a deck.*

	When the *DECK_LEN* command is given, the *DeckLenCommand* function will be
	called and it will check if the command's argument is valid. If this is the
	case, it will find the deck at position *\<deck_index>* and show its length.

7. **SHUFFLE_DECK \<deck_index>**

	*This command shuffles a deck.*

	When the *SHUFFLE_DECK* command is given the *ShuffleDeckCommand* function
	will be called and it will check if the command's argument is valid. If this
	is the case, it will shuffle the deck at position *\<deck_index>* by
	switching the first half of the deck with the second one.

8. **MERGE_DECKS \<deck_index1> \<deck_index2>**

	*This command merges two decks.*

	When the *MERGE_DECKS* command is given the *MergeDecksCommand* function
	will be called and it will check if the command's arguments are valid. If
	this is the case, it will proceed to merge the decks at position
	*\<deck_index1>* and *\<deck_index2>* into one. Memory will be allocated for
	a new deck and it will be completed with cards by taking one card from each
	of the decks until one of them runs out and then add the rest of the cards
	that remained in either of the decks. The new deck will be added to the end
	of the set of decks.

9. **SPLIT_DECK \<deck_index> \<split_index>**

	*This command splits a deck into two.*

	When the *SPLIT_DECK* command is given the *SplitDeckCommand* function
	will be called and it will check if the command's arguments are valid.
	If this is the case, it will proceed to split the deck at position
	*\<deck_index>* into two. Memory will be allocated for a new deck which
	will be completed with the cards from *\<split_index>* to the end of the
	deck and it will be added to the set of deck right after the deck that
	was split.

10. **REVERSE_DECK \<deck_index>**

	*This command reverses a deck.*

	When the *REVERSE_DECK* command is given the *ReverseDeckCommand* function
	will be called and it will check if the command's argument is valid. If this
	is the case, it will proceed to reverse the deck in the *\<deck_index>*
	position.

11. **SHOW_DECK \<deck_index>**

	*This command shows a deck.*

	When the *SHOW_DECK* command is given the *ShowDeckCommand* function will be
	called and it will check if the command's argument is valid. If this is the
	case, it will show the deck in the *\<deck_index>* position.

12. **SHOW_ALL**

	*This command shows all the decks in the set.*

	When the *SHOW_ALL* command is given the *ShowAllCommand* function will be
	called and it will check if the number of arguments is correct. If this is
	the case, it will show all the decks in the set.

13. **SORT_DECK \<deck_index>**

	*This command sorts a deck.*

	When the *SORT_DECK* command is given the *SortDeckCommand* function will be
	called and it will check if the command's argument is valid. If this is the
	case, it will proceed to sort the deck at the *\<deck_index>* position.

14. **EXIT**

	*This command exits the program.*

	When the *EXIT* command is given the *ExitCommand* function will be called
	and it will check if the number of arguments is correct. If this is the
	case, it will free all the allocated memory. The command will then return 0
	in main, ending the execution of the program.


## Comments on homework:

* Do you think you could have done a better implementation?
	
	> Well, I don't think that my implementation is perfect, so it could
	> probably be improved, but this is the best implementation that I could do
	> and I am pretty happy with how it turned out.

* What did you learn from doing this homework?

	> I learned to implement and use generic linked lists, to write a README
	> using Markdown and to better organize my code.

* Other comments

	> I liked the homework and I think it achieved its objectives.
