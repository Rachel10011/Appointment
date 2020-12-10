//PROG71985F20 - Group Assignment
//Fall 2020
//Group members:
	//Thi Huong Tra Le
	//Dominic Pham
	//Le Minh Nguyen

#include <stdio.h>
#include <stdbool.h>
#include "Features.h"

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
	puts("|   8) Quit                                    |");
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
	char name[20];
	char location[20];
	char body[100];
	bool repeat = true;

	do
	{
		puts("Starting time:");
		newAppt.startHour = inputTime(0, 23);		//ask user to enter the hour of the appointment 
		newAppt.startMinutes = inputTime(0, 59);	//ask for minutes
		puts("Ending time:");
		newAppt.endHour = inputTime(0, 23);
		newAppt.endMinutes = inputTime(0, 59);
		if ((newAppt.startHour > newAppt.endHour || (newAppt.startHour == newAppt.endHour && newAppt.startMinutes > newAppt.endMinutes)))
			printf("\nStarting time must be smaller than ending time. Please enter again.\n");
		else
			repeat = false;

	} while (repeat);

	puts("Enter appoinments name: ");
	gets(name);
	puts("Enter location: ");
	gets(location);
	puts("Enter appointment's description: ");
	gets(body); 

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
		fprintf(stderr, "Error allocating memory");
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
	puts("New appointment is added successfully!");

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

	char temp[MAXAPPT];
	puts("Enter appointment's number that you want to delete:");
	scanf_s("%s", &temp);

	int num = atoi(temp);
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

	printf("Deleting appointment %d completed", num);
}

void displayAllAppt(PAPPOINTMENT apptList[], int* size)
{
	printf("The List of all appointment today\n");
	if(*size == 0)
	{
		printf("No appointment today");
		return;
	}
	for (int i = 0; i < *size; i++)
	{
		printf("Start\tEnd\t Name\t Location\t Note");
		printf("\n%d:%d  %d:%d  %s  %s  %s\n", apptList[i]->startHour, apptList[i]->startMinutes, apptList[i]->endHour, apptList[i]->endMinutes, apptList[i]->apptName, apptList[i]->location, apptList[i]->body);
	}
}

void displayRangeAppt(PAPPOINTMENT apptList[], int* size)
{
	int j;
	printf("This is all appointment for today");
	if (apptList == NULL)
	{
		printf("No appointment today");
	}
	while (apptList != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			printf("%s      %s      %s        %s        %s\n", "Start", "End", "Name", "Location", "Note");
			printf("%d:%d  %d:%d  %s  %s  %s\n", apptList[i]->startHour, apptList[i]->startMinutes, apptList[i]->endHour, apptList[i]->endMinutes,MAXNAME, apptList[i]->apptName,MAXNAME, apptList[i]->location,MAXNAME, apptList[i]->body); 
			/* Minh Le: Can u fix it for me the code printf and also in line 280*/
			printf("Enter the number of the appointment you want to check the range:");
			scanf_s("%d", &j);
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
					printf("The range of the appointment : %d:%d", rangehour, rangeMin);
				}
			}
			rangehour = apptList[j]->endHour - apptList[j]->startHour;
			printf("The range of the appointment : %d:%d", rangehour, rangemin);
		}
	}

	
	
}