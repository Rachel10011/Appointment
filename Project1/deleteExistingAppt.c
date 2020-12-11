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