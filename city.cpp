#include "city.hpp"

using namespace std;

city::city()
{
	money = 1000000;
	soldier[0] = 20;
	soldier[1] = 0;
	soldier[2] = 0;
	soldier[3] = 0;
	soldier[4] = 0;
	soldier[5] = 0;
	building[0] = 1;
	building[1] = 0;
	building[2] = 1;
	building[3] = 1;
	building[4] = 0;
	building[5] = 0;
}

string city::getObjectName(int objectType, int objectNumber)
{
	switch (objectType)
	{
	case 0:
		switch (objectNumber)
		{
		case 0:
			return "Pikeman";
			break;
		case 1:
			return "Swordsman";
			break;
		case 2:
			return "Medic";
			break;
		case 3:
			return "Archer";
			break;
		case 4:
			return "Horseman";
			break;
		case 5:
			return "SuperSoldier";
		default:
			return "Error. SoldierType could not be retreived.";
			break;
		}
		break;
	case 1:
		switch (objectNumber)
		{
		case 0:
			return "Castle";
			break;
		case 1:
			return "Training Camp";
			break;
		case 2:
			return "Farms";
			break;
		case 3:
			return "Blacksmith 1";
			break;
		case 4:
			return "Blacksmith 2";
			break;
		case 5:
			return "Blacksmith 3";
			break;
		default:
			return "Error. BuildingType could not be retreived.";
			break;
		}
		break;
	default:
		break;
	}	
	return "<ERROR ALERT. PLEASE SUBMIT BUG REPORT>";
}

long long city::getMoney()
{
    return money;
}

int city::soldierTotal()
{
	return soldier[0] + soldier[1] + soldier[2] + soldier[3] + soldier[4] + soldier[5];
}

int city::soldierCap()
{
	return building[2] * 200 - soldier[0] - soldier[1] - soldier[2] - soldier[3] - soldier[4] - soldier[5];
}

int city::blacksmithTotal()
{
	return building[3] + building[4] + building[5];
}

int city::buildingInfo(int action, int buildingNum)
{
	// action = 0 Gets building cost.
	// action = 1 Gets maxlevel.
	// action = 2 gets current level
	switch(action)
	{
		case 0:
			switch(buildingNum)
			{
				case 0:
					// Castle costs £3 million.
					return 3000000;
					break;
				case 1:
					// Trainingcamp costs £150000.
					return 150000;
					break;
				case 2:
					// 1 farms level costs £200,000.
					return 200000;
					break;
				case 3:
					// 1 Blacksmith level costs £350,000
					return 350000;
					break;
				case 4:
					// 1 Blacksmith level costs £350,000
					return 350000;
					break;
				case 5:
					// 1 Blacksmith level costs £350,000
					return 350000;
					break;
				default:
					return -1;
					break;
			}
			break;
		case 1:
			switch(buildingNum)
			{
			case 0:
				// Castle can be upgraded to level 3.
				return 3;
				break;
			case 1:
				// Trainingcamp has only 1 level.
				return 1;
				break;
			case 2:
				// Farms can be upgraded to level 30.
				return 30;
				break;
			case 3:
				// Each blacksmith can have 100 levels.
				return 100;
				break;
			case 4:
				// Each blacksmith can have 100 levels.
				return 100;
				break;
			case 5:
				// Each blacksmith can have 100 levels.
				return 100;
				break;
			default:
				return -1;
				break;
			}
			break;
		case 2:
			return building[buildingNum];
			break;
		default:
			return -1;
			break;
    }
}

int city::soldierInfo(int action, int soldierType)
{
	switch (action)
	{
		case 0:
			switch (soldierType)
            {
                case 0:
                    return 50000;
                    break;
                case 1:
                    return 75000;
                    break;
                case 2:
                    return 150000;
                    break;
                case 3:
                    return 250000;
                    break;
                case 4:
                    return 350000;
                    break;
                case 5:
                    return 750000;
                    break;
                default:
                    return -1;
                    break;
            }
        case 1:
		switch (soldierType)
		{
		case 0:
			return 1;
			break;
		case 1:
			return 2;
			break;
		case 2:
			return 4;
			break;
		case 3:
			return 8;
			break;
		case 4:
			return 16;
			break;
		case 5:
			return 80;
			break;
		default:
			return -1;
			break;
		}
	case 2:
		return soldier[soldierType];
		break;
	default:
                return -1;
                break;
    }
    return -1;
}

int city::setSoldier(int action, int value, int soldierType)
{
	// action = 0 adds value to the soldier count. Returns -1 if soldiers cannot be added because the soldierCap has been reached, else returns soldierCount.
	// action = 1 subtracts value from the soldier count. Returns 0 even if value > soldier count. Returns soldierCount.
	// action = 2 Sets the soldier count to value. Returns -1 if value is negative. Returns soldierCount.
	// action = 3 Tells the amount of soldier[soldierType].
	bool correctChoice = false;
	switch (action)
	{
		case 0:
			while (correctChoice == false)
			{
			if (soldierType >= 0 && soldierType <= 5)
			{
        		if(soldierTotal() + value <= soldierCap())
			{
				if (soldierInfo(0,soldierType) * value <= money)
				{
					cout << "If you do this:" << endl;
					cout << "You will be charged $" << soldierInfo(0,soldierType) * value << " ." << endl;
					cout << "You will have " << soldier[soldierType] + value << " soldiers of type " << getObjectName(0, soldierType) << endl;
					cout << "Do you wish to do this (true/false): ";
					cin >> correctChoice;
					cout << endl;
					if (correctChoice == true)
					{
					soldier[soldierType] += value;
					money -= soldierInfo(0,soldierType) * value;
					return soldier[soldierType];
					}
				}
				else
				{
					return -1;
				}
			}
			else
			{
				return -2;
			}
			}
			else 
			{
				cout << "<ERROR!> <There is no soldier of the type selected!>" << endl;
			}
			}
			break;
		case 1:
            if (value <= soldier[soldierType])
            {
                soldier[soldierType] -= value;
                return soldier[soldierType];
            }
            else
            {
                soldier[soldierType] = 0;
                return soldier[soldierType];
            }
            break;
        case 2:
            if (value >= 0)
            {
                soldier[soldierType] = value;
                return soldier[soldierType];
            }
            else
            {
                return -1;
            }
            break;
        default:
            return -1;
            break;
    }
	return -1;
}

int city::setBuilding(int action, int value, int buildingNum)
{
    // action = 0 adds value to the building level. Returns -1 if not enough money or max level reached, else returns building level.
    // action = 1 subtracts value from the soldier count. Returns -1 if building level is tried to go under 0. Else returns building level.
    // action = 2 Sets the soldier count to value. Returns -1 if value is negative. Returns soldierCount.
    // action = 3 Tells the amount of soldier[soldierType].
	bool correctChoice = false;
    switch (action)
    {
        case 0:
		if (buildingNum >= 0 && buildingNum <= 5)
		{
		while (correctChoice == false)
		{
		if(building[buildingNum] + value <= buildingInfo(1,buildingNum))
		{
			if (buildingInfo(0, buildingNum) <= money)
			{
				cout << "If you do this:" << endl;
                                cout << "You will be charged $" << buildingInfo(1, buildingNum) * value << " ." << endl;
                                cout << "You will have " << building[buildingNum] + value << " levels in your " << getObjectName(1, buildingNum) << endl;
                                cout << "Do you wish to do this (true/false): ";
                                cin >> correctChoice;
				if (correctChoice == true)
				{
				building[buildingNum] += value;
				money -= buildingInfo(0, buildingNum);
				return building[buildingNum];
				}
			}
			else 
			{
				return -1;
			}
		}
		else
		{
			return -2;
		}
		}
		}
		else
		{
			cout << "<ERROR!> <Wrong BuildingNumber Was entered.>" << endl;
		}
		break;
	case 1:
		if (building[buildingNum] - value >= 0)
		{
			building[buildingNum] -= value;
			return building[buildingNum];
		}
		else
		{
			return -1;
		}
		break;
        case 2:
		if (value >= 0)
		{
			building[buildingNum] = value;
			return building[buildingNum];
		}
                else
                {
			return -1;
		}
                break;
        default:
		return -1;
		break;
    }
	return -1;
}

void city::getBlacksmithBonus()
{
	if (blacksmithTotal() < 100)
	{
		money += blacksmithTotal();
	}
	else
	{
	    money += (int) blacksmithTotal() * 0.75;
	}
	return;
}
