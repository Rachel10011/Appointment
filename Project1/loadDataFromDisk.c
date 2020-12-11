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

void askForFilePath(char fileName[])
{
	FILE* fp;
	bool repeat;
	do
	{
		printf("Please enter a full path of the file you want to access/create: ");
		scanf("%s", fileName);
		getchar();

		if (!fopen(fileName, "r+"))
		{
			printf("Entered file name is unaccepted. Please try again.\n");
			repeat = true;
		}
		else
			repeat = false;
	} while (repeat);

}
void loadDataFromDisk(PAPPOINTMENT apptList[], int* size, char file_Name[])
{
	FILE* fp;
	
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
			APPOINTMENT appointment = { 0 };
			int start_hours=0;
			int start_minutes=0;
			int end_hour=0;
			int end_minutes=0;
			char name[MAXNAME];
			char location[MAXNAME];
			char body[MAXBODY];
			char* token;
//			fscanf(fp, "%d:%d - %d:%d \nName: %s\nLocation: %s\nInformation:%s\n\n", start_hours, start_minutes, end_hour, end_minutes, name, location, body); //&appointment.startHour, &appointment.startMinutes, &appointment.endHour, &appointment.endMinutes, appointment.apptName, appointment.location, appointment.body);
	
			fscanf(fp, "%d %d %d %d %s %s %s", start_hours, start_minutes, end_hour, end_minutes, name, location, body); //&appointment.startHour, &appointment.startMinutes, &appointment.endHour, &appointment.endMinutes, appointment.apptName, appointment.location, appointment.body);

			apptList[i]->startHour = start_hours;// appointment.startHour;
			apptList[i]->startMinutes = start_minutes;//appointment.startMinutes;
			apptList[i]->endHour = end_hour;//appointment.endHour;
			apptList[i]->endMinutes = end_minutes;//appointment.endMinutes;
			strncpy(apptList[i]->apptName, name, MAXNAME);
			strncpy(apptList[i]->location, location, MAXNAME);
			strncpy(apptList[i]->body, body, MAXBODY);
		}
		fclose(fp);
		printf("\nLoad Data From File Successfully\n");
	}
}