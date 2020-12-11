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
#include <conio.h>
#include <stdlib.h>
void loadDataFromDisk(PAPPOINTMENT apptList[], int* size, char file_Name[])
{
	FILE* fp;
	PAPPOINTMENT appointment[] = { 0 };
	fp = fopen(file_Name, "r");
	if (fp == NULL)
	{
		printf("There is no data to load\n");
		exit(1);
	}
	else
	{
		for (int i = 0; i <= *size; i++)
		{
			fscanf(fp, "%d:%d - %d:%d \nName: %s\nLocation: %s\nInformation:%s\n\n", &appointment[i]->startHour, &appointment[i]->startMinutes, &appointment[i]->endHour, &appointment[i]->endMinutes, appointment[i]->apptName, appointment[i]->location, appointment[i]->body);
			apptList[i] = appointment[i];
		}
		fclose(fp);
		printf("\nLoad Data From File Successfully\n");
	}
}