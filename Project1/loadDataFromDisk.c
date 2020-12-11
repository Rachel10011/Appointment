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

void loadDataFromDisk(PAPPOINTMENT apptList[], int* size, char file_Name[])
{
	FILE* fp;
	fp = fopen(file_Name, "rt");
	if (fp == NULL)
	{
		printf("There is no data to load\n");
		return;
	}
	else
	{
		for (int i = 0; i <= *size; i++)
		{
			PAPPOINTMENT appointment = { 0 };
			scanf(fp, "%d:%d - %d:%d \nName: %s\nLocation: %s\nInformation:%s\n\n", &appointment->startHour, &appointment->startMinutes, &appointment->endHour, &appointment->endMinutes, appointment->apptName, appointment->location, appointment->body);
			apptList[i] = appointment;
		}
		fclose(fp);
		printf("\nLoad Data From File Successfully\n");
	}
}