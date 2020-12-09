#include <stdio.h>
#include <stdbool.h>
#include "Features.h"

void searchForAppt(PAPPOINTMENT apptList[], int*size) {

	char ApptName[MAXNAME];
	printf("Enter the name of the appointment you wish to search in the list: ");
	(void)scanf("%s", &ApptName);
	
	for (int i = 0; i < size; i++)
	{
		if (strcmp(ApptName, apptList[i]->apptName) == 0) {
			printf("Appointment exists in the list.\n");
			return;
		}
	}
	printf("The appointment you wish to search does not exist in list.\n");
	return;
}