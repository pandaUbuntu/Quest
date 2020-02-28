#include <iostream>
#include <time.h>
#include "Boss.h"
#include "Mob.h"
#include "Weapon.h"
#include "Armor.h"
#include "Tank.h"

int main()
{
    srand(time(0));
    setlocale(0, "ru");

    Mob* monster = new Mob(1);
    Boss* boss = new Boss(1);
    Tank* player = new Tank();

    cout << "Armor : " << player->getArmor()->getName() << " armor: " << player->getArmor()->getDefence() << " type: " << player->getArmor()->getType()  << endl;
    cout << "Weapon : " << player->getWeapon()->getName() << " damage: " << player->getWeapon()->getDamage() << " type: " << player->getWeapon()->getType()  << endl;
    


   // monster->takeDamage(455);
   cout << "Boss : " << boss->getName() << " Hp: " << boss->getHp() <<  endl;
   cout << "Monster : " <<  monster->getName() << " Hp: " << monster->getHp() << endl;

    return 0;
}
