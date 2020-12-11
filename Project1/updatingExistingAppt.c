#include <stdio.h>
#include <stdbool.h>
#include "Features.h"

void updateExistingAppt(PAPPOINTMENT apptList[], int* size, PAPPOINTMENT appt)
{
	char name_Update[MAXNAME];
	char location_Update[MAXNAME];
	char body_Update[MAXBODY];
	int input;
	char scannedInput;

	bool repeat;

	if (*size == 0)
	{
		printf("There are no appointments in the list.");
		return;
	}
	do
	{
		input = getUserInput("Enter the number of the appointment you wish to update: ");

		if (input >= 0 && input < *size)
		{
			repeat = false;
			int choice;
			printf("What would you like to update:\n");						// prompts a menu for user to choose what they would
			printf("1) Appointment name\n2) Location\n3) Description\n");	// like to change in their appointment
			printf("4) Time\n");
			choice = getUserInput("Enter here: ");

			switch (choice) {														
			case(1):
				printf("Previous appointment name: %s\n", apptList[input]->apptName);	// update appointment name 
				printf("Enter a new appointment name to change previous one: ");		
				fgets(name_Update, MAXNAME,stdin);
				strncpy(apptList[input]->apptName, name_Update, MAXNAME);
				printf("Appointment name updated.\n");
				break;
			case(2):
				printf("Previous location: %s\n", apptList[input]->location);	// update location
				printf("Enter a new location to change previous one: ");
				fgets(location_Update,MAXNAME,stdin);
				strncpy(apptList[input]->location, location_Update, MAXNAME);
				printf("Location updated.\n");
				break;
			case(3):
				printf("Previous description: %s\n", apptList[input]->body);	// update description 
				printf("Enter a new description to change previous one: ");
				fgets(body_Update,MAXNAME,stdin);
				strncpy(apptList[input]->body, body_Update, MAXBODY);
				printf("Description updated.\n");
				break;
			case(4):
				do {
					printf("Previous Starting time: %d:%d\n", apptList[input]->startHour, apptList[input]->startMinutes);	//update time
					printf("Enter a new starting time to change previous one.\n");
					printf("Enter starting time:\n");
					apptList[input]->startHour = inputTime(0, 23);
					apptList[input]->startMinutes = inputTime(0, 59);
					printf("Previous Ending time: %d:%d\n", apptList[input]->endHour, apptList[input]->endMinutes);
					printf("Enter a new ending time to change previous one.\n");
					printf("Enter ending time:\n");
					apptList[input]->endHour = inputTime(0, 23);
					apptList[input]->endMinutes = inputTime(0, 59);
				} while ((appt->startHour) > (apptList[input]->startHour) && (appt->startHour) < (apptList[input]->endHour) ||
					(appt->endHour) < (apptList[input]->endHour) && (appt->endHour) > (apptList[input]->startHour) ||
					(appt->startHour) == (apptList[input]->endHour) && (appt->startMinutes) < (apptList[input]->endMinutes) ||
					(appt->endHour) == (apptList[input]->startHour) && (appt->endMinutes) > (apptList[input]->startMinutes));
		
					printf("Time updated.\n");
					break;
			}
		}
		else
		{
			printf("There is no appointment at %d\n", input);
			repeat = true;
		}
	} while (repeat);

}