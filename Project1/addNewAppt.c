//PROG71985F20 - Group Assignment
//Fall 2020
//Group members:
	//Thi Huong Tra Le
	//Dominic Pham
	//Le Minh Nguyen
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include "Features.h"

void addNewAppt(PAPPOINTMENT apptList[], PAPPOINTMENT appt, int* size)
{
	for (int i = 0; i < (*size); i++)
	{
		if ((appt->startHour) > (apptList[i]->startHour) && (appt->startHour) < (apptList[i]->endHour) ||
			(appt->endHour) < (apptList[i]->endHour) && (appt->endHour) > (apptList[i]->startHour) ||
			(appt->startHour) == (apptList[i]->endHour) && (appt->startMinutes) < (apptList[i]->endMinutes) ||
			(appt->endHour) == (apptList[i]->startHour) && (appt->endMinutes) > (apptList[i]->startMinutes))
		{
			printf("\nCannot book. Overlap time range!\n\n");
			return;
		}

	}

	addApptToList(apptList, appt, *size);
	(*size)++;
	sortAppt(apptList, *size);
	puts("\nNew appointment is added successfully!\n");

}

APPOINTMENT createAppt()
{
	APPOINTMENT newAppt;
	char name[MAXNAME];
	char location[MAXNAME];
	char body[MAXBODY];
	bool repeat;

	puts("\nTo book time for your appointment. Please follow the instruction below.\nYou will need to enter hour and minutes separately.\nNote: Please enter 24-hour clock.\n");

	do
	{
		puts("Starting time:");
		newAppt.startHour = inputTime(0, 23);		//ask user to enter the hour of the appointment 
		newAppt.startMinutes = inputTime(0, 59);	//ask for minutes
		puts("Ending time:");
		newAppt.endHour = inputTime(0, 23);
		newAppt.endMinutes = inputTime(0, 59);
		if ((newAppt.startHour > newAppt.endHour || (newAppt.startHour == newAppt.endHour && newAppt.startMinutes > newAppt.endMinutes)))
		{
			printf("\nStarting time must be smaller than ending time. Please enter again.\n\n");
			repeat = true;
		}
		else
			repeat = false;

	} while (repeat);

	printf("Enter appoinments name: ");
	fgets(name, MAXNAME, stdin);
	printf("Enter location: ");
	fgets(location, MAXNAME, stdin);
	printf("Enter appointment's description: ");
	fgets(body, MAXBODY, stdin);

	newAppt.apptName = (char*)malloc(strlen(name) + 1);
	newAppt.location = (char*)malloc(strlen(location) + 1);
	newAppt.body = (char*)malloc(strlen(body) + 1);

	if (!newAppt.apptName || !newAppt.location || !newAppt.body)
	{
		fprintf(stderr, "Error allocating memory!\n");
		exit(1);
	}

	strncpy(newAppt.apptName, name, strlen(name) + 1);
	strncpy(newAppt.location, location, strlen(location) + 1);
	strncpy(newAppt.body, body, strlen(body) + 1);

	newAppt.apptName[strlen(name)] = '\0';
	newAppt.location[strlen(location)] = '\0';
	newAppt.body[strlen(body)] = '\0';

	return newAppt;
}

bool isNull(PAPPOINTMENT appt)
{
	return appt == NULL;		//return true if appt is null, otherwise return false
}

PAPPOINTMENT initialAppointment()
{
	PAPPOINTMENT appt = (PAPPOINTMENT)malloc(sizeof(APPOINTMENT));
	if (!appt)
	{
		fprintf(stderr, "Error allocating memory!\n");
	}
	appt->startHour = 0;
	appt->startMinutes = 0;
	appt->endMinutes = 0;
	appt->endHour = 0;
	appt->apptName = NULL;
	appt->body = NULL;
	appt->location = NULL;
	return appt;
}

PAPPOINTMENT copyNewAppt(APPOINTMENT newAppt)
{
	PAPPOINTMENT pCopyAppt = (PAPPOINTMENT)malloc(sizeof(APPOINTMENT));
	if (!pCopyAppt)
	{
		fprintf(stderr, "Error allocating memory!\n");
		exit(1);
	}

	pCopyAppt->apptName = (char*)malloc(strlen(newAppt.apptName) + 1);
	pCopyAppt->location = (char*)malloc(strlen(newAppt.location) + 1);
	pCopyAppt->body = (char*)malloc(strlen(newAppt.body) + 1);

	if (!pCopyAppt->apptName || !pCopyAppt->location || !pCopyAppt->body)
	{
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}

	memset(pCopyAppt->apptName, 0, strlen(newAppt.apptName) + 1);
	strncpy(pCopyAppt->apptName, newAppt.apptName, strlen(newAppt.apptName));

	memset(pCopyAppt->location, 0, strlen(newAppt.location) + 1);
	strncpy(pCopyAppt->location, newAppt.location, strlen(newAppt.location));

	memset(pCopyAppt->body, 0, strlen(newAppt.body) + 1);
	strncpy(pCopyAppt->body, newAppt.body, strlen(newAppt.body));

	pCopyAppt->startHour = newAppt.startHour;
	pCopyAppt->startMinutes = newAppt.startMinutes;
	pCopyAppt->endHour = newAppt.endHour;
	pCopyAppt->endMinutes = newAppt.endMinutes;

	return pCopyAppt;

}
void addApptToList(PAPPOINTMENT apptList[], PAPPOINTMENT appt, int index)
{
	if (isNull(appt))
		return;

	apptList[index] = appt;

}

void sortAppt(PAPPOINTMENT apptList[], int size)
{
	if (size = 0)
		return;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			PAPPOINTMENT temp;

			if (apptList[i]->startHour > apptList[j]->startHour ||
				apptList[i]->startHour == apptList[j]->startHour &&
				apptList[i]->startMinutes > apptList[j]->startMinutes)
			{
				temp = apptList[i];
				apptList[i] = apptList[j];
				apptList[j] = temp;
			}

		}
	}
}

void disposeAppt(PAPPOINTMENT appt[], int* size)
{
	if ((*size) = 0)
		return;

	for (int i = 0; i < *size; i++)
	{
		free(appt[i]->apptName);
		free(appt[i]->location);
		free(appt[i]->location);
	}
}