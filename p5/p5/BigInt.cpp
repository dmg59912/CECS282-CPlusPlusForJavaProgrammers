// Qianli Li
// CECS 282-05
// Project 5 - Standard Template
// Nov 19, 2019

#include "BigInt.h"
#include<iostream>
#include <iomanip>
#include<vector>
using namespace std;

BigInt::BigInt() {
	num.push_back(0);
}

BigInt::BigInt(int n) {
	while (n > 9) {
		int digit = n % 10;
		num.push_back(digit);
		n /= 10;
	}
	num.push_back(n);
}

BigInt::BigInt(string s) {
	for (int i = 0; i < s.size(); i++) {
		num.insert(num.begin(), s[i] - 48);
	}
}

BigInt BigInt::operator+(BigInt bInt) {
	BigInt longInt, shortInt;
	if (num.size() < bInt.num.size()) {
		shortInt = *this;
		longInt = bInt;
	}
	else {
		longInt = *this;
		shortInt = bInt;
	}
	for (int i = 0; i < shortInt.num.size(); i++) {
		longInt.num[i] += shortInt.num[i];
	}
	for (int j = 0; j < longInt.num.size() - 1; j++) {
		if (longInt.num[j] > 9) {
			if (longInt.num[j + 1] != NULL) {
				longInt.num[j + 1]++;
				longInt.num[j] -= 10;
			}
			else {
				longInt.num[j + 1] = 1;
				longInt.num[j] -= 10;
			}
		}
	}
	if (longInt.num.back() > 9) {
		longInt.num.back() -= 10;
		longInt.num.push_back(1);
	}
	return longInt;
}

BigInt operator+(int x, const BigInt& bInt) {
	return BigInt(x) + bInt;
}

BigInt BigInt::operator+=(BigInt bInt) {
	*this = *this + bInt;
	return *this;
}

BigInt& BigInt::operator++() {
	*this += 1;
	return *this;
}

BigInt BigInt::operator++(int x) {
	BigInt temp = *this;
	++*this;
	return temp;
}

BigInt BigInt::operator-(BigInt bInt) {
	BigInt left, right;
	left = *this;
	right = bInt;
	for (int i = 0; i < right.num.size(); i++) {
		if ((int)left.num[i] >= (int)right.num[i]) {
			left.num[i] = (int)left.num[i] - (int)right.num[i];
		}
		else {
			left.num[i] = 10 + (int)left.num[i] - (int)right.num[i];
			for (int j = i + 1; j < left.num.size(); j++) {
				if (left.num[j] > 0) {
					--left.num[j];
					break;
				}
				else {
					left.num[j] = 9;
				}
			}

		}
	}
	for (int k = left.num.size() - 1; k > 0; k--) {
		if ((int)left.num[k] == 0) {
			left.num.pop_back();
		}
		else {
			break;
		}
	}
	return left;
}

BigInt operator-(int x, const BigInt& bInt) {
	return BigInt(x) - bInt;
}

BigInt BigInt::operator-=(BigInt bInt) {
	*this = *this - bInt;
	return *this;
}

BigInt& BigInt::operator--() {
	*this -= 1;
	return *this;
}

BigInt BigInt::operator--(int x) {
	BigInt temp = *this;
	--*this;
	return temp;
}

ostream& operator<<(ostream& out, const BigInt& bInt) {
	vector<char>::const_reverse_iterator rit;
	rit = bInt.num.rbegin();
	while (rit != bInt.num.rend()) {
		out << (int)*rit++;
	}
	return out;
}
/*
bool BigInt::operator< (const BigInt& bInt) const {
	if (num.size() < bInt.num.size()) {
		return true;
	}
	else if (num.size() > bInt.num.size()) {
		return false;
	}
	else {
		vector<char>::const_reverse_iterator rit_this, rit_other;
		rit_this = num.rbegin();
		rit_other = bInt.num.rbegin();
		while ((*rit_this++ == *rit_other++) && rit_this != num.rend());
		--rit_this;
		--rit_other;
		return ((int)*rit_this < (int)*rit_other);
	}
}

bool BigInt::operator> (const BigInt& bInt) const  {
	if (num.size() > bInt.num.size()) {
		return true;
	}
	else if (num.size() < bInt.num.size()) {
		return false;
	}
	else {
		vector<char>::const_reverse_iterator rit_this, rit_other;
		rit_this = num.rbegin();
		rit_other = bInt.num.rbegin();
		while ((*rit_this++ == *rit_other++) && rit_this != num.rend());
		--rit_this;
		--rit_other;
		return ((int)*rit_this > (int)*rit_other);
	}
}

bool BigInt::operator== (const BigInt& bInt) const  {
	if (num.size() != bInt.num.size()) {
		return false;
	}
	else {
		vector<char>::const_reverse_iterator rit_this, rit_other;
		rit_this = num.rbegin();
		rit_other = bInt.num.rbegin();
		while ((*rit_this++ == *rit_other++) && rit_this != num.rend());
		--rit_this;
		--rit_other;
		return ((int)*rit_this == (int)*rit_other);
	}
}

bool BigInt::operator<= (const BigInt& bInt) const  {
	if (*this < bInt || *this == bInt) {
		return true;
	}
	else {
		return false;
	}
}

bool BigInt::operator>= (const BigInt& bInt) const  {
	if (*this > bInt || *this == bInt) {
		return true;
	}
	else {
		return false;
	}
}
*/
bool operator< (const BigInt& lhs, const BigInt& rhs) {
	if (lhs.num.size() < rhs.num.size()) {
		return true;
	}
	else if (lhs.num.size() > rhs.num.size()) {
		return false;
	}
	else {
		vector<char>::const_reverse_iterator rit_lhs, rit_rhs;
		rit_lhs = lhs.num.rbegin();
		rit_rhs = rhs.num.rbegin();
		while ((*rit_lhs++ == *rit_rhs++) && rit_lhs != lhs.num.rend());
		--rit_lhs;
		--rit_rhs;
		return ((int)*rit_lhs < (int)*rit_rhs);
	}
}

bool operator> (const BigInt& lhs, const BigInt& rhs) {
	if (lhs.num.size() > rhs.num.size()) {
		return true;
	}
	else if (lhs.num.size() < rhs.num.size()) {
		return false;
	}
	else {
		vector<char>::const_reverse_iterator rit_lhs, rit_rhs;
		rit_lhs = lhs.num.rbegin();
		rit_rhs = rhs.num.rbegin();
		while ((*rit_lhs++ == *rit_rhs++) && rit_lhs != lhs.num.rend());
		--rit_lhs;
		--rit_rhs;
		return ((int)*rit_lhs > (int)*rit_rhs);
	}
}

bool operator== (const BigInt& lhs, const BigInt& rhs) {
	if (lhs.num.size() != rhs.num.size()) {
		return false;
	}
	else {
		vector<char>::const_reverse_iterator rit_lhs, rit_rhs;
		rit_lhs = lhs.num.rbegin();
		rit_rhs = rhs.num.rbegin();
		while ((*rit_lhs++ == *rit_rhs++) && rit_lhs != lhs.num.rend());
		--rit_lhs;
		--rit_rhs;
		return ((int)*rit_lhs == (int)*rit_rhs);
	}
}

bool operator<= (const BigInt& lhs, const BigInt& rhs) {
	if (lhs < rhs || lhs == rhs) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>= (const BigInt& lhs, const BigInt& rhs) {
	if (lhs > rhs || lhs == rhs) {
		return true;
	}
	else {
		return false;
	}
}

void BigInt::print() {
	vector<char>::reverse_iterator rit;
	rit = num.rbegin();
	while (rit != num.rend()) {
		cout << (int)*rit++;
	}
}