#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class card
{
	friend class player;

	string suit;
	string rank;
	string location;
	int value;

	public:
		
		card();
		
		~card();

		card(const card &);

		void setLocal(string);

		card& operator=(const card&);

		bool operator>(const card) const;

		friend ifstream& operator>>(ifstream&, card&);
		friend ostream& operator<<(ostream&, card&);
		friend bool operator<(const card,const card);
};

class player
{
	string name;
	card* hand;
	float bet;

	public:

		player();

		~player();

		void setBet(int);
		int getBet() const;
		
		void setHand(card, int);

		friend ifstream& operator>>(ifstream&, player&);
		friend ostream& operator<<(ostream&, player&);
};
