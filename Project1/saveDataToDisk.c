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

void saveDataToDisk(PAPPOINTMENT apptList[], int* size, char fileName[])
{
	if (*size == 0)
	{
		printf("There is no appointment to save to data.\n");
	}
	else
	{
		FILE* fp;
		fp = fopen(fileName, "w+");

		for (int i = 0; i < *size; i++)
		{
			fprintf(fp,"[%d]\t%d/%d/%d\n", i, apptList[i]->month, apptList[i]->day, apptList[i]->year);
			fprintf(fp, "%d:%d - %d:%d\nName: %s\nLocation: %s\nInformation:%s\n\n", apptList[i]->startHour, apptList[i]->startMinutes, apptList[i]->endHour, apptList[i]->endMinutes, apptList[i]->apptName, apptList[i]->location, apptList[i]->body);
		}

		fclose(fp);
		printf("\nAppointments are updated to file successfully\n");
	}

}