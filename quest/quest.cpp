#include <iostream>
#include <time.h>
#include "Boss.h"
#include "Mob.h"
#include "Weapon.h"

int main()
{
    srand(time(0));
    setlocale(0, "ru");
    Mob* monster = new Mob(1);
    Boss* boss = new Boss(1);
    Weapon* weap = new Weapon(5);
    
    cout << "Weapon : " << weap->getName() << " damage: " << weap->getDamage() << " price: " << weap->getPrice() << endl;


   // monster->takeDamage(455);
   cout << "Boss : " << boss->getName() << " Hp: " << boss->getHp() <<  endl;
  

   cout << "Monster : " <<  monster->getName() << " Hp: " << monster->getHp() << endl;

    return 0;
}
