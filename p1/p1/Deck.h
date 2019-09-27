// Qianli Li
// CECS 282-05
// Project 1 - Solitaire Prime
// Sep 17, 2019

#ifndef Deck_H
#define Deck_H
#include "Card.h"

class Deck
{
private:
	Card storage[52];
	int top;
public:
	Deck();
	void refreshDeck();
	Card deal();
	void shuffle();
	int cardsLeft();
	void showDeck();
};
#endif
