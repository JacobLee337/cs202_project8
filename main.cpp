#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "card.h"


using namespace std;

void readDeck(card*,string);
void readPlys(player*,string);
void shuffle(card*);
void deckCopy(card*,card*);
void menu();
void deal(player&, card*, int&);


int num_players = 0;

int main()
{
	string deckFile;
	cout << "Please give a file with a deck of cards in it" << endl;
	cin >> deckFile;


	cout << "How many players? (2-8)" << endl;
	cin >> num_players;

	string plyFile;
	cout <<"Please give a file with player names in it" << endl;
	cin >> plyFile;

	player* plys = new player[num_players];
	readPlys(plys,plyFile);

	card* cleanDeck = new card[52];
	readDeck(cleanDeck,deckFile);

	card* shuffleDeck = new card[52];
	int decknum = 0;

	card* discard = new card[52];
	int disnum = 0;

	card* stock = new card[52];
	int stocknum = 0;

	deckCopy(shuffleDeck,cleanDeck);

	
	shuffle(shuffleDeck);

	while(true)
	{
		menu();
		string indeck;
		card card1;
		card card2;
		int decknum2;
		int menu = -1;
		cin >> menu;
	
		switch(menu)
		{
			case 1:

				cout << "Name of new deck" << endl;
				cin >> indeck;
				readDeck(cleanDeck,indeck);
				deckCopy(shuffleDeck,cleanDeck);

				break;
		
			case 2:
			
				shuffle(shuffleDeck);
				break;
			
			case 3:
			
				cout << "Name of new player file" << endl;
				cin >> plyFile;
				readPlys(plys,plyFile);
				break;

			case 4:
			
				for(int i = 0; i < num_players; i++)
				{
					deal(plys[i],shuffleDeck, decknum);
				}

				discard[disnum] = shuffleDeck[decknum];
				discard[disnum].setLocal("discard");
	
				disnum++;
				decknum++;
				
				
				decknum2 = 	decknum;		

				for(int i = 0; i < (52-decknum2); i++)
				{
				stock[i] = shuffleDeck[decknum];
				stock[i].setLocal("stock");
				stocknum++;
				decknum++;
				}				
				
				break;

			case 5:
		
				for(int i = 0; i < 52; i++)
				{
					cout << cleanDeck[i] << endl;
				}
				break;
			case 6:
		
				for(int i = 0; i < 52; i++)
				{
					cout << shuffleDeck[i] << endl;
				}
				break;

			case 7:

				for(int i = 0; i < disnum; i++)
				{
					cout << discard[i] << endl;
				}
				break;

			case 8:
			
				for(int i = 0; i < stocknum; i++)
				{
					cout << stock[i] << endl;
				}

				break;

			case 9:
			
				for(int i = 0; i < num_players; i++)
				{
					cout << "Player " << i + 1 << ":"<< endl;
					cout << plys[i] << endl;
				}
				break;

			case 10:
				cout << "GOOD BYE" << endl;

				delete [] plys;
				plys = NULL;

				delete [] cleanDeck;
				cleanDeck = NULL;

				delete [] shuffleDeck;
				shuffleDeck = NULL;

				delete [] discard;
				discard = NULL;

				delete [] stock;
				stock = NULL;

				return 0;
				break;

			case 27:
			
				
				card1 =cleanDeck[1];

			
				card2 = cleanDeck[10];

				cout << "Card 1: " << card1 << endl <<"Card 2:" << card2 << endl;

				if(card1 < card2)
					cout << "Card one is LESS THAN card2" << endl;
				else
					cout << "Card one is NOT LESS THAN card2"<< endl;

				if(card1 > card2)
					cout << "Card one is GREATER THAN card2" << endl;
				else
					cout << "Card one is NOT GREATER THAN card2"<< endl;
				break;
			default:
				cout << "That is not a valid input, Please try again" << endl;	
		}


	}

	return 0;
}

void readDeck(card* deck,string deckFile)
{
	ifstream fin;
	fin.open(deckFile.c_str());

	for(int i = 0; i < 52; i++)
	{
		fin >> deck[i];
		deck[i].setLocal("unshuffled");
	}

	fin.close();
}

void readPlys(player* plys,string plyFile)
{
	ifstream fin;
	fin.open(plyFile.c_str());

	for(int i = 0; i < num_players; i++)
	{
		fin >> plys[i];
	}

	fin.close();
}

void shuffle(card* deck)
{
	srand(time(NULL));

	bool* used = new bool[52];
	card* tempDeck = new card[52];
	int rnd;

	for(int i = 0; i < 52; i++)
		used[i] = false;

	deckCopy(tempDeck,deck);
	
	for(int i = 0; i < 52; i++)
	{
		bool done = false;
		while(done == false)
		{
			rnd = rand() % 52 ;

			if(used[rnd] == false)
			{
				deck[i] = tempDeck[rnd];
				used[rnd] = true;
				done = true;
				deck[i].setLocal("shuffled");
			}	
		}	
	}
	
	delete [] used;
	used = NULL;
	delete [] tempDeck;
	tempDeck = NULL;
}

void deckCopy(card* out,card* in)
{
	for(int i = 0; i < 52; i++)
	{
		out[i] = in[i];
	}	
}

void menu()
{
	cout << endl;
	cout <<"**************************************************************" << endl;
	cout <<"1: Read in a new deck of cards" << endl;
	cout <<"2: Shuffle the deck" << endl;
	cout <<"3: Read in new player names" << endl;
	cout <<"4: Deal a hand to each player" << endl;
	cout <<"5: Print clean deck"<<endl;
	cout <<"6: Print out shuffled deck" << endl;
	cout <<"7: Print out card discard pile" << endl;
	cout <<"8: Print out card stock pile" << endl;
	cout <<"9: Print out player info" << endl;
	cout <<"10: quit" << endl;
	cout <<"27: See the fun overloaded < > operators" <<endl;
	cout <<"**************************************************************" << endl;
}

void deal(player &in ,card* deck, int &i)
{
	for(int a = 0; a < 5; a++)
	{
		in.setHand(deck[i],a);
		i++;
	}
}
