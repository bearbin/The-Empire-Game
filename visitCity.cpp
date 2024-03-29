#include "functions.hpp"

using namespace std;

void visitCity(int cityToWorkOn, int playerNumber)
{
	int thingToBeUpgraded, amountToBeUpgradedBy, answer;
	signed int result;
	while (true)
	{
	cout << "(1) Upgrade Buildings" << endl;
	cout << "(2) Hire Troops" << endl;
	cout << "(3) Not implemented." << endl;
	cout << "(4) Check Money" << endl;
	cout << "(5) Check Buildings" << endl;
	cout << "(6) Check Troops" << endl;
	cout << "(7) Exit City" << endl;
	cout << "What operation do you want to do: ";
	cin >> answer;
	cout << endl;
	switch (answer)
	{
	case 1:
		cout << "(0) Castle" << endl;
		cout << "(1) Training Camp" << endl;
		cout << "(2) Farms" << endl;
		cout << "(3-5) Blacksmiths" << endl;
		cout << "What building do you want to upgrade: ";
		cin >> thingToBeUpgraded;
		cout << endl;
		cout << "How many levels do you want to upgrade the building by: ";
		cin >> amountToBeUpgradedBy;
		cout << endl << endl;
		result = realPlayer[playerNumber].cities[cityToWorkOn].setBuilding(0, amountToBeUpgradedBy, thingToBeUpgraded);
		if (result == -1)
		{
			cout << "Upgrade failed. Not enough money to upgrade the building." << endl;
		}
		else if (result == -2)
		{
			cout << "Upgrade failed. Building level maxed out." << endl;
		}
		else
		{
			cout << "Building upgrade succeeded!" << endl;
			cout << "The chosen building now has " << result << " levels." << endl;
		}
		break;
	case 2:
		cout << "(0) Pikeman" << endl;
		cout << "(1) Swordsman" << endl;
		cout << "(2) Medic" << endl;
		cout << "(3) Archer" << endl;
		cout << "(4) Horseman" << endl;
		cout << "(5) SuperSoldier" << endl;
		cout << "What type of soldier do you want to recruit: ";
		cin >> thingToBeUpgraded;
		cout << endl;
		cout << "How many soldiers do you want to recruit: ";
		cin >> amountToBeUpgradedBy;
		cout << endl << endl;
		result = realPlayer[playerNumber].cities[cityToWorkOn].setSoldier(0, amountToBeUpgradedBy, thingToBeUpgraded);
		if (result == -1)
		{
			cout << "Upgrade failed. There was not enough food for the soldiers." << endl;
		}
		else if (result == -2)
		{
			cout << "Upgrade failed. There was nout enough money to hire the new soldiers." << endl;
		}
		else
		{
			cout << "Soldier recruiting succeeded!" << endl;
			cout << "The chosen soldiertype now has " << result << " soldiers in it." << endl;
		}
		break;
	case 3:
		cout << "This feature is not implemented." << endl;
		break;
	case 4:
		cout << "You have: $" << realPlayer[playerNumber].cities[cityToWorkOn].getMoney() << " in this city." << endl;
		break;
	case 5:
		cout << "(0) Castle" << endl;
		cout << "(1) Training Camp" << endl;
		cout << "(2) Farms" << endl;
		cout << "(3-5) Blacksmith (1-3)" << endl;
		cout << "What building do you want to inspect: ";
		cin >> thingToBeUpgraded;
		cout << endl;
		cout << "The cost of a level upgrade to building " << thingToBeUpgraded << " is " << realPlayer[playerNumber].cities[cityToWorkOn].buildingInfo(0, thingToBeUpgraded) << endl;
		cout << "The maximum level of building " << thingToBeUpgraded << " is " << realPlayer[playerNumber].cities[cityToWorkOn].buildingInfo(1, thingToBeUpgraded) << endl;
		cout << "The current level of building " << thingToBeUpgraded << " is " << realPlayer[playerNumber].cities[cityToWorkOn].buildingInfo(2, thingToBeUpgraded) << endl;
		break;
	case 6:
		cout << "(0) Pikeman" << endl;
		cout << "(1) Swordsman" << endl;
		cout << "(2) Medic" << endl;
		cout << "(3) Archer" << endl;
		cout << "(4) Horseman" << endl;
		cout << "(5) SuperSoldier" << endl;
		cout << "What type of soldier do you want to inspect: ";
		cin >> thingToBeUpgraded;
		cout << endl;
		cout << "The current amount of soldiertype " << thingToBeUpgraded << " is " << realPlayer[playerNumber].cities[cityToWorkOn].soldierInfo(2, thingToBeUpgraded) << endl;
		break;
	case 7:
		return;
		break;
	default:
		cout << "You entered a number that was not available, please try again." << endl;
		break;
	}
	}
}
