#include "tower.h"
#include "unit.h"
#include <string>

using namespace std;

Tower::Tower(const int& uid, const int& pos, const int& hp, const int& atkdmg, const int& atkrng,
            const int& atkspd, const int& percep, const int& atkcnt, const int& wall):
            Unit(uid, pos, hp, atkdmg, atkrng, atkspd, percep, atkcnt), wallArmour_(wall)

string Tower::serializeTower(const Tower& tower){


}
