#pragma once
#include "Weapon.h"
#include "Armor.h"
#include <iostream>

class User
{
	private:
		/* Base characters */
		int expirience = 0;
		int level = 1;

		int strenght = 10;
		int agility = 10;
		int hpGeneral = 100 * this->strenght;
		int hp = this->hpGeneral;
		int damageBase = 0;
		int armorBase = 0;
		int dodge = 10;
		int mpGeneral = 100;
		int mp = 100;
		int regeneration = 10;
		/* End Base characters */

		int money = 0;
		int criticalChance = 0;

		Armor* armor;
		Weapon* weapon;

		bool generateFlag() {
			return (rand() % 2 == 1) ? true : false;
		}

		void replaceHp() {
			this->setHpGeneral(this->getStrenght() * 100);
			this->setHp(this->getHpGeneral());
		}

	protected:
		int getPercent(int limit, int offset = 1) {
			return rand() % limit + offset;
		} 

		int getSummaryDamage() {
			return this->strenght * 5 + this->weapon->getDamage() + damageBase;
		}

		int getSummaryDefence() {
			return this->strenght * 2 + this->armor->getDefence() + this->agility * 2 + armorBase;
		}

		int getSummaryCriticalChance() {
			int tmpCritical = 5 + rand() % 5;
			return tmpCritical + this->agility / 2;
		}

		void generateCharactersClass(int strenght, int agiglity, int damage, int armor, int dodge) {
			this->setStrenght(strenght);
			this->setAgility(agiglity);
			this->setDamageBase(damage);
			this->setArmorBase(armor);
			this->setDodge(dodge);

			this->replaceHp();
		}

		void levelUp(int strenght, int agility) {
			this->setStrenght(this->getStrenght() + strenght);
			this->setAgility(this->getAgility() + agility);

			this->replaceHp();
		}

	public:
		User() {
			Armor* arm = new Armor(this->getLevel());
			Weapon* wpn = new Weapon(this->getLevel());
			
			this->setWeapon(wpn);
			this->setArmor(arm);

			this->generatorUser();
		};

		void setHp(int hp) { this->hp = hp; }
		int getHp() { return hp; }
		void setHpGeneral(int hpGeneral) { this->hpGeneral = hpGeneral; }
		int getHpGeneral() { return hpGeneral; }
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
		void setArmor(Armor* armor) { this->armor = armor; }
		Armor* getArmor() { return this->armor; }
		void setWeapon(Weapon* weapon) { this->weapon = weapon; }
		Weapon* getWeapon() { return this->weapon; }
		void setArmorBase(int armor) { this->armorBase = armor; }
		int getArmorBase() { return this->armorBase; }
		void setDamageBase(int damageBase) { this->damageBase = damageBase; }
		int getDamageBase() { return this->damageBase; }
		void setDodge(int dodge) { this->dodge = dodge; }
		int getDodge() { return dodge; }

		void generatorUser() {
			this->money = rand() % 10 * 100;
			this->criticalChance = this->getSummaryCriticalChance();
		}

		int attack() {
			if (this->getPercent(100) <= this->getCriticalChance()) {
				return this->getSummaryDamage() * 2;
			}

			return this->getSummaryDamage();
		}

		bool takeDamage(int damage) {
			int tmpDamage = (damage - this->getSummaryDefence());

			if (tmpDamage < 0) { tmpDamage = 0;  }

			if (this->getPercent(100) > this->dodge) {
				int hp = this->getHp() - tmpDamage;
				this->setHp(hp);
			}
			

			if (this->getHp() <= 0) {
				return this->death();
			}

			return false;
		}

		void regenerationPlayer() {
			int regenerationHp = this->hpGeneral / this->regeneration + this->hp;
			if (regenerationHp > this->hpGeneral) {
				this->hp = this->hpGeneral;
			}
			else {
				this->hp = regenerationHp;
			}

			int regenerationMp = this->mpGeneral / this->regeneration + this->mp;
			if (regenerationMp > this->mpGeneral) {
				this->mp = this->mpGeneral;
			}
			else {
				this->mp = regenerationMp;
			}
		}

		bool death() {
			return true;
		}
};

