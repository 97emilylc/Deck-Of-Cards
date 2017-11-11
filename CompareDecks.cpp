/*******************************************************************************
 * AUTHOR		: Emily Christiansen
 * STUDENT ID	: 1027461
 * ASSIGN # 01	: Deck of Cards
 * CLASS		: CS1C
 * SECTION		: MW: 2:00 pm
 * DUE DATE		: 08/31/16
 ******************************************************************************/

/*******************************************************************************
 * 	FUNCTION CompareDecks
 * _____________________________________________________________________________
 *		This function receives two arrays of type card and compares each element
 * 			to determine if the arrays are equal.
 * 			- returns a boolean value if they are equal.
 * 	____________________________________________________________________________
 * 	PRE-CONDITIONS
 * 			cardAr:			Deck of cards must be previously initialized
 * 			cardArCompare: 	Deck of cards must be previously initialized
 *
 * 	POST-CONDITIONS
 * 			This function will return the boolean value if the arrays contents
 * 				are equal to one another.
 ******************************************************************************/
#include "Header.h"

bool CompareDecks(Card cardAr[], 		// IN - First comparison array
				  Card cardArCompare[]) // IN - Second comparison array
{
	bool equal;		//CALC - OUT	- The result of if the decks are equal
	int  deckIndex; //CALC			- The index as the loop traverses each
					//					element of the deck array

	equal 	  = true;
	deckIndex = 0;

	for(deckIndex = 0; deckIndex < DECK_SIZE; deckIndex++)
	{
		if(!(cardAr[deckIndex].CompareCards(cardArCompare[deckIndex])))
		{
			equal = false;
		}
	}// for(deckIndex = 0; deckIndex < DECK_SIZE; deckIndex++)

	return equal;
}
