//PROG71985F20 - Group Assignment
//Fall 2020
//Group members:
	//Thi Huong Tra Le
	//Dominic Pham
	//Le Minh Nguyen

#define MAXTIME 6 
#include "Features.h"

void getInfo(APPOINTMENT appt)
{
	puts("Enter year: ");
	scanf("%d", &appt.year);
	puts("Enter month: ");
	scanf("%d", &appt.month);
	puts("Enter date: ");
	scanf("%d", &appt.date);
	puts("Enter staring time: ");
	scanf("%s", &appt.startTime);
	puts("Enter ending time: ");
	scanf("%s", &appt.finishTime);
	puts("Enter appointment's name: ");
	scanf("%s", &appt.apptName);
	puts("Enter appointment's location: ");
	scanf("%s", &appt.location);
	puts("Enter appointment's content: ");
	scanf("%s", &appt.body);
	getchar();
}

void addNewAppt(PLISTAPPT list, APPOINTMENT newAppt)
{

}

void deleteExistingAppt(PLISTAPPT list, APPOINTMENT newAppt)
{

}
