using namespace std;

#include "functions.hpp"

int getPlayerNumbers()
{
	int playerNum;
	while(true)
	{
		cout << endl << "Please choose how many players you want to have: ";
		cin >> playerNum;
		cout << endl;
		if((playerNum > 11) || (playerNum < 2))
		{
			cout << "Invalid player number. Please choose a number between 2 and 10." << endl;
		}
		else
		{
			return playerNum;
		}
	}
	return playerNum;
}
