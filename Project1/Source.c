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
		selection = getUserInput("Please enter your choice here: ");

		switch (selection)
		{
		case (1):
			newAppt = createAppt();
			addNewAppt(apptList, copyNewAppt(newAppt), &size);
			break;
		case (2):
			deleteExistingAppt(apptList, &size);
			break;
		case (3):
			updateExistingAppt(apptList, &size);
			continue;
		case (4):
			displaySingleAppt(apptList,&size);
			continue;
		//case ('5'):
		//	displayRangeAppt();
		//	continue;

		//case ('6'):

		//	displayAllAppt();
		//	continue;
		case (7):
			searchForAppt(apptList,&size);
			continue;	
		case (6):
			displayAllAppt(apptList, &size);
			continue;
		case (8):
			repeat = false;
			break;
		default:
			puts("Invalid input! Please try again\n");
			break;
		}
	}
	puts("\nThank you for using our appointment app!\n");
	disposeAppt(apptList,&size);

	return 0;
}


	

