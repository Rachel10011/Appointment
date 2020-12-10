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
#define MAXTIME 11 
#define MAXNAME 51	  
#define MAXBODY 201
#define MAXAPPT 48

typedef struct appointment
{
	int startHour;
	int startMinutes;
	int endHour;
	int endMinutes;
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
void menu(void);


int getUserInput(char []);
int inputTime(int, int);
PAPPOINTMENT initialAppointment();
APPOINTMENT createAppt();
PAPPOINTMENT copyNewAppt(APPOINTMENT);
void addApptToList(PAPPOINTMENT, PAPPOINTMENT, int);
void sortAppt(PAPPOINTMENT[], int);
void disposeAppt(PAPPOINTMENT[], int*);
void addNewAppt(PAPPOINTMENT[], PAPPOINTMENT, int*);
void deleteExistingAppt(PAPPOINTMENT, int*);
void updateExistingAppt(PAPPOINTMENT[], int*);
void displaySingleAppt(PAPPOINTMENT[],int*);
void searchForAppt(PAPPOINTMENT[], int*);
void displayRangeAppt(PAPPOINTMENT[],int*);
void displayAllAppt(PAPPOINTMENT[],int*);


//Friendly/easy to use UI (or menu system) --- nice and clean design?
//save accumulated data to disk   ---- save to file?
//load accumulated data from disk ---- load data from file?