#pragma once
#include "Weapon.h"
#include "Armor.h"
#include <iostream>

class User
{
	/*private:
		int expirience = 0;
		int level = 1;
		int strenght = 10;
		int agility = 10;
		int hpGeneral = 1000;
		int hp = 1000;
		int mpGeneral = 100;
		int mp = 100;
		int regeneration = 10;

		int money = 0;
		int criticalChance = 0;
		int damageBase = 0;
		int armorBase = 0;

		Armor armor;
		Weapon weapon;

		bool generateFlag() {
			return (rand() % 2 == 1) ? true : false;
		}

	protected:
		int getPercent(int limit, int offset = 1) {
			return rand() % limit + offset;
		} 

		int getSummaryDamage() {
			return this->getStrenght();
		}

		int getSummaryDefence() {
			return this->getStrenght();
		}

	public:
		void setHp(int hp) { this->hp = hp; }
		int getHp() { return hp; }
		void setMp(int mp) { this->mp = mp; }
		int getMp() { return hp; }
		void setLevel(int level) { this->level = level; }
		int getLevel() { return level; }
		void setMoney(int money) { this->money = money; }
		int getMoney() { return money; }
		void setStrenght(int strenght) { this->strenght = strenght; }
		int getStrenght() { return strenght; }
		void setAgility(int agility) { this->agility = agility; }
		int getAgility() { return agility; }
		void setCriticalChance(int critical) { this->criticalChance = critical; }
		int getCriticalChance() { return this->criticalChance; }


		void generatorUser() {
			this->money = rand() % 10 * 100;
			this->criticalChance = 5 + rand() % 5;
		}

		int attack() {
			if (this->getPercent(100) <= this->getCriticalChance()) {
				return this->getSummaryDamage() + (this->getSummaryDamage() / 2);
			}

			return this->getSummaryDamage();
		}

		bool takeDamage() {
			
		}

		void regeneration() {
			int regenerationHp = this->hpGeneral / 10 + this->hp;
			if (regenerationHp > this->hpGeneral) {
				this->hp = this->hpGeneral;
			}
			else {
				this->hp = regenerationHp;
			}

			int regenerationMp = this->mpGeneral / 10 + this->mp;
			if (regenerationMp > this->mpGeneral) {
				this->mp = this->mpGeneral;
			}
			else {
				this->mp = regenerationMp;
			}
		}*/
};

