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