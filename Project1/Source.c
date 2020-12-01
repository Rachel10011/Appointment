//PROG71985F20 - Group Assignment
//Fall 2020
//Group members:
	//Thi Huong Tra Le
	//Dominic Pham
	//Le Minh Nguyen

#define _CRT_SECURE_NO_WARNINGS
#include "Features.h"
#include <string.h>

int main(void)
{
	PAPPOINTMENT apptList[MAXAPPT];
	APPOINTMENT newAppt;
	bool repeat = true;
	char selection;
	int size = 0;
	while (repeat)
	{
		menu();
		selection = getUserInput("Enter here: ");

		switch (selection)
		{
		case (1):
			newAppt = createAppt();
			addNewAppt(apptList, copyNewAppt(newAppt), &size);
			continue;
		case (2):
			deleteExistingAppt(apptList, &size);
			continue;
	/*	case ('3'):

			updateExistingAppt();
			continue;
		case ('4'):
			displaySingleAppt();
			continue;
		case ('5'):
			displayRangeAppt();
			continue;

		case ('6'):

			displayAllAppt();
			continue;
		case ('7'):

			searchForAppt();
			continue;	*/
		case (8):
			repeat = false;
			break;
		default:
			puts("Invalid input");
			continue;
		}
	}
	puts("\nThank you!\n");
	freeAppt(apptList,&size);

	return 0;
}


	

