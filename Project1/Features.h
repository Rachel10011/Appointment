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
#define MAXTIME 100
#define MAXNAME 51	  
#define MAXBODY 1000
#define MAXAPPT 48
#define MAX_FILENAME 100 
#define MINTIME 0
#define MINDATE 1
#define MINYEAR 2020
#define MAXDAY 31
#define MAXHOUR 23
#define MAXMINUTE 59
#define MAXMONTH 12
#define MAXYEAR MINYEAR+4

typedef struct appointment
{
	int day;
	int month;
	int year;
	int startHour;
	int startMinutes;
	int endHour;
	int endMinutes;
	char* apptName;
	char* location;
	char* body;

}APPOINTMENT, * PAPPOINTMENT;



void menu(void);

//By Thi Huong Tra Le:
void printIntro();
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
void askForFilePath(char[]);
void saveDataToDisk(PAPPOINTMENT[], int*, char[]);			


//By Dominic Pham
void updateExistingAppt(PAPPOINTMENT[], int*);
void displaySingleAppt(PAPPOINTMENT[],int*);
void searchForAppt(PAPPOINTMENT[], int*);

//By Le Minh Nguyen
void displayRangeAppt(PAPPOINTMENT[],int*);
void displayAllAppt(PAPPOINTMENT[],int*);
void loadDataFromDisk(APPOINTMENT[], int* , char[]);
//load from file function
