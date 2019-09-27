// Qianli Li
// CECS 282-05
// Project 1 - Solitaire Prime
// Sep 17, 2019

# include "Deck.h"
# include "Card.h"
# include <iostream>
using namespace std;


void printMenu() {
	cout << endl << "Welcome to Soliaire Prime!" << endl;
	cout << "1) New Deck" << endl;
	cout << "2) Display Deck" << endl;
	cout << "3) Shuffle Deck" << endl;
	cout << "4) Play Solitaire Prime" << endl;
	cout << "5) Exit" << endl;
}


bool isPrime(int value) {
	if (value <= 1){
		return false;
	}

	for (int i = 2; i < value; i++){
		if (value % i == 0)
			return false;
	}
	return true;
}


void solitairePrime(Deck deck) {
	int sum = 0;
	int count = 0;
	Card c;
	cout << "Playing Solitaire Prime!!!" << endl << endl;

	for (int i = 0; deck.cardsLeft() > 0; i++) {
		c = deck.deal();
		c.showCard();
		cout << ", ";
		sum += c.getValue();
		if (isPrime(sum)) {
			cout << "Prime: " << sum << endl;
			sum = 0;
			count++;
		}
		if (deck.cardsLeft() == 0 && sum == 0) {
			cout << endl << "Winner in " << count << " piles!" << endl;
		}
		if (deck.cardsLeft() == 0 && sum != 0) {
			cout << "Loser" << endl;
		}
	}
}


int main() {
	int userInput = 0;
	Deck myDeck;
	while (userInput != 5) {
		printMenu();
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			myDeck.refreshDeck();
			break;
		case 2:
			myDeck.showDeck();
			break;
		case 3:
			myDeck.shuffle();
			break;
		case 4:
			solitairePrime(myDeck);
			break;
		}
	}
	return 0;
}
