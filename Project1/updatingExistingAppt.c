#include <stdio.h>
#include <stdbool.h>
#include "Features.h"

void updateExistingAppt(PAPPOINTMENT apptList[], int* size)
{
	char ApptName[MAXNAME];
	char name_Update[MAXNAME];
	char location_Update[MAXNAME];
	char body_Update[MAXBODY];

	printf("Enter the name of the appointment you wish to update: ");
	(void)scanf_s("%s", &ApptName);
	for (int i = 0; i < size; i++)
	{
		if (strcmp(ApptName, apptList[i]->apptName) == 0) {
			int choice = 0;
			printf("What would you like to update:\n");
			printf("1) Appointment name\n2) Location\n3) Description\n");
			printf("4) Starting time\n 5) Ending Time\n");
			gets(choice);

			switch (choice) {
			case(1):
				printf("Previous appointment name: %s", apptList[i]->apptName);
				printf("Enter a new appointment name to change previous one: ");
				gets(name_Update);
				strncpy(apptList[i]->apptName, name_Update);
				printf("Appoitment name updated.\n");
				break;
			case(2):
				printf("Previous location: %s", apptList[i]->location);
				printf("Enter a new location to change previous one: ");
				gets(location_Update);
				strncpy(apptList[i]->location, location_Update);
				printf("Location updated.\n");
				break;
			case(3):
				printf("Previous description: %s", apptList[i]->body);
				printf("Enter a new description to change previous one: ");
				gets(body_Update);
				strncpy(apptList[i]->body, body_Update);
				printf("Description updated.\n");
				break;
			case(4):
				printf("Previous Starting time: %d:%d", apptList[i]->startHour, apptList[i]->startMinutes);
				printf("Enter a new starting time to change previous one.\n");
				printf("Enter starting time:");
				apptList[i]->startHour = inputTime(0, 23);
				apptList[i]->startMinutes = inputTime(0, 59);
				printf("Starting time updated.\n");
				break;
			case(5):
				printf("Previous Ending time: %d:%d", apptList[i]->endHour, apptList[i]->endMinutes);
				printf("Enter a new ending time to change previous one.\n");
				printf("Enter ending time:");
				apptList[i]->endHour = inputTime(0, 23);
				apptList[i]->endMinutes = inputTime(0, 59);
				printf("Ending time updated.\n");
				break;
			}
		}
	}
}