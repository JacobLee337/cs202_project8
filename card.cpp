#include <iostream>
#include <fstream>
#include <string>
#include "card.h"

using namespace std;

//CARD CLASS
card :: card()
{
	suit = "suit";
	rank = "rank";
	location = "location";
	value = 0;
}

card :: ~card()
{
	suit.clear();
	rank.clear();
	location.clear();
	value = 0;

}

card :: card(const card &in)
{
	suit = in.suit;
	rank = in.rank;
	location = in.location;
	value = in.value;
}

void card :: setLocal(string in)
{
	location = in;
}

card& card :: operator=(const card &in)
{
	if(this != &in)
	{
		suit = in.suit;
		rank = in.rank;
		location = in.location;
		value = in.value;
	}

	return *this;	
}

bool card :: operator>(const card in) const
{
	if(value > in.value)
		return true;
	else
		return false;
}


bool operator<(const card one, const card two)
{
	if(one.value > two.value)
		return false;
	else
		return true;
}


ifstream& operator>>(ifstream &fin, card &in)
{
	string names[13] = {"two","three","four","five",
					    "six","seven","eight","nine",
						"ten","jack","queen","king","ace"};
	int value[13];

	for(int i = 0; i < 13; i++)
	{
		value[i] = i+2;
		
	}


	fin >> in.suit;
	fin >> in.rank;

	string tmp = in.rank;

	

	for(int i = 0; i < 13; i++)
	{
		if( tmp.compare(names[i]) == 0) 
		{
			in.value = value[i];
		}		
	}

}

ostream& operator<<(ostream &os, card &in)
{
	cout << in.suit << " " << in.rank << " " << in.location; 
}

//PLAYER CLASS
player :: player()
{
	name = "first last";
	hand = new card[5];
	bet = 0.0;
}

player :: ~player()
{
	name.clear();
	delete [] hand;
	bet = 0.0;
}

void player :: setBet(int in)
{
	bet = in;
}

int player :: getBet() const
{
	return bet;
}

void player :: setHand(card in, int i)
{
	hand[i] = in;
	hand[i].setLocal("InHand");
}

ifstream& operator>>(ifstream &fin, player &in)
{
	string tmp;
	fin >> tmp;
	in.name = tmp;
	in.name += " ";
	fin >> tmp;
	in.name += tmp;
	in.bet = 0.0;
}

ostream& operator<<(ostream &os, player &in)
{

	cout << in.name << endl;
	for(int i = 0; i < 5; i++)
	{
		cout << in.hand[i] << endl;
	}
	cout << in.bet << endl;

}


