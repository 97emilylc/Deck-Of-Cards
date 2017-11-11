/*******************************************************************************
 * AUTHOR		: Emily Christiansen
 * STUDENT ID	: 1027461
 * ASSIGN # 01	: Deck of Cards
 * CLASS		: CS1C
 * SECTION		: MW: 2:00 pm
 * DUE DATE		: 08/31/16
 ******************************************************************************/

/*******************************************************************************
 * 	FUNCTION PerfectShuffle
 * _____________________________________________________________________________
 * 	This function receives a single array of cards and performs a perfect
 * 		shuffle on them. Thus replacing the second card with the 26th, the
 * 		fourth card with the 27th etc.
 * 	____________________________________________________________________________
 * 	PRE-CONDITIONS
 * 			cardAr:	The card array must be pre-initialized.
 *
 * 	POST-CONDITIONS
 * 			This function will return by reference the shuffled array.
 ******************************************************************************/
#include "Header.h"

void PerfectShuffle(Card cardAr[]) // IN - The card "deck" array
{
	int copyDeckIndex;	//CALC - Index of each element of the deck as it is
						// 			traversed
	int firstHalfIndex; //CALC - Index of the first half of the deck as it is
						//			layered with the second half
	int secondHalfIndex;//CALC - Index of the second half of the deck as it is
						//			layered with the first half

	Card masterDeck[DECK_SIZE];
	/***************************************************************************
	 * FOR LOOPS
	 * -------------------------------------------------------------------------
	 * First FOR LOOP:
	 * 		The first for loop simply copies the deck passed into the MASTER
	 * 			DECK. The MASTER DECK will not be changed, just being used as
	 * 			reference when assigning elements.
	 * Second FOR LOOP:
	 * 		The second for loop assigns the elements that are in every other
	 * 			component of the MASTER DECK starting at index 0 to index 24.
	 * Third FOR LOOP:
	 * 		The third for loop assigns the elements that are in every other
	 * 			component of the MASTER DECK starting at index 25 to index 52.
	 **************************************************************************/
	for(copyDeckIndex = 0; copyDeckIndex < DECK_SIZE; copyDeckIndex++)
	{
		masterDeck[copyDeckIndex] = cardAr[copyDeckIndex];
	}//END - for(copyDeckIndex = 0; copyDeckIndex < DECK_SIZE; copyDeckIndex++)

	firstHalfIndex = 0;
	for(copyDeckIndex = 0; copyDeckIndex < DECK_SIZE; copyDeckIndex += 2)
	{
		cardAr[copyDeckIndex] = masterDeck[firstHalfIndex];
		firstHalfIndex++;
	}//END - for(copyDeckIndex = 0; copyDeckIndex < DECK_SIZE; copyDeckIndex += 2)

	secondHalfIndex = (DECK_SIZE / 2);
	for(copyDeckIndex = 1; copyDeckIndex < DECK_SIZE; copyDeckIndex += 2)
	{
		cardAr[copyDeckIndex] = masterDeck[secondHalfIndex];
		secondHalfIndex++;
	}//END - for(copyDeckIndex = 1; copyDeckIndex < DECK_SIZE; copyDeckIndex += 2)
}
