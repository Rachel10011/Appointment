//PROG71985F20 - Group Assignment
//Fall 2020
//Group members:
	//Thi Huong Tra Le
	//Dominic Pham
	//Le Minh Nguyen

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
		scannedInput = scanf("%d", &input);
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
	char name[MAXNAME];
	char location[MAXNAME];
	char body[MAXBODY];

	do
	{
		puts("Enter starting time:");
		newAppt.startHour = inputTime(0, 23);		//ask user to enter the hour of the appointment 
		newAppt.startMinutes = inputTime(0, 59);	//ask for minutes
		puts("Enter ending time:");
		newAppt.endHour = inputTime(0, 23);
		newAppt.endMinutes = inputTime(0, 59);
	} while (newAppt.startHour > newAppt.endHour || (newAppt.startHour == newAppt.endHour && newAppt.startMinutes > newAppt.endMinutes));

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
	scanf("%s", &temp);

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

char askForFileName()
{
	char fileName[MAX_FILENAME];
	puts("Please enter name of a file to read/write data: ");
	scanf("%s", &fileName);
	getchar();
	return fileName;
}

void saveDataToDisk(APPOINTMENT apptList[], char fileName[])
{
	FILE* fp = fopen(fileName, "w+");
	
	for (int i = 0; i < size(apptList) / sizeof(APPOINTMENT); i++)
	{
		fprintf(fp, "%d:%d to %d:%d\n", apptList[i].startHour, apptList[i].startMinutes, apptList[i].endHour, apptList[i].endMinutes);
		fprintf(fp, "%s\n%s\%s\n\n", apptList[i].apptName, apptList[i].location, apptList[i].body);

	}
	fclose(fp);
	printf("\nData is updated to file successfully.\n");
}