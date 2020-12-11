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

void displayRangeAppt(PAPPOINTMENT apptList[], int* size)

{
	if (*size == NULL)
		return;

	displayAllAppt(apptList, size);

	for (int i = 0; i < *size; i++)
	{

		int range_min, range_hour;

		i = getUserInput("Enter the number of the appointment you want to check the range:");

		range_min = apptList[i]->endMinutes - apptList[i]->startMinutes;

		if (range_min < 0)
		{
			int endhour = apptList[i]->endHour - 1;
			int endminute = apptList[i]->endMinutes + 60;
			int rangeMin = endminute - apptList[i]->startMinutes;
			range_hour = endhour - apptList[i]->startHour;
			if (range_hour < 0)
			{
				printf("Invalid Appointment\n");
			}
			else
			{
				printf("The range of the appointment at %d is %d hours and %d minutes\n\n", i, range_hour, rangeMin);
			}
			return;
		}
		else
			range_hour = apptList[i]->endHour - apptList[i]->startHour;

		printf("The range of the appointment at %d is %d hours and %d minutes\n\n",i, range_hour, range_min);
		return;
	}

}