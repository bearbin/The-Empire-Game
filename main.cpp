#include <iostream>
#include <string>

using namespace std;

#include "functions.hpp"

int main()
{
	int choice;
	cout << "Welcome!" << endl;
	while(true)
	{
		cout << endl << "(1) Play the Game" << endl;
		cout << "(2) Exit" << endl;
		cout << "Please choose an option: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				game();
				cout << endl << "The game finished. Restarting!";
				cout << endl;
				break;
			case 2:
				return 0;
				break;
			default:
				cout << endl << "An error occured. Please try again." << endl << endl;
				break;
		}
	}
}

