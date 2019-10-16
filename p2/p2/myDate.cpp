// Qianli Li
// CECS 282-05
// Project 2 - myDate
// Oct 1, 2019

#include "myDate.h"
#include <iostream>
using namespace std;


int Greg2Julian(int month, int day, int year) {
	return (day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3 * ((year + 4900 + (month - 14) / 12) / 100) / 4);
}


void Julian2Greg(int JD, int & month, int & day, int & year) {
	int I, J, K, L, N;

	L = JD + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	year = I;
	month = J;
	day = K;
}


myDate::myDate()
{
	month = 5;
	day = 11;
	year = 1959;
}


myDate::myDate(int M, int D, int Y) {
	if (M > 0 && M < 13) {
		if (M == 12) {
			if (D > 0 && D < 32) {
				month = M;
				day = D;
				year = Y;
				return;
			}
		}
		else if (D > 0 && D < (Greg2Julian(M + 1, 1, Y) - Greg2Julian(M, 1, Y))) {
			month = M;
			day = D;
			year = Y;
			return;
		}
	}
	month = 5;
	day = 11;
	year = 1959;
}


void myDate::display() {
	string monthName;
	switch (month)
	{
	case 1: monthName = "Jan";
		break;
	case 2: monthName = "Feb";
		break;
	case 3: monthName = "Mar";
		break;
	case 4: monthName = "Apr";
		break;
	case 5: monthName = "May";
		break;
	case 6: monthName = "Jun";
		break;
	case 7: monthName = "Jul";
		break;
	case 8: monthName = "Aug";
		break;
	case 9: monthName = "Sep";
		break;
	case 10: monthName = "Oct";
		break;
	case 11: monthName = "Nov";
		break;
	case 12: monthName = "Dec";
		break;
	}
	cout << monthName << " " << day << ", " << year;
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
	return Greg2Julian(month, day, year) - Greg2Julian(1, 1, year) + 1;
}


string myDate::dayName() {
	int dayOfWeek = (Greg2Julian(month, day, year) - Greg2Julian(5, 11, 1959)) % 7;
	string nameOfDay = "";
	switch (dayOfWeek) {
	case 0:
		nameOfDay = "Monday";
		break;
	case 1:
		nameOfDay = "Tuesday";
		break;
	case 2:
		nameOfDay = "Wednesday";
		break;
	case 3:
		nameOfDay = "Thusday";
		break;
	case 4:
		nameOfDay = "Friday";
		break;
	case 5:
		nameOfDay = "Satusday";
		break;
	case 6:
		nameOfDay = "Sunday";
		break;
	}
	return nameOfDay;
}


