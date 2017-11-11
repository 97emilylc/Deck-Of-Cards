/*******************************************************************************
 * AUTHOR		: Emily Christiansen
 * STUDENT ID	: 1027461
 * ASSIGN # 01	: Deck of Cards
 * CLASS		: CS1C
 * SECTION		: MW: 2:00 pm
 * DUE DATE		: 08/31/16
 ******************************************************************************/

/*******************************************************************************
  * OutputDeck
  * ____________________________________________________________________________
  * 	This function receives array of type card formats a ostringstream with
  * 		the data contained in the deck of cards by using the global
  * 		constants that correspond with the array.
 * 	____________________________________________________________________________
 * 	PRE-CONDITIONS
 * 			cardAr[]	:	array of card elements
 *
 * 	POST-CONDITIONS
 * 			This function will output the class heading.
 ******************************************************************************/
#include "Header.h"

string OutputDeck(Card cardAr[])
{
	ostringstream output; //OUT - The string that will be formated with the
						  // 	  list style output

	/***************************************************************************
	 * FOR LOOP
	 * -------------------------------------------------------------------------
	 * 	This loop outputs each element of the array of cards by using the
	 * 		predefined global constants of string arrays that correspond to the
	 * 		enumerated type.
	 **************************************************************************/
	for(int i = 0; i < 52; i++)
	{
		output << "Card # " << i + 1 << ": "
			   << RANK_NAMES[cardAr[i].GetRank()] << " of "
			   << SUIT_NAMES[cardAr[i].GetSuit()] << endl;
	}
	return output.str();
}
