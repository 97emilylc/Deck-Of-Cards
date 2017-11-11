/*******************************************************************************
 * AUTHOR		: Emily Christiansen
 * STUDENT ID	: 1027461
 * ASSIGN # 01	: Deck of Cards
 * CLASS		: CS1C
 * SECTION		: MW: 2:00 pm
 * DUE DATE		: 08/31/16
 ******************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "Card.h"

using namespace std;

// Global Variables
const int DECK_SIZE = 52;

// Enumerated Types
enum Suit
{
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES,
	NO_SUIT
};

enum Rank
{
	ACE,
	KING,
	QUEEN,
	JACK,
	TEN,
	NINE,
	EIGHT,
	SEVEN,
	SIX,
	FIVE,
	FOUR,
	THREE,
	TWO,
	NO_RANK
};

// Corresponding Enum String Arrays
const string SUIT_NAMES[4]  = {"Clubs", "Diamonds", "Hearts", "Spades"};
const string RANK_NAMES[13] = {"Ace", "King", "Queen", "Jack", "Ten",
							   "Nine", "Eight", "Seven", "Six", "Five",
							   "Four", "Three", "Two"};


/*-------------------------------PROTOTYPES-------------------------------------
  ******************************************************************************
  * PrintHeader
  * 	This function receives an assignment name, type, and number then outputs
  * 			the appropriate header
  * 	- returns nothing -> This will output the class heading.
  *****************************************************************************/
	void PrintHeader (string asName,	// IN - Assignment name
						char asType,	// IN - Assignment type
				  	  	  	  	  		//    - (LAB or ASSIGNMENT)
						int asNum);		// IN - Assignment number

  /*****************************************************************************
  * PerfectShuffle
  * 	This function receives array of type card and performs a perfect shuffle
  * 		on the "deck" of cards.
  * 	- returns nothing -> The array is passed by reference.
  *****************************************************************************/
	void PerfectShuffle(Card cardAr[]);

  /*****************************************************************************
  * OutputDeck
  * 	This function receives array of type card formats a ostringstream with
  * 		the data contained in the deck of cards by using the global
  * 		constants that correspond with the array.
  * 	- returns the formatted string.
  *****************************************************************************/
	string OutputDeck(Card cardAr[]);

  /*****************************************************************************
  * CompareDecks
  * 	This function receives two arrays of type card and compares each element
  * 		to determine if the arrays are equal.
  * 	- returns a boolean value if they are equal.
  *****************************************************************************/
	bool CompareDecks(Card cardAr[], Card cardArCompare[]);

//------------------------------------------------------------------------------

#endif
