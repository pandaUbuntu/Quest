#include <string>

using namespace std;

class Npc
{
	private:
		string name = "";

		int level = 0;
		int hp = 0;
		int damage = 0; 
		int armor = 0;
		int criticalChance = 0;
		int money = 0;
		int playerXp = 0;

		int generateRandomLevel(int level) {
			int percent = rand() % 100 + 1;

			if (level > 1) {
				if (percent >= 1 && percent <= 10) {
					level -= 1;
				}
				else if (percent > 85 && percent <= 100) {
					level += 2;
				}
				else if (percent > 60 && percent <= 85) {
					level += 1;
				}
			}
			else {
				if (percent > 95 && percent <= 100) {
					level += 2;
				}
				else if (percent > 60 && percent <= 85) {
					level += 1;
				}
			}

			return level;
		}

		bool generateFlag() {
			return (rand() % 2 == 1) ? true : false;
		}

	public:

		Npc() {}

		void setName(string name) { this->name = name; }
		string getName() { return this->name; }

		void setLevel(int level) { this->level = level; }
		int getLevel() { return this->level; }
		void setHp(int hp) { this->hp = hp; }
		int getHp() { return this->hp; }
		void setDamage(int damage) { this->damage = damage; }
		int getDamage() { return this->damage; }
		void setArmor(int armor) { this->armor = armor; }
		int getArmor() { return this->armor; }
		void setCriticalChance(int critical) { this->criticalChance = critical; }
		int getCriticalChance() { return this->criticalChance; }
		void setMoney(int money) { this->money = money; }
		int getMoney() { return this->money; }
		void setPlayerXp(int playerXp) { this->playerXp = playerXp; }
		int getPlayerXp() { return this->playerXp; }

		void generateCharacters(int level, bool isBoss = false) {
			level = this->generateRandomLevel(level);

			int bossHpIncrease = 1;
			int bossDamageIncrease = 1;
			int bossArmorIncrease = 1;
			int bossCriticalChanceIncrease = 1;
			int bossMoneyIncrease = 1;
			int bossPlayerXpIncrease = 1;

			if (isBoss) {
				bossHpIncrease = 5;
				bossDamageIncrease = 3;
				bossArmorIncrease = 3;
				bossCriticalChanceIncrease = 2;
				bossMoneyIncrease = 10;
				bossPlayerXpIncrease = 10;
			}

			this->setLevel(level);

			int hp = level * 300;
			hp += this->generateFlag() ? (rand() % 5) * 50 : ((rand() % 5) * 50) * -1;
			this->setHp(hp * bossHpIncrease);

			int damage = this->getHp() / 10;
			damage = this->generateFlag() ? (rand() % 5) * 5 : ((rand() % 5) * 5) * -1;
			this->setDamage(damage * bossDamageIncrease);

			int armor = this->getHp() / 100;
			this->setArmor(armor * bossArmorIncrease);

			int criticalChance = 2 * bossCriticalChanceIncrease;
			criticalChance += rand() % 5 ;
			this->setCriticalChance(criticalChance);

			int money = level * 50;
			money += this->generateFlag() ? (rand() % 300) : (rand() % 50) * -1;
			this->setMoney(money * bossMoneyIncrease);

			this->setPlayerXp((level * 50) * bossPlayerXpIncrease);
		}

		int attack() {
			int percent = rand() % 100 + 1;
			int tmpDamage = this->getDamage();

			if (percent <= this->getCriticalChance()) {
				tmpDamage = tmpDamage + tmpDamage / 2;
			}

			return tmpDamage;
		}

		bool takeDamage(int damage) {
			int hp = this->getHp() - (damage - this->getArmor());
			this->setHp(hp);

			if (this->getHp() <= 0) {
				return this->death();
			}

			return false;
		}

		bool death() {
			return true;
		}
};

