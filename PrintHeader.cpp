/*******************************************************************************
 * AUTHOR		: Emily Christiansen
 * STUDENT ID	: 1027461
 * ASSIGN # 01	: Deck of Cards
 * CLASS		: CS1C
 * SECTION		: MW: 2:00 pm
 * DUE DATE		: 08/31/16
 ******************************************************************************/

/*******************************************************************************
 * 	FUNCTION PrintHeader
 * _____________________________________________________________________________
 * 	This function receives an assignment name, type, and number then
 * 		outputs the appropriate header -
 * 		returns nothing.
 * 	____________________________________________________________________________
 * 	PRE-CONDITIONS
 * 			asName:	Assignment name has to be previously defined
 * 			asType: Assignment type has to be previously defined
 * 			asNum:	Assignment number has to be previously defined
 *
 * 	POST-CONDITIONS
 * 			This function will output the class heading.
 ******************************************************************************/
#include "Header.h"

void PrintHeader (string asName,	// IN - Assignment name
				  char asType,		// IN - Assignment type
				  	  	  	  	  	//    - LAB or ASSIGNMENT)
				  int asNum)		// IN - Assignment number
{
	cout << left;
	cout << "******************************************************\n";
	cout <<	"*  PROGRAMMED BY : Emily Christiansen";
	cout << "\n*  " << setw(14) << "STUDENT ID" << ": 1027461";
	cout << "\n*  " << setw(14) << "CLASS" << ": CS1C --> MW - 2:00pm";
	cout << "\n*  ";

	// determines if the assignment is an assignment or a lab from input
	if(toupper (asType) == 'L')
	{
		cout << "LAB #" << setw(2);
	}
	else
	{
		cout << "ASSIGNMENT #" << setw(2);
	}
	cout << asNum << ": " << asName;
	cout << "\n******************************************************\n\n";
	cout << right;
}
