#include <stdio.h>
#include <stdbool.h>
#include "Features.h"

void displaySingleAppt(PAPPOINTMENT apptList[], int* size) {

	char ApptName[MAXNAME];

	displayAllAppt(apptList, size);
	if (*size != 0) {
		bool repeat = true;
		do
		{
			int input = getUserInput("Enter the number of the appointment you wish to display: ");	// searches through list for the index number of 
			if (input >= 0 && input < size) {													    // the appointment the user wishes to display
				printf("[%d]\t%d/%d/%d\n", input, apptList[input]->month, apptList[input]->day, apptList[input]->year);
				printf("    \t%d:%d-%d:%d\n", input, apptList[input]->startHour, apptList[input]->startMinutes, apptList[input]->endHour, apptList[input]->endMinutes);
				printf("    \tName: %s\n", apptList[input]->apptName);
				printf("    \tLocation: %s\n", apptList[input]->location);
				printf("    \tDescription: %s\n", apptList[input]->body);
				repeat = false;
			}
			else
			{
				printf("There is no appointment at %d\n", input); //prints when there is no existing appointment at given index
			}
				printf("");
		} while (repeat);
	}
	else {
		printf("There are no appointments to display.\n");	// prints when there are no appointments in the list 
	}
}
