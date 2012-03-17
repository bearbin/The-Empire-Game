#include "functions.hpp"

using namespace std;

void turn(int playerNumber)
{
	int cityToWorkOn;
	for (int i = 0; i < 5; i++)
	{
	realPlayer[playerNumber].cities[i].getBlacksmithBonus();
	}
	while (true)
	{
	cout << "(1-3) Visit a city." << endl;
	cout << "(4) End Turn." << endl;
	cout << "What do you want to do: ";
	cin >> cityToWorkOn;
	cityToWorkOn -= 1;
	cout << endl;
	if (cityToWorkOn == 3)
	{
		return;
        }
        else
        {
            visitCity(cityToWorkOn, playerNumber);
        }
	}
}


