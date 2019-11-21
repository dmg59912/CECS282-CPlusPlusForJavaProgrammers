// Qianli Li
// CECS 282-05
// Project 4 - Overloading Operators
// Nov 5, 2019

#include "upDate.h"
#include <iostream>
using namespace std;

int upDate::count = 0;

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


upDate::upDate()
{
	dptr = new int[3];
	dptr[0] = 5;
	dptr[1] = 11;
	dptr[2] = 1959;

	count++;
}

upDate::upDate(int M, int D, int Y) {
	dptr = new int[3];
	if (M > 0 && M < 13) {
		if (M == 12) {
			if (D > 0 && D < 32) {
				dptr[0] = M;
				dptr[1] = D;
				dptr[2] = Y;
				count++;
				return;
			}
		}
		else if (D > 0 && D < (Greg2Julian(M + 1, 1, Y) - Greg2Julian(M, 1, Y))) {
			dptr[0] = M;
			dptr[1] = D;
			dptr[2] = Y;
			count++;
			return;
		}
	}
	dptr[0] = 5;
	dptr[1] = 11;
	dptr[2] = 1959;

	count++;
}

upDate::upDate(int J)
{
	dptr = new int[3];
	Julian2Greg(J, dptr[0], dptr[1], dptr[2]);

	count++;
}

upDate::upDate(const upDate &D)
{
	dptr = new int[3];
	dptr[0] = D.dptr[0];
	dptr[1] = D.dptr[1];
	dptr[2] = D.dptr[2];

	count++;
}

upDate::~upDate()
{
	count--;
	delete[]dptr;
}

int upDate::julian() {
	return Greg2Julian(dptr[0], dptr[1], dptr[2]);
}

void upDate::setDate(int M, int D, int Y)
{
	if (M > 0 && M < 13) {
		if (M == 12) {
			if (D > 0 && D < 32) {
				dptr[0] = M;
				dptr[1] = D;
				dptr[2] = Y;
				return;
			}
		}
		else if (D > 0 && D < (Greg2Julian(M + 1, 1, Y) - Greg2Julian(M, 1, Y))) {
			dptr[0] = M;
			dptr[1] = D;
			dptr[2] = Y;
			return;
		}
	}
	dptr[0] = 5;
	dptr[1] = 11;
	dptr[2] = 1959;
}

int upDate::getMonth() const {
	return dptr[0];
}

int upDate::getDay() const {
	return dptr[1];
}

int upDate::getYear() const {
	return dptr[2];
}

string upDate::getMonthName() const
{
	string monthName;
	switch (dptr[0])
	{
	case 1: monthName = "January";
		break;
	case 2: monthName = "February";
		break;
	case 3: monthName = "March";
		break;
	case 4: monthName = "April";
		break;
	case 5: monthName = "May";
		break;
	case 6: monthName = "June";
		break;
	case 7: monthName = "July";
		break;
	case 8: monthName = "August";
		break;
	case 9: monthName = "September";
		break;
	case 10: monthName = "October";
		break;
	case 11: monthName = "November";
		break;
	case 12: monthName = "December";
		break;
	}
	return monthName;
}

upDate upDate::operator+(int d) {
	int J = Greg2Julian(dptr[0], dptr[1], dptr[2]) + d;
	upDate temp(J);
	return temp;
}

upDate operator+(int d, const upDate& D) {
	int J = Greg2Julian(D.dptr[0], D.dptr[1], D.dptr[2]) + d;
	upDate temp(J);
	return temp;
}

int upDate::operator-(upDate D) {
	return Greg2Julian(dptr[0], dptr[1], dptr[2]) - Greg2Julian(D.getMonth(), D.getDay(), D.getYear());
}

upDate upDate::operator-(int d) {
	int J = Greg2Julian(dptr[0], dptr[1], dptr[2]) - d;
	upDate temp(J);
	return temp;
}

upDate upDate::operator+=(int d) {
	int J = Greg2Julian(dptr[0], dptr[1], dptr[2]) + d;
	Julian2Greg(J, dptr[0], dptr[1], dptr[2]);
	return *this;
}

upDate upDate::operator-=(int d) {
	int J = Greg2Julian(dptr[0], dptr[1], dptr[2]) - d;
	Julian2Greg(J, dptr[0], dptr[1], dptr[2]);
	return *this;
}

upDate& upDate::operator++() {
	*this += 1;
	return *this;
}

upDate& upDate::operator++(int x) {
	upDate temp = *this;
	++*this;
	return temp;
}

upDate& upDate::operator--() {
	*this -= 1;
	return *this;
}

upDate& upDate::operator--(int x) {
	upDate temp = *this;
	--*this;
	return temp;
}

upDate& upDate::operator=(upDate D) {
	dptr[0] = D.getMonth(); 
	dptr[1] = D.getDay();
	dptr[2] = D.getYear();
	return *this;
}

bool upDate::operator>(upDate D) {
	if (julian() > D.julian())
		return true;
	else
		return false;
}

bool upDate::operator<(upDate D) {
	if (julian() < D.julian())
		return true;
	else
		return false;
}

bool upDate::operator==(upDate D) {
	if (julian() == D.julian())
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, const upDate& D) {
	out << D.getMonthName();
	out << " " << D.getDay();
	out << "," << D.getYear();
	return out;
}

int upDate::GetDateCount() {
	return count;
}


