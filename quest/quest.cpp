#include <iostream>
#include <time.h>

#include "Boss.h"

int main()
{
    srand(time(0));
   // Mob* monster = new Mob(1);
    Boss* boss = new Boss();


   // monster->takeDamage(455);
    cout << boss->getHp();

   // cout << monster->getHp();

    return 0;
}
