#pragma once
#include "User.h"

class Tank : public User
{
	private:

	public:
		Tank() : User()
		{
			this->generateCharactersClass(15, 12, -20, 30, 0);
		}

		void levelUpClass() {
			this->levelUp(3, 1);
			this->setArmorBase(this->getArmorBase() + 10);
		}
};

