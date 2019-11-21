// Qianli Li
// CECS 282-05
// Project 5 - Standard Template
// Nov 19, 2019

#ifndef BIGINT_H
#define BIGINT_H

#include<vector>
using namespace std;

class BigInt
{
private: 
	vector<char> num;
public:
	BigInt();
	BigInt(int);
	BigInt(string);
	BigInt operator+(BigInt);
	friend BigInt operator+(int, const BigInt&);
	BigInt operator+=(BigInt);
	BigInt& operator++();
	BigInt operator++(int);
	BigInt operator-(BigInt);
	friend BigInt operator-(int, const BigInt&);
	BigInt operator-=(BigInt);
	BigInt& operator--();
	BigInt operator--(int);
	friend ostream& operator<<(ostream&, const BigInt&);
	/*
	bool operator< (const BigInt&) const;
	bool operator> (const BigInt&) const;
	bool operator== (const BigInt&) const;
	bool operator<= (const BigInt&) const;
	bool operator>= (const BigInt&) const;
	*/
	friend bool operator< (const BigInt&, const BigInt&);
	friend bool operator> (const BigInt&, const BigInt&);
	friend bool operator== (const BigInt&, const BigInt&);
	friend bool operator<= (const BigInt&, const BigInt&);
	friend bool operator>= (const BigInt&, const BigInt&);
	void print();
};
#endif

