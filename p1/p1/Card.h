// Qianli Li
// CECS 282-05
// Project 1 - Solitaire Prime
// Sep 17, 2019

#ifndef Card_H
#define Card_H

class Card
{
private:
	char rank;
	char suit;
public:
	Card();
	Card(char, char);
	void setCard(char, char);
	int getValue();
	void showCard();
};
#endif

