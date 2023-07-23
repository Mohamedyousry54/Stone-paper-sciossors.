#include <iostream>
#include<cstdlib>
#include<windows.h>
using namespace std;
enum enchoice { paper = 1, scissors = 2, stone = 3 };

//read number of rounds 

void readrounds(int& i) 
{
	cout << "enter number of rounds ?" << endl;
	cin >> i;
}

//determine which is choice is win in the round 
void roundwin(int x,int y,int &player,int &comp)
{
	if (((x ==enchoice::stone && y == enchoice::scissors) || 
		(x == enchoice::paper && y == enchoice::stone)) ||
		(x == enchoice::scissors && y == enchoice::paper))
	{
		cout << "\nwinner is player in this round \a.\n";
		system("color 04");
		player++;
	}
	else if (((y == enchoice::stone && x == enchoice::scissors) || 
		     (y == enchoice::paper && x == enchoice::stone)) ||
		     (y == enchoice::scissors && x == enchoice::paper))
	{
		cout << "winner is coputer in this round \a.\n";
		system("color 4f");
		comp++;
	}
	else
	{
		cout << "\nit's a tie.\n";
		system("color 0f");
	}

}

void userchoice(int&x)
{
	cout << "enter your choice \n[1]:paper\n [2]:scissors\n [3]:stone\n ";
	cin >> x;
}

void computerchoice(int&computer)
{
	computer = rand() % 3;
	while (computer == 0)
		computer = rand() % 3;
	cout << "\nthe computer choice is \n" << computer << endl;
}

void declarewinner(int x,int y)
{
	
	if (x > y)
		cout << "\nplayer is the winner in the end of the game .\n";
	else if (x < y)
		cout << "\n computer  is the winner in the end of the game .\n";
	else
		cout << "\n \a it is a tie.\n\a";
}

bool loop(bool& repeat)
{
	cout << "\ndo you want to start the game again?[0]:NO\n,[1]:Yes.\n";
	cin >> repeat;
	return repeat;
}

void game() {
	int x = 0;
	bool repeat = 0;
	int player = 0, comp = 0, sump = 0, sumc = 0;
	do
	{
		readrounds(x);
		for (int i = 0; i < x; i++)
		{
			userchoice(player);
			computerchoice(comp);
			roundwin(player, comp, sump, sumc);
		}
		declarewinner(sump, sumc);
		loop(repeat);
	} while (repeat);
}


int main()
{
	srand((unsigned)time(NULL));
	game();
	return 0;
}
