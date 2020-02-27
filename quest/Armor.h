#pragma once
#include "Item.h"

class Armor: public Item
{
	private:
		int defence = 0;
		int subPoint = 0;

		int constPrice = 40;
		int constDefence = 20;
	
		int sizeSub = 12;
		string sub[12] = { "Разрушающийся", "Великий", "Поношеный", "Поцарапанный",
						  "Дырявый", "Куриный", "Бронированый", "Кирпичный",
						  "Перфорированый", "Новый", "Покусаный", "Пенопластовый"};
	
		int typeSize = 6;
		string typeList[6] = { "Нагрудник", "Бригандина", "Кольчуга", "Рубашка", "Латы", "Шосы" };
	
		int sizeName = 10;
		string nameList[10] = { "Карлик", "Великан", "Скафандр", "Защитник", "Носок", "Сссссссс", "Хищник",
			"Труселя", "Коробка", "Консерва" };

		string generateName() {
			this->subPoint = this->getPercent(this->sizeSub, 0);

			return sub[this->subPoint] + " " + nameList[rand() % this->sizeName];
		}

		string generateType() {
			return typeList[rand() % this->typeSize];
		}

		void generateCharaters(int level) {
			int increaseDefence = 20;

			if (this->subPoint == 0 || this->subPoint == 4 ) {
				increaseDefence = 5;
			}
			else if (this->subPoint == 11) {
				increaseDefence = 7;
			}
			else if (this->subPoint == 5) {
				increaseDefence = 3;
			}
			else if (this->subPoint == 1 || this->subPoint == 9 || this->subPoint == 6) {
				increaseDefence *= 2;
			}

			this->setDefence(increaseDefence * level);
			this->setPrice(this->getDefence() * this->constPrice);

			int tmpLimit = this->getDefence() / this->constDefence;
			tmpLimit += (rand() % 2 == 1) ? (rand() % 10) : (rand() % 5) * -1;
			this->setAgilityLimit((tmpLimit < 0) ? tmpLimit : 10);

			tmpLimit += (rand() % 2 == 1) ? (rand() % 10) : (rand() % 5) * -1;
			this->setStrenghtLimit((tmpLimit < 0) ? tmpLimit : 10);
		}

	public:
		void setDefence(int defence) { this->defence = defence; }
		int getDefence() { return this->defence; }
	
		Armor(int level) {
			this->setName(this->generateName());
			this->setType(this->generateType());
			this->generateCharaters(level);
		}
};

