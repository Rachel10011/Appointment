#include <stdio.h>
#include <stdbool.h>
#include "Features.h"

void searchForAppt(PAPPOINTMENT apptList[], int*size) {

	char search_Name[MAXNAME];

	printf("Enter the name of the appointment you wish to search in the list: ");
	gets(search_Name);

	for (int i = 0; i < size; i++)
	{
		if (strcmp(search_Name, apptList[i]->apptName) == 0)	//searches for appointment name in list
		{
			printf("Appointment exists in the list.\n");
			return;
		}
	}
	printf("The appointment you wish to search does not exist in list.\n");
	return;
}