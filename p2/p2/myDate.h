// Qianli Li
// CECS 282-05
// Project 2 - myDate
// Oct 1, 2019

#ifndef MYDATE_H
#define MYDATE_H
#include <string>
using namespace std;

class myDate
{
public:
	myDate();
	myDate(int, int, int);
	void display();
	void increaseDate(int);
	void decreaseDate(int);
	int daysBetween(myDate);
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
	string dayName();


private:
	int month;
	int day;
	int year;
};
#endif
