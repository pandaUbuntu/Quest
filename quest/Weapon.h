#pragma once
#include "Item.h"

class Weapon : public Item
{
	private:
		int damage = 0;
		int subPoint = 0;

		int sizeSub = 12;
		string sub[12] = {"Эпичный", "Легендарный", "Анигиляторный", "Галогенный",
						  "Гелевый", "Мифриловый", "Двухсторонний", "Безлезвенный", 
						  "Обычный", "Воображаемый", "Мохнатый", "Убитый"};

		int typeSize = 6;
		string typeList[6] = { "Катана", "Посох", "Кунаи", "Ствол", "Кинжал", "Камень" };

		int sizeName = 10;
		string nameList[10] = {"Без меня", "Пятница", "Андрей", "Расщепитель", "Суи", "Бейся сам", "Швабра", 
			"Мрак", "Ногоперебиватель", "Демонсдох"};

		string generateName() {
			int subPercent = this->getPercent(100);

			if (subPercent <= 10) {
				int tmpPercent = this->getPercent(100);
				if (tmpPercent <= 45) {
					this->subPoint = 0;
				}
				else if (tmpPercent > 45 && tmpPercent <= 90) {
					this->subPoint = 1;
				}
				else {
					this->subPoint = 2;
				}
			}
			else {
				this->subPoint = (rand() % (this->sizeSub - 3)) + 3;
			}

			return sub[this->subPoint] + " " + nameList[rand() % sizeName];
		}

		string generateType() {
			return typeList[rand() % this->typeSize];
		}

		void generateCharaters(int level) {
			int constDamage = 10;
			int percent = this->getPercent(100);

			if (this->subPoint == 0 || this->subPoint == 1) {
				constDamage *= 3;
			}
			else if (this->subPoint == 4 || this->subPoint == 7 || this->subPoint == 11) {
				constDamage = 3;
			}
			else if (this->subPoint == 2) {
				constDamage *= 5;
			}
			else if (this->subPoint == 9) {
				constDamage = 0;
			}

			this->setDamage(constDamage * level);
			this->setPrice(this->getDamage() * 20);

			int tmpLimit = this->getDamage() / 20;
			tmpLimit += (rand() % 2 == 1) ? (rand() % 10) : (rand() % 5) * -1;
			this->setAgilityLimit((tmpLimit < 0) ? tmpLimit : 10);

			tmpLimit += (rand() % 2 == 1) ? (rand() % 10) : (rand() % 5) * -1;
			this->setStrenghtLimit((tmpLimit < 0) ? tmpLimit : 10);
		}

	public:

		void setDamage(int damage) { this->damage = damage; }
		int getDamage() { return this->damage; }

		Weapon(int level) {
			this->setName(this->generateName());
			this->setType(this->generateType());
			this->generateCharaters(level);
		}

		
};

