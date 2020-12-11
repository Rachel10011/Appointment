#include <stdio.h>
#include <stdbool.h>
#include "Features.h"

void displaySingleAppt(PAPPOINTMENT apptList[], int* size) {

	char ApptName[MAXNAME];

	if (*size != 0) {
		bool repeat = true;
		do
		{
			int input = getUserInput("Enter the number of the appointment you wish to display: ");
			if (input >= 0 && input < size) {
				printf("[%d]\t%d:%d-%d:%d\n", input, apptList[input]->startHour, apptList[input]->startMinutes, apptList[input]->endHour, apptList[input]->endMinutes);
				printf("    \tName: %s\n", apptList[input]->apptName);
				printf("    \tLocation: %s\n", apptList[input]->location);
				printf("    \tDescription: %s\n", apptList[input]->body);
				repeat = false;
			}
			else
			{
				printf("There is no appointment at %d\n", input);
			}
				printf("");
		} while (repeat);
	}
	else {
		printf("There are no appointments to display.");
	}
}
