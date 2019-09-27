// Qianli Li
// CECS 282-05
// Project 1 - Solitaire Prime
// Sep 17, 2019

#include "Card.h"
#include<iostream>
#include <string>
using namespace std;


// create a blank card
Card::Card()
{
	rank = ' ';
	suit = ' ';
}


// constructor to create a card, setting the rank and suit
Card::Card(char r, char s) 
{
	rank = r;
	suit = s;
}


// set an existing blank card to a particular value
void Card::setCard(char r, char s)
{
	rank = r;
	suit = s;
}


// return the point value of the card
int Card::getValue()
{
	switch (rank)
	{
	case 'A': return 1;
		break;
	case '2': return 2;
		break;
	case '3': return 3;
		break;
	case '4': return 4;
		break;
	case '5': return 5;
		break;
	case '6': return 6;
		break;
	case '7': return 7;
		break;
	case '8': return 8;
		break;
	case '9': return 9;
		break;
	default: return 10;
		break;
	}
}


// display the card using 2 fields
void Card::showCard(){
	string output = "";
	if (rank == 'T') {
		output = output + "10";
	}
	else {
		output += rank;
	}
	output += suit;
	cout << output;
}



