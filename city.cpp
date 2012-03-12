#include "city.h"

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
	building[6] = 0;
	building[7] = 0;
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
	return building[3] + building[4] + building[5] + building[6] + building[7];
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
				case 6:
					// 1 Blacksmith level costs £350,000
					return 350000;
					break;
				case 7:
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
			case 6:
				// Each blacksmith can have 100 levels.
				return 100;
				break;
			case 7:
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
    switch (action)
    {
        case 0:
            if(soldierTotal() + value <= soldierCap() && soldierInfo(0,soldierType) * value <= money)
            {
                soldier[soldierType] += value;
                money -= soldierInfo(0,soldierType) * value;
                return soldier[soldierType];
            }
            else
            {
                return -1;
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
}

int city::setBuilding(int action, int value, int buildingNum)
{
    // action = 0 adds value to the building level. Returns -1 if not enough money or max level reached, else returns building level.
    // action = 1 subtracts value from the soldier count. Returns -1 if building level is tried to go under 0. Else returns building level.
    // action = 2 Sets the soldier count to value. Returns -1 if value is negative. Returns soldierCount.
    // action = 3 Tells the amount of soldier[soldierType].
    switch (action)
    {
        case 0:
		if(building[buildingNum] + value <= buildingInfo(1,buildingNum) && buildingInfo(0,buildingNum) <= money)
		{
			building[buildingNum] += value;
			money -= buildingInfo(0,buildingNum) * value;
			return building[buildingNum];
		}
		else
		{
			return -1;
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
