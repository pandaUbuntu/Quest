#pragma once
#include <string>

using namespace std;

class Item
{
	private:
		int price = 0;
		string name = "";
		string type = "";
		int strenghtLimit = 0;
		int agilityLimit = 0;

	protected:
		int getPercent(int limit, int offset = 1) {
			return rand() % limit + offset;
		}

	public:
		void setPrice(int price) { this->price = price; }
		int getPrice() { return this->price; }
		void setName(string name) { this->name = name; }
		string getName() { return this->name; }
		void setType(string type) { this->type = type; }
		string getType() { return this->type; }
		void setStrenghtLimit(int strenghtLimit) { this->strenghtLimit = strenghtLimit; }
		int getStrenghtLimit() { return this->strenghtLimit; }
		void setAgilityLimit(int agilityLimit) { this->agilityLimit = agilityLimit; }
		int getAgilityLimit() { return this->agilityLimit; }
};

