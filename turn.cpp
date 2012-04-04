#include "functions.hpp"

using namespace std;

void turn(int playerNumber)
{
	int cityToWorkOn, slotToUse;
	for (int i = 0; i < 3; i++)
	{
	realPlayer[playerNumber].cities[i].getBlacksmithBonus();
	}
	while (true)
	{
	cout << "(1-3) Visit a city." << endl;
	cout << "(4) Save." << endl;
	cout << "(5) End Turn." << endl;
	cout << "What do you want to do: ";
	cin >> cityToWorkOn;
	cityToWorkOn -= 1;
	cout << endl;
	
	if (cityToWorkOn == 3)
	{
		cout << "(1-5) Which slot do you want to use: ";
		cin >> slotToUse;
		cout << endl;
		
		if (save(slotToUse) == true)
		{
		cout << "Save succesful" << endl;
		}
		
		else 
		{
		cout << "Save failed" << endl;
		}

	}

	else if (cityToWorkOn == 4)
	{
		return;
        }
        
	else if (cityToWorkOn > -1 && cityToWorkOn < 3)
        {
            visitCity(cityToWorkOn, playerNumber);
        }
	
	else 
	{
		cout << "Invalid option. Please try again." << endl;
	}
	
	}
}


