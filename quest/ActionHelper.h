#pragma once
#include "Boss.h"
#include "Mob.h"
#include "Weapon.h"
#include "Armor.h"
#include "User.h"
#include <vector>

class ActionHelper
{
	private:
		int playerLevel = 1;
		User* player;

		vector<Weapon*> marketPlaceWeapon(int weaponListSize) {
			// TO DO message
			vector<Weapon*> weaponList = {};
			for (int i = 0; i < weaponListSize; i++) {
				weaponList.push_back(new Weapon(this->playerLevel));
			}

			return weaponList;
		}

		vector<Armor*> marketPlaceArmor(int armorListSize) {
			// TO DO message
			vector<Armor*> armorList = {};
			for (int i = 0; i < armorListSize; i++) {
				armorList.push_back(new Armor(this->playerLevel));
			}

			return armorList;
		}

		void getMoney() {
			this->player->changeMoney(300);
		}

		void criminalScum() {
			this->player->changeMoney(-(this->player->getMoney() / 2));
		}

		void crazyMashrooms() {
			if (this->getPercent(100) >= 50) {
				this->player->changeStrenght(this->getMashroomsStats(true));
			}
			else {
				this->player->changeStrenght(this->getMashroomsStats());
				//this->player->set();
			}
		}

		int getMashroomsStats(bool flag = false) {
			int increment = 1;

			if (!flag) {
				increment = -1;
			}

			int percent = this->getPercent(100);
			if (percent <= 30) {
				return 1 * increment;
			}
			else if (percent > 30 && percent <= 80) {
				return 2 * increment;
			}
			else {
				return 3 * increment;
			}
		}

		int getPercent(int limit, int offset = 1) {
			return rand() % limit + offset;
		}

	public:
		ActionHelper(User* player) {
			this->playerLevel = player->getLevel();
			this->player = player;
		}

		Mob* boutMob() {
			// TO DO message
			// TO DO battle
			return new Mob(this->playerLevel);
		}

		Boss* boutBoss() {
			// TO DO message
			// TO DO battle
			return new Boss(this->playerLevel);
		}



		void meetTrader() {

		}

		void randomEvent() {

			/*if () {
				this->criminalScum();
			}
			else if () {
				this->getMoney();
			}
			else if () {

			}
			else if () {

			}
			else if () {

			}*/
			//Ловушка -5% hp
			//Чудо грибы +/- сила/ловкость
			//Растяпа(Персонаж видит реку, решает искупаться и пока он купаеться его вещи ворую гуси)
		}

		void hideTreasure() {
			//New weapon +1/2 lvl
			//New armor +1/2 lvl
			//Strenght potion + 1-5 strenght
			//Agility potion + 1-5 agility
			//Money 2000
		}

		void voidAction() {
			//
			//
			//
		}
};

