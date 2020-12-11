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

void printIntro()
{
	printf("**********************************************\n");
	printf("*     Welcome to our appointment system      *\n");
	printf("**********************************************\n\n");
}

void menu(void)
{
	puts("*----------------------------------------------*");
	puts("|To choose a function, enter its letter label: |");
	puts("|   1) Add a new appointment                   |");
	puts("|   2) Delete an existing appointment          |");
	puts("|   3) Update an appointment                   |");
	puts("|   4) Display an appointment                  |");
	puts("|   5) Display the range appointment           |");
	puts("|   6) Display all appointment                 |");
	puts("|   7) Search for appointment                  |");
	puts("|   8) Save appointment to file                |");
	puts("|   9) Load appointment from file              |");
	puts("|  10) Quit                                    |");
	puts("*----------------------------------------------*");

}

int getUserInput(char message[])
{
	int input;
	char scannedInput;
	do
	{
		printf("%s", message);
		scannedInput = scanf_s("%d", &input);
		char buf;
		while ((buf = getchar()) != '\n' && input != EOF);
		if (scannedInput != 1)
		{
			printf("Only numebr is accepted. Try again\n");
			printf("%s", message);
		}

	}while (scannedInput != 1);

	return input;
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
	appt->apptName= NULL;
	appt->body= NULL;
	appt->location= NULL;
	return appt;
}

int inputTime(int min, int max)
{
	int time = 0;
	char buffer[MAXTIME];

	do {
		printf("Please enter a number between %d and %d:", min, max);
		time = getUserInput("");
		if (time<min || time>max)
			puts("Invalid input! Please try again.");
	} while (time<min || time>max);									//if the user's input is not inthe range of time, ask for another input

	return time;		
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
		for (int j = i+1; j < size; j++)
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

void deleteExistingAppt(PAPPOINTMENT list[], int* size)			//We will delete appt by asking user to enter the index(number) of that appt. The numbers will be printed on the screen beside the appointments 
{
	if (*size == 0)
	{
		puts("There is no appointment!\n");
		return;
	}

	/*puts("List of current appointment: ");
	print the current list appoinment so the user can choose easiser
	*/

	displayAllAppt(list, size);

	char temp[MAXAPPT];
	int num;
	num = getUserInput("Enter appointment's number that you want to delete:");
	if (num >= *size)
	{
		printf("There is no appointment at %d\n", num);
		return;
	}

	//make the values of satrting hours large so when sort the list, this appt will go to the end of the list
	list[num]->startHour = 100;
	list[num]->startMinutes = 100;

	if (num < *size)
	{
		sortAppt(list, *size);
	}

	(*size)--;

	printf("\nDeleting appointment %d completed\n\n", num);
}

void displayAllAppt(PAPPOINTMENT apptList[], int* size)
{
	if (*size == 0)
	{
		printf("No appointment today\n");
		return;
	}

	printf("The List of all appointment today: \n");
	for (int i = 0; i < *size; i++)
	{
		printf("%d:%d - %d:%d\nName: %s\nLocation: %s\nInformation: %s\n\n", apptList[i]->startHour, apptList[i]->startMinutes, apptList[i]->endHour, apptList[i]->endMinutes, apptList[i]->apptName, apptList[i]->location, apptList[i]->body);
	}

}

void displayRangeAppt(PAPPOINTMENT apptList[], int* size)

{
	if (*size == NULL)
		return;
	
	displayAllAppt(apptList, size);

	for (int i = 0; i < *size; i++)
	{

		int range_min, range_hour;
		
		i=getUserInput("Enter the number of the appointment you want to check the range:");

		range_min = apptList[i]->endMinutes - apptList[i]->startMinutes;
		
		if (range_min < 0)
		{
			int endhour = apptList[i]->endHour - 1;
			int endminute = apptList[i]->endMinutes + 60;
			int rangeMin = endminute - apptList[i]->startMinutes;
			range_hour = endhour - apptList[i]->startHour;
			if (range_hour < 0)
			{
				printf("Invalid Appointment");
			}
			else
			{
				printf("The range of the appointment : %d:%d", range_hour, rangeMin);
			}
			return;
		}
		else
			range_hour = apptList[i]->endHour - apptList[i]->startHour;

		printf("The range of the appointment %d:%d-%d:%d is %d:%d", apptList[i]->startHour, apptList[i]->startMinutes, apptList[i]->endHour, apptList[i]->endMinutes,range_hour, range_min);
		return;
	}

}

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

void saveDataToDisk(PAPPOINTMENT apptList[], int*size, char fileName[])
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
			fprintf(fp, "%d:%d - %d:%d \nName: %s\nLocation: %s\nInformation:%s\n\n", apptList[i]->startHour, apptList[i]->startMinutes, apptList[i]->endHour, apptList[i]->endMinutes, apptList[i]->apptName, apptList[i]->location, apptList[i]->body);
		}

		fclose(fp);
		printf("\nAppointments are updated to file successfully\n");
	}
}

void loadDataFromDisk(PAPPOINTMENT apptList[], int* size, char file_Name[])
{
	FILE* fp;
	if ( fopen(file_Name, "r") == NULL)
	{
		printf("There is no data to load\n");
		return;
	}
	else
	{
		fp = fopen(file_Name, "r");
		for (int i = 0; i <= *size; i++)
		{
			PAPPOINTMENT appointment = { 0 };
			fscanf(fp, "%d:%d - %d:%d \nName: %s\nLocation: %s\nInformation:%s\n\n", &appointment->startHour, &appointment->startMinutes,&appointment->endHour, &appointment->endMinutes, appointment->apptName, appointment->location, appointment->body);
			apptList[i] = appointment;
		}

		fclose(fp);
		printf("\nLoad Data From File Successfully\n");
	}
}
