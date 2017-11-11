/*******************************************************************************
 * AUTHOR		: Emily Christiansen
 * STUDENT ID	: 1027461
 * ASSIGN # 01	: Deck of Cards
 * CLASS		: CS1C
 * SECTION		: MW: 2:00 pm
 * DUE DATE		: 08/31/16
 ******************************************************************************/
#include"Header.h"

/*******************************************************************************
 * Random Numbers
 * _____________________________________________________________________________
 * This program will generate a deck of cards using the Card class. It will then
 * 		perform a perfect shuffle on the deck continuously in, counting the
 * 		number of shuffles it requires to return back to the original deck.
 * _____________________________________________________________________________
 * 	INPUT:
 * 		No user input for this program
 *
 * 	OUTPUT:
 * 		The output for this program will be:
 * 			The deck before the first shuffling,
 * 			the deck after the first shuffling,
 * 			the final deck (should match the original deck),
 * 			and the number of shuffles it took to make the deck return to its
 * 			original form.
 ******************************************************************************/

int main()
{
	/***************************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------------
	 * USED FOR CLASS HEADING - ALL WILL BE OUTPUT
	 * -------------------------------------------------------------------------
	 * ASSIGN_NUM	: Assignment Number (specific to this assignment)
	 * ASSIGN_NAME	: Title of the assignment
	 * ASSIGN_TYPE	: The type of assignment
	 **************************************************************************/

	const string ASSIGN_NAME	 	= "Deck of Cards";
	const char 	 ASSIGN_TYPE		= 'A';
	const int 	 ASSIGN_NUM			=  01;

	/***************************************************************************
	 * DATA TABLE
	 * -------------------------------------------------------------------------
	 * 		CARD DECKS
	 * 		--------------------------------------------------------------------
	 * 		cardAr		:	The original deck that the initial cards are
	 * 						assigned
	 * 		masterDeck	:	A copy of the original deck to compare the shuffled
	 * 						decks to
	 *      --------------------------------------------------------------------
	 * equalDecks 	:	The boolean value to determine if the two decks compared
	 * 					are equivalent
	 * shuffleCount	:	The number of shuffles required to make the deck return
	 * 					to is original state
	 * arrayIndex	:	A counter for the index of the array as cards are
	 * 					initialized and stored into it
	 * suitIndex	:	The index of each value of the suits for initializing
	 * 					the cards
	 * rankIndex	:	The index of each value of the ranks for initializing
	 * 					the cards
	 **************************************************************************/

	Card cardAr[DECK_SIZE];
	Card masterDeck[DECK_SIZE];

	bool equalDecks;	//CALC 		- If the two decks being compared are
						//				equivalent
	int shuffleCount;	//CALC-OUT	- The number of shuffles performed
	int arrayIndex;		//CALC		- The index of the current array being
						//				traversed
	int suitIndex;		//CALC		- The index of each suit as it is assigned
						//				to the deck
	int rankIndex;		//CALC		- The index of each rank as it is assigned
						//				to the deck

	PrintHeader(ASSIGN_NAME, ASSIGN_TYPE, ASSIGN_NUM);

	shuffleCount = 0;
	arrayIndex	 = 0;
/*******************************************************************************
 * FIRST DECK
 * -----------------------------------------------------------------------------
 * Nested FOR LOOPS initialize the first deck of playing cards.
 *
 * 		Outer loop: indexes by the suit of each card
 *
 * 		Inner loop: indexes by the rank of each card
 *
 ******************************************************************************/
	for(suitIndex = CLUBS; suitIndex <= SPADES; suitIndex++)
	{
		for(rankIndex = ACE; rankIndex <= TWO; rankIndex++)
		{
			Card newCard(suitIndex, rankIndex);
			cardAr[arrayIndex] = newCard;
			masterDeck[arrayIndex] = newCard;
			arrayIndex++;
		}// END - for(rankIndex = ACE; rankIndex <= TWO; rankIndex++)
	}// END - for(suitIndex = CLUBS; suitIndex <= SPADES; suitIndex++)

	// OUTPUT - Outputs the deck before any shuffling
	cout << "First deck (before shuffling): " << endl << OutputDeck(cardAr);

	PerfectShuffle(cardAr);

	// OUTPUT - Outputs the deck after the first shuffle
	cout << endl << "Deck after first perfect shuffle: " << endl
				 << OutputDeck(cardAr);

	equalDecks = CompareDecks(cardAr, masterDeck);

	//Counting the first shuffle towards the total amount of shuffles
	if(!equalDecks)
	{
		shuffleCount = 1;
	}

	while(!equalDecks)
	{
		PerfectShuffle(cardAr);
		equalDecks = CompareDecks(cardAr, masterDeck);
		shuffleCount++;
	}// END - while(!equalDecks)

	// OUTPUT - Outputs the final deck after it has been returned to its
	//			original state
	cout << "\nThe deck once it has be shuffled back to its original state: "
		 << endl << OutputDeck(cardAr);

	cout << endl << "The number of shuffles to return the deck to the original "
				 <<	"state was: " << shuffleCount << endl;


	return 0;
}
