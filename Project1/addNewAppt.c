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