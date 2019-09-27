// Qianli Li
// CECS 282-05
// Project 1 - Solitaire Prime
// Oct 1, 2019

#include "myDate.h"
#include <iostream>
using namespace std;


int Greg2Julian(int month, int day, int year) {
	return (day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367 * (month - 2 -
		(month / 14) / 12 * 12) / 12 - 3 * ((year + 4900 + (month - 14) / 12) / 100) / 4);
}


void Julian2Greg(int JD, int & month, int & day, int & year) {
	int L, N;
	L = JD + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	year = 4000 * (L + 1) / 1461001;
	L = L - 1461 * year / 4 + 31;
	month = 80 * L / 2447;
	day = L - 2447 * month / 80;
	L = month / 11;
	month = month + 2 - 12 * L;
	year = 100 * (N - 49) + year + L;
}


myDate::myDate()
{
	month = 5;
	day = 11;
	year = 1959;
}


myDate::myDate(int M, int D, int Y) {
	month = M;
	day = D;
	year = Y;
}


void myDate::display() {
	cout << month << " " << day << ", " << year;
}


void myDate::increaseDate(int N) {
	Julian2Greg(Greg2Julian(month, day, year) + N, month, day, year);
}


void myDate::decreaseDate(int N) {
	Julian2Greg(Greg2Julian(month, day, year) - N, month, day, year);
}


int myDate::daysBetween(myDate D) {
	if (Greg2Julian(month, day, year) > Greg2Julian(D.getMonth(), D.getDay(), D.getYear())) {
		return Greg2Julian(month, day, year) - Greg2Julian(D.getMonth(), D.getDay(), D.getYear());
	}
	return Greg2Julian(D.getMonth(), D.getDay(), D.getYear()) - Greg2Julian(month, day, year);
}


int myDate::getMonth() {
	return month;
}


int myDate::getDay() {
	return day;
}


int myDate::getYear() {
	return year;
}

int myDate::dayOfYear() {
	return Greg2Julian(month, day, year) - Greg2Julian(1, 1, year);
}


string myDate::dayName() {

}


