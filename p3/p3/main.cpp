// Qianli Li
// CECS 282-05
// Project 3 - Structs and Pointers
// Oct 15, 2019


#include "myDate.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;


struct Student
{
	int ID;
	char name[20];
	char grade;
	myDate bday;
	string homeTown;
};


void populate(Student *s[]);
void sortByID(Student);
void sortByName(Student);
void sortByGrade(Student);
void sortByBirthday(Student);
void sortByHomeTown(Student);
void display(Student *s[]);
void copyArray(Student *d[], Student *s[]);
void printMenu();


int main()
{
	int option = 0;
	Student *p[9];
	populate(p);
	display(p);
	Student *copy[9];
	copyArray(copy, p);
	display(copy);
	/*
	

	while (option != 7) {
	    printMeun
	    cin >> option
		switch (option) {
		case 1:
			display(p);
			break;
		case 2:
			sortByID(copy);
			display(copy);
			break;
		case 3:
			sortByName(copy);
			display(copy);
			break;
		case 4:
			sortByGrade(copy);
			display(copy);
			break;
		case 5:
			sortByBirthday(copy);
			display(copy);
			break;
		case 6:
			sortByHomeTown(copy);
			display(copy);
			break;
		}
	}
	*/
	getchar();
}


void printMenu() {
	cout << endl << "1) Display original list" << endl;
	cout << "2) Display list sorted by Student ID" << endl;
	cout << "3) Display list sorted by Name" << endl;
	cout << "4) Display list sorted by Grade" << endl;
	cout << "5) Display list sorted by Birthday" << endl;
	cout << "6) Display list sorted by Home Town" << endl;
	cout << "7) Exit" << endl;
}

void populate(Student *s[]) {
	char grade[] = { 'A', 'B', 'C', 'D', 'F' };
	string city[] = { "San Francisco", "San Mateo", "Palo Alto", "Los Altos", "Mountain View", "Sunnyvale", "San Jose", "Irvine", "Long beach" };
	srand(time(NULL));
	for (int i = 0; i < 9; i++) {
		s[i] = new Student;
		s[i]->ID = rand()% 100000 + 100000;
		s[i]->grade = grade[rand() % (sizeof(grade) / sizeof(grade[0]))];
		s[i]->bday = myDate(rand() % 12 + 1, rand() % 28 + 1, rand() % 4+ 2000);
		s[i]->homeTown = city[i];
	}
	strncpy_s(s[0]->name, "Roronoa Zoro", sizeof(s[0]->name) - 1);
	strncpy_s(s[1]->name, "Vinsmoke Sanji", sizeof(s[1]->name) - 1);
	strncpy_s(s[2]->name, "Tony Chopper", sizeof(s[2]->name) - 1);
	strncpy_s(s[3]->name, "Nico Robin", sizeof(s[3]->name) - 1);
	strncpy_s(s[4]->name, "Monkey Luffy", sizeof(s[4]->name) - 1);
	strncpy_s(s[5]->name, "Dracule Mihawk", sizeof(s[5]->name) - 1);
	strncpy_s(s[6]->name, "Trafalgar Law", sizeof(s[6]->name) - 1);
	strncpy_s(s[7]->name, "Boa Hancock", sizeof(s[7]->name) - 1);
	strncpy_s(s[8]->name, "Monkey Garp", sizeof(s[8]->name) - 1);
}


void sortByID(Student) {}
void sortByName(Student) {}
void sortByGrade(Student) {}
void sortByBirthday(Student) {}
void sortByHomeTown(Student) {}


void display(Student *s[]) {
	cout << setw(15) << left << "Student ID";
	cout << setw(25) << left << "Name";
	cout << setw(15) << left << "Grade";
	cout << setw(30) << left << "Birthday";
	cout << setw(20) << left << "Home Town" << endl;
	for (int i = 0; i < 9; i++) {
		cout << setw(15) << left << s[i]->ID;
		cout << setw(25) << left << s[i]->name;
		cout << setw(15) << left << s[i]->grade;
		cout << setw(30) << left << s[i]->bday.formatDate();
		cout << setw(20) << left << s[i]->homeTown << endl;
	}
}


void copyArray(Student *d[], Student *s[]) {
	for (int i = 0; i < 9; i++)
	{
		d[i] = s[i];
	}
}