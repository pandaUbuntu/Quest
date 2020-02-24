#pragma once
#include "Npc.h"

class Boss : public Npc
{
	private:
		bool isHeal = false;
		int subPosition = 0;

		int sizeSub = 8;
		string sub[8] = { "Милый", "Пожилой", "Ужасный", "Слабый", "Мастер", "Побитый", "Серьезный", "Унылый" };
	
		int sizeName = 15;
		string nameList[15] = { "Рошан", "Рокки Бальбоа", "Душегуб", "Светлана", "Лампочка", "Марковка", "Рукожопый Жопорук",
							   "Карась", "Капатыч", "Котик", "Евкакий", "Амоновец", "Любая дичь", "Леприкон", "Картошка" };
	
		string phraseStart[4] = { "", "", "", "" };
		string phraseRandom[4] = { "", "", "", "" };
	
		string generateName() {
			this->subPosition = rand() % sizeSub;
			return sub[subPosition] + " " + nameList[rand() % sizeName];
		}

	public:
		Boss(int level)
		{
			this->setName(this->generateName());
			this->generateCharacters(level, true);
		}

		bool takeDamage(int damage) {
			int percent = this->getPercent(100);

			if ((this->getHpGeneral() / 2 <= this->getHp()) && (this->subPosition == 1 || this->subPosition == 5) && percent <= 5) {
				return this->insult();
			}

			int tmpDamage = (damage - this->getArmor()) * this->ultimateDefense();

			if (tmpDamage < 0) { tmpDamage = 0; }

			int hp = this->getHp() - tmpDamage;
			this->setHp(hp);

			if ((this->getHpGeneral() / 5 <= this->getHp()) && !isHeal && (percent >= 1 && percent <= 10)) {
				this->selfHeal();
				isHeal = true;
			}

			if (this->getHp() <= 0) {
				return this->death();
			}

			return false;
		}

		int ultimateDefense() {
			if (this->getPercent(100) == 34) {
				return 10;
			}

			return 1;
		}

		void selfHeal() {
			this->setHp(this->getHpGeneral());
		}

		bool insult() {
			return true;
		}


};

