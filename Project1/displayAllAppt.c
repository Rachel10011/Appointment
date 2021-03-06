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

void displayAllAppt(PAPPOINTMENT apptList[], int* size)
{
	if (*size == 0)
	{
		printf("No appointment today\n");
		return;
	}

	printf("The List of all appointments: \n");
	for (int i = 0; i < *size; i++)
	{
		printf("[%d] %d/%d/%d\n", i, apptList[i]->month, apptList[i]->day, apptList[i]->year);
		printf("	%d:%d-%d:%d\n", apptList[i]->startHour, apptList[i]->startMinutes, apptList[i]->endHour, apptList[i]->endMinutes);
		printf("	Name: %s\n", apptList[i]->apptName);
		printf("	Location: %s\n", apptList[i]->location);
		printf("	Description: %s\n", apptList[i]->body);
	}

}