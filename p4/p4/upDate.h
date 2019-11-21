// Qianli Li
// CECS 282-05
// Project 4 - Overloading Operators
// Nov 5, 2019

#ifndef UPDATE_H
#define UPDATE_H
#include <string>
using namespace std;

class upDate
{
private:
	int *dptr;
	static int count;
public:
	upDate();
	upDate(int, int, int);
	upDate(int);
	upDate(const upDate&);
	~upDate();
	int julian();
	void setDate(int, int, int);
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	string getMonthName() const;
	upDate operator+(int);
	friend upDate operator+(int, const upDate&);
	upDate operator-(int);
	int operator-(upDate);
	upDate operator+=(int);
	upDate operator-=(int);
	upDate& operator++();
	upDate& operator++(int);
	upDate& operator--();
	upDate& operator--(int);
	upDate& operator=(upDate);
	bool operator>(upDate);
	bool operator<(upDate);
	bool operator==(upDate);
	friend ostream& operator<<(ostream&, const upDate&);
	static int GetDateCount();
};
#endif
