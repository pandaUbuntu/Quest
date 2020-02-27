#pragma once
#include "User.h"

class DamageDealer : public User
{
	private:
	
	
	public:
		DamageDealer() : User()
		{
			this->generateCharactersClass(20, 10, 40, 0, 15);
		}

		void levelUpClass() {
			this->levelUp(2, 2);
			this->setDamageBase(this->getDamageBase() + 10);
		}
};

