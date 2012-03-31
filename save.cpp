#include "functions.hpp"
#include <fstream>
#include <sstream>

using namespace std;

bool save(short saveSlot)
{
	if (saveSlot < 1 || saveSlot > 5)
	{
	cout << "Slot chosen is outside the range of available slots. Save aborted!" << endl;
	return false;
	}

	char inputChar;
	cout << "This will cause any existing savefile in this slot to be overwritten. Are you sure that you want to do this? (y to do it!) ";
	cin >> inputChar;
	cout << endl;

	if (!(inputChar=='y'))
	{
	cout << "Save aborted!" << endl;
	return false;
	}

	stringstream saveLocBundler;
	saveLocBundler << "saves/" << saveSlot << ".txt";
	ofstream saveHandler;
	saveHandler.open("saves/1.txt", ios::trunc);	

	if (!saveHandler.is_open())
	{
		cout << "Error opening savefile!" << endl;
		return false;
	}

	// Saving current turn
	saveHandler << currentTurn << '\n';

	// Saving ending turn
	saveHandler << amountOfTurns << '\n';

	// Saving curent player.
	saveHandler << currentPlayer << '\n';

	// Saving number of players.
	saveHandler << playerNumbers << '\n';	

	for(short i = 0; i <= 9; i++)
	{
				
		for(short a = 0; a <= 2; a++)
		{
	
		// Saving money.
		saveHandler << realPlayer[i].cities[a].getMoney() << '\n';
	
		//Get soldier numbers.	
		for(short b = 0; b < 6; b++)
		{
		saveHandler << realPlayer[i].cities[a].soldierInfo(2,b) << '\n';
		}
		
		//Get building numbers.
		for (short c = 0; c < 6; c++)
		{
		saveHandler << realPlayer[i].cities[a].buildingInfo(2,c) << '\n';
		}

		}
	}
	return true;
}
