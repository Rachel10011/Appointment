#include <stdio.h>
#include <stdbool.h>
#include "Features.h"

void displaySingleAppt(PAPPOINTMENT apptList[], int* size) {

	char ApptName[MAXNAME];
	printf("Enter the name of the appointment you wish to display: ");
	(void)scanf_s("%s", &ApptName);

	for (int i = 0; i < size; i++)
	{
		if (strcmp(ApptName, apptList[i]->apptName) == 0) {
			printf("Appointment name: %s\n", apptList[i]->apptName);
			printf("Location: %s\n", apptList[i]->location);
			printf("Starts at %d:%d\n", apptList[i]->startHour, apptList[i]->startMinutes);
			printf("Ends at %d:%d\n", apptList[i]->endHour, apptList[i]->endMinutes);
			printf("Description: %s\n", apptList[i]->body);
		}
	}
}/* Minh Le: I think you should check the apptlist if it NULL before the for loop 
 And you should display all the appt to the user to choose cuz they maybe forget thier name appointment
 */
