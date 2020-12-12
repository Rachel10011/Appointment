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


