#include "Npc.h"

class Mob : public Npc
{
	private:
		string sub[7] = {"Милый", "Пожилой", "Ужасный", "Слабый", "Мастер", "Побитый", "Серьезный"};
		string nameList[24] = {"Василий", "Химера", "Слизень", "Зомби", "Альпака", "Двойник", "Пацанчик",
							   "Чувачек", "Барыга", "АПАСНЫЙ", "Странник", "Вздутень", "Учитель", "Грешник",
							   "Выхухоль", "Коловрутень", "ПсевдоГигант", "Волшебник", "Школьник", "Титан", 
							   "Чувырло", "Ногожуй", "Кот", "Гений"};

		string phraseStart[4] = {"Шо тэ нада?", "Шо опять?", "Ты не достоин моей силы", "Дамы и господа бой начинается"};
		string phraseRandom[4] = {"Ты победил, но какой ценой?", "Ты должен был возглавить борьбу со злом, а не примкнуть к нему", "Передай маме что я ее любил, твоей маме", "Аргх!!!!1111"};

		string generateName() {
			return sub[rand() % 7] + " " + nameList[rand() % 24];
		}

	public:
		Mob(int level)
		{
			this->setName(this->generateName());
			this->generateCharacters(level);
		}
	
		string sayStart() {
			return phraseStart[rand() % 4];
		}

		string sayRandom() {
			return phraseRandom[rand() % 4];
		}
};
