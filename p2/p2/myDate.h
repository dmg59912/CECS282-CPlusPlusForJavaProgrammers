// Qianli Li
// CECS 282-05
// Project 1 - Solitaire Prime
// Oct 1, 2019

#ifndef MYDATE.H
#define MYDATE.H
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
