/*******************************************************************************
 * AUTHOR		: Emily Christiansen
 * STUDENT ID	: 1027461
 * ASSIGN # 01	: Deck of Cards
 * CLASS		: CS1C
 * SECTION		: MW: 2:00 pm
 * DUE DATE		: 08/31/16
 ******************************************************************************/
#include "Card.h"

	/***************************************************************************
	 CONSTRUCTORS & DESTRUCTOR
	 **************************************************************************/
	Card::Card()
	{
		cardSuit = 0;
		cardRank = 0;
	}
	Card::~Card()
	{
	}

	// Overloaded constructor for assigning the suit and rank immediately
	Card::Card(int startingSuit, int startingRank)
	{
		cardSuit = startingSuit;
		cardRank = startingRank;
	}

	/***************************************************************************
 	 ACCESSORS
	 **************************************************************************/
	int Card::GetRank()
	{
		return cardRank;
	}

	int Card::GetSuit()
	{
		return cardSuit;
	}

	bool Card::CompareCards(Card compareTo) //IN - Card object to compare the
											// 		private elements to
	{
		bool equal;
		equal = false;

		if(cardRank == compareTo.GetRank())
		{
			if(cardSuit == compareTo.GetSuit())
			{
				equal = true;
			}
		}
		return equal;
	}
