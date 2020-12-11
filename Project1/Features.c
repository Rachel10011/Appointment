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
			printf("Only numebr is accepted. Try again.\n");
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
		printf("Please enter a number between %d and %d: ", min, max);
		fgets(buffer, MAXTIME, stdin);
		time = atoi(buffer);										 //conert char to int
		if (time<min || time>max)
			puts("Invalid input! Please try again.");
	} while (time<min || time>max);									//if the user's input is not inthe range of time, ask for another input

	return time;		
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
	fgets(name,MAXNAME,stdin);
	printf("Enter location: ");
	fgets(location, MAXNAME, stdin);
	printf("Enter appointment's description: ");
	fgets(body, MAXBODY, stdin);

	newAppt.apptName = (char*)malloc(strlen(name)+1);
	newAppt.location = (char*)malloc(strlen(location)+1);
	newAppt.body = (char*)malloc(strlen(body)+1);

	if (!newAppt.apptName || !newAppt.location || !newAppt.body)
	{
		fprintf(stderr, "Error allocating memory!\n");
		exit(1);
	}

	strncpy(newAppt.apptName,name, strlen(name)+1);
	strncpy(newAppt.location, location, strlen(location)+1);
	strncpy(newAppt.body, body, strlen(body)+1);

	newAppt.apptName[strlen(name)] = '\0';
	newAppt.location[strlen(location)] = '\0';
	newAppt.body[strlen(body)] = '\0';

	return newAppt;
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


void addNewAppt(PAPPOINTMENT apptList[], PAPPOINTMENT appt, int* size)
{
	for (int i = 0; i < (*size); i++)
	{
		if ((appt->startHour)> (apptList[i]->startHour) && (appt->startHour)<(apptList[i]->endHour) ||
			(appt->endHour)<(apptList[i]->endHour) && (appt->endHour)>(apptList[i]->startHour) ||
			(appt->startHour) == (apptList[i]->endHour)&&(appt->startMinutes)<(apptList[i]->endMinutes)||
			(appt->endHour)==(apptList[i]->startHour)&& (appt->endMinutes) >(apptList[i]->startMinutes))
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
		printf("No appointment today");
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
	int j;

	if (*size == NULL)
	{
		printf("No appointment today\n");
		return;
	}

	printf("This is all appointment for today\n");
	for (int i = 0; i < *size; i++)
	{
		printf( "%d:%d - %d:%d \nName: %s\nLocation: %s\nInformation:%s\n\n", apptList[i]->startHour, apptList[i]->startMinutes, apptList[i]->endHour, apptList[i]->endMinutes, apptList[i]->apptName, apptList[i]->location, apptList[i]->body);
		j = getUserInput("Enter the number of the appointment you want to check the range: ");
		//scanf_s("%d", &j);
		if (j >= *size)
		{
			printf("There is no appointmetn at %d\n", j);
			return;
		}

		int rangemin, rangehour;
		rangemin = apptList[j]->endMinutes - apptList[j]->startMinutes;
		if (rangemin < 0)
		{
			int endhour = apptList[j]->endHour - 1;
			int endminute = apptList[j]->endMinutes + 60;
			int rangeMin = endminute - apptList[j]->startMinutes;
			rangehour = endhour - apptList[j]->startHour;
			if (rangehour < 0)
			{
				printf("Invalid Appointment");
			}
			else
			{
				printf("The range of the appointment: %d:%d", rangehour, rangeMin);
			}
			return;
		}
		rangehour = apptList[j]->endHour - apptList[j]->startHour;
		printf("The range of the appointment: %d:%d", rangehour, rangemin);
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
	
	//if(*size == 0)

	FILE* fp;
	turnback:
	printf("Enter name of a file you wish to load:\n");
	gets(file_Name);
	if ((fp = fopen(file_Name, "r")) == NULL)
	{
		char selection;
		printf("\nEnterd file is empty.\n");
		turnback1:
		puts("*--------------------------------*");
		puts("|   Do you Want to input again   |");
		puts("|   1. Input again               |");
		puts("|   2. Exit to the menu          |");
		puts("*--------------------------------*");
		selection = getUserInput("Please enter your choice here: ");
		switch (selection)
		{
		case (1):
			goto turnback;
			break;
		case (2):
			break;
		default:
			puts("Invalid input! Please try again\n");
			goto turnback1;
			break;
		}
	}
	else 
	{
		for (int i = 0; i < *size; i++) 
		{
			fgets("%d%d%d%d%s%s%s", &apptList[i]->startHour, &apptList[i]->startMinutes, &apptList[i]->endHour, &apptList[i]->endMinutes, apptList[i]->apptName, apptList[i]->location, apptList[i]->body,fp);
			printf("Here is the Data in your file\n");
			printf("%d:%d - %d:%d \nName: %s\nLocation: %s\nInformation:%s\n\n", apptList[i]->startHour, apptList[i]->startMinutes, apptList[i]->endHour, apptList[i]->endMinutes, apptList[i]->apptName, apptList[i]->location, apptList[i]->body);
		}
		fclose(fp);
		printf("\nLoad Data From File Successfully\n");
	}
}