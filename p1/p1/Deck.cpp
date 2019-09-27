// Qianli Li
// CECS 282-05
// Project 1 - Solitaire Prime
// Sep 17, 2019

#include "Deck.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;


// constructor which creates a deck of 52 cards. 
// Ace of Spades on top, followed by the rest of the spades in orfer, followed by Hearts, Diamonds and Clubs.
Deck::Deck()
{
	top = 0;
	char suits[4] = { 'S', 'H', 'D', 'C' };
	char ranks[13] = { 'A', '2','3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
	for (int s = 0; s < 4; s++)
	{
		for (int r = 0; r < 13; r++)
		{
			storage[s * sizeof(ranks) + r].setCard(ranks[r], suits[s]);
		}
	}
}


// reset the deck so it looks like a new deck
void Deck::refreshDeck() 
{
	top = 0;
	char suits[4] = { 'S', 'H', 'D', 'C' };
	char ranks[13] = { 'A', '2','3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
	for (int s = 0; s < 4; s++)
	{
		for (int r = 0; r < 13; r++)
		{
			storage[s * sizeof(ranks) + r].setCard(ranks[r], suits[s]);
		}
	}

}


// deal a card from the top of the deck
Card Deck::deal() 
{
	top += 1;
	return storage[top - 1];
}


// shuffle the cards in the deck
void Deck::shuffle()
{
	srand(time(NULL));
	for (int i = 0; i< 10000; i++)
	{
		int x = rand() % 52;
		int y = rand() % 52;
		Card c = storage[x];
		storage[x] = storage[y];
		storage[y] = c;
	}
}


// return the number of cards left in the deck
int Deck::cardsLeft() 
{
	return (sizeof(storage) / sizeof(storage[0]) - top);
}


void Deck::showDeck()
{
	for (int i = 0; i < (sizeof(storage) / sizeof(storage[0]) -top); i++) {
		if (i % 13 == 0) {
			cout << endl;
		}
		storage[top+i].showCard();
		cout << "\t";
	}
	cout << endl;
}
