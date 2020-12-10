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
	char *fileName;
	int size = 0; 

	fileName = askForFileName();

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
			puts("Invalid input! Please try again\n");
			break;
		}
	}

	//saveDataToDisk(apptList, fileName);
	//fclose(fp);
	/*if (saveDataToDisk(apptList, fileName))
		printf("Appointments are updated to file\n");
	else
		printf("Error saving data to file\n");
		
	puts("\nThank you for using our appointment app!\n");
	*/
	disposeAppt(apptList,&size);

	return 0;
}


	

