using namespace std;

#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED

class city
{
    long long money;
    int soldier[5], building[7];
    // soldier[0] = Pikeman
    // soldier[1] = Swordman
    // soldier[2] = Medic
    // soldier[3] = Archer
    // soldier[4] = Horseman
    // soldier[5] = SuperSoldier
    // building[0] = Castle
    // building[1] = Training Camp
    // building[2] = Farms
    // building[3] = blacksmith
    // building[4] = blaqcksmith
    // building[5] = blacksmith
    // building[6] = blacksmith
    // building[7] = blacksmith
    public:
        city();
        long long getMoney();
        int soldierTotal();
        int soldierCap();
        int blacksmithTotal();
        int buildingInfo(int, int);
        int soldierInfo(int, int);
        int setSoldier(int,int,int);
        int setBuilding(int,int,int);
        void getBlacksmithBonus();
};


#endif // CITY_H_INCLUDED
