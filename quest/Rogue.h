#pragma once
#include "User.h"

class Rogue : public User
{
	private:

	
	public:
		Rogue() : User()
		{
			this->generateCharactersClass(8, 20, 20, -20, 40);
		}

		void levelUpClass() {
			this->levelUp(1, 3);
			this->setDodge(this->getDodge() + 2);
			this->setCriticalChance(this->getCriticalChance() + 2);
		}
};

