using namespace std;

#include "functions.h"

void game()
{
    int amountOfTurns;
	int i;
	int players = getPlayerNumbers() - 1;
	cout << "How many turns do you want to play: ";
	cin >> amountOfTurns;
	cout << endl;
	for (int a = 0; a < amountOfTurns; a++)
	{
        for (i = 0; i <= players; i++)
        {
            cout << "Turn " << a+1 << " of " << amountOfTurns << " for player " << i+1 << " ." << endl << endl;
            turn(i);
        }
	}
	cin.get();
	cin.get();
	return;
}
