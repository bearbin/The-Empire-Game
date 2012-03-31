using namespace std;

#include "functions.hpp"

void game()
{
	currentTurn = 0;
	playerNumbers = getPlayerNumbers() - 1;
	cout << "How many turns do you want to play: ";
	cin >> amountOfTurns;
	cout << endl;
	while (currentTurn <= amountOfTurns)
	{
	while (currentPlayer <= playerNumbers)
	{
	cout << "Turn " << currentTurn+1 << " of " << amountOfTurns << " for player " << currentPlayer+1 << "." << endl << endl;
	turn(currentPlayer);
	currentPlayer++;
        }
	currentTurn++;
	}
	cin.get();
	cin.get();
	return;
}
