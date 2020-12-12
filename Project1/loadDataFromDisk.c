//PROG71985F20 - Group Assignment
//Fall 2020
//Group members:
	//Thi Huong Tra Le
	//Dominic Pham
	//Le Minh Nguyen
#define _CRT_SECURE_NO_WARNINGS

#include"Features.h"
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
						APPOINTMENT appointment = { 0 };
					int start_hours = 0;
					int start_minutes = 0;
					int end_hour = 0;
					int end_minutes = 0;
					char name[MAXNAME];
					char location[MAXNAME];
					char body[MAXBODY];
					char* token;
					//			fscanf(fp, "%d:%d - %d:%d \nName: %s\nLocation: %s\nInformation:%s\n\n", start_hours, start_minutes, end_hour, end_minutes, name, location, body); //&appointment.startHour, &appointment.startMinutes, &appointment.endHour, &appointment.endMinutes, appointment.apptName, appointment.location, appointment.body);

					fscanf(fp, "%d %d %d %d %s %s %s", &appointment.startHour, &appointment.startMinutes, &appointment.endHour, &appointment.endMinutes, appointment.apptName, appointment.location, appointment.body);

					apptList[i]->startHour = appointment.startHour;
					apptList[i]->startMinutes = appointment.startMinutes;
					apptList[i]->endHour = appointment.endHour;
					apptList[i]->endMinutes =appointment.endMinutes;
					strncpy(apptList[i]->apptName, appointment.apptName, MAXNAME);
					strncpy(apptList[i]->location, appointment.location, MAXNAME);
					strncpy(apptList[i]->body, appointment.body, MAXBODY);
						

				//	fscanf(fp, "%d:%d - %d:%d \nName: %s\nLocation: %s\nInformation:%s\n\n", &appointment[i]->startHour, &appointment[i]->startMinutes, &appointment[i]->endHour, &appointment[i]->endMinutes, appointment[i]->apptName, appointment[i]->location, appointment[i]->body);
					//apptList[i] = appointment[i];
				}
				fclose(fp);
				printf("\nLoad Data From File Successfully\n");
			}
	}