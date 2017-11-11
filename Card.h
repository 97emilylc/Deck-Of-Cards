/*******************************************************************************
 * AUTHOR		: Emily Christiansen
 * STUDENT ID	: 1027461
 * ASSIGN # 01	: Deck of Cards
 * CLASS		: CS1C
 * SECTION		: MW: 2:00 pm
 * DUE DATE		: 08/31/16
 ******************************************************************************/

#ifndef CARD_H_
#define CARD_H_

class Card
{
public:

	/***************************************************************************
 	 CONSTRUCTORS & DESTRUCTOR
	 **************************************************************************/
		Card();
		Card(int startingSuit, int startingRank);
		virtual ~Card();

	/***************************************************************************
 	 ACCESSORS
	 **************************************************************************/
		int GetSuit();
		int GetRank();
		bool CompareCards(Card compareTo);

	private:
		int cardSuit;
		int cardRank;

};

#endif /* CARD_H_ */
