//PROG71985F20 - Group Assignment
//Fall 2020
//Group members:
	//Thi Huong Tra Le
	//Dominic Pham
	//Le Minh Nguyen

#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdbool.h>
#define MAX_TIME_SIZE 6

typedef struct appointment
{
	int date;
	int month;
	int year;
	char* startTime;
	char* finishTime;
	char* apptName;
	char* location;
	char* body;
}APPOINTMENT, * PAPPOINTMENT;

typedef struct listappointment
{
	PAPPOINTMENT appt;
	struct listappointment* nextappt;
}LISTAPPT, * PLISTAPPT;


//Required features:
void getInfo(APPOINTMENT);
void addNewAppt(PLISTAPPT, APPOINTMENT);
void deleteExistingAppt(PLISTAPPT, APPOINTMENT);
void updateExistingAppt();
void displaySingleAppt();
void displayRangeAppt();
void displayAllAppt();
void searchForAppt();

//Friendly/easy to use UI (or menu system) --- nice and clean design?
//save accumulated data to disk   ---- save to file?
//load accumulated data from disk ---- load data from file?