#include "BigInt.h"
#include <iostream>
#include <map>
using namespace std;


int goldRabbits(int);
BigInt goldRabbits(BigInt);
void pause() { cout << "press Enter to continue..."; getchar(); }

int main() {
	BigInt B1("123456789123456789123456789123456789");
	BigInt B2(B1);
	BigInt MAX(INT_MAX);
	cout << "B1: " << B1 << "\nB2: " << B2 << "\nMAX: " << MAX << endl;
	pause();
	cout << "\nB1: ";
	B1.print();
	cout << endl;
	pause();
	
	// for (int i = 0; i <= 3000; i++) 
	 for (BigInt i = 0; i <= 100; i++)
	 {
		cout << "\ngoldRabbits(" << i << ") = " << goldRabbits(i);
	 }
	
	pause();

	cout << "\nThis is the value of goldRabbits(3000)\n\n";
	BigInt gR3000 = goldRabbits(BigInt(3000));
	gR3000.print();

	pause();
}

int goldRabbits(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return goldRabbits(n - 1) + goldRabbits(n - 2);
	}
}

BigInt goldRabbits(BigInt bInt) {
	static map<BigInt, BigInt> storage;
	if (bInt == BigInt(0) || bInt == BigInt(1)) {
		return BigInt(1);
	}
	else if (storage.find(bInt) != storage.end()) {
		return storage.find(bInt)->second;
	}
	else {
		BigInt temp = goldRabbits(bInt - 1) + goldRabbits(bInt - 2);
		storage[bInt] = temp;
		return temp;
	}


}