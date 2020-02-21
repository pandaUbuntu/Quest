#include "Npc.h"

class Mob : public Npc
{
	private:
		string sub[7] = {"�����", "�������", "�������", "������", "������", "�������", "���������"};
		string nameList[24] = {"�������", "������", "�������", "�����", "�������", "�������", "��������",
							   "�������", "������", "�������", "��������", "��������", "�������", "�������",
							   "��������", "�����������", "������������", "���������", "��������", "�����", 
							   "�������", "�������", "���", "�����"};

		string phraseStart[4] = {"�� �� ����?", "�� �����?", "�� �� ������� ���� ����", "���� � ������� ��� ����������"};
		string phraseRandom[4] = {"�� �������, �� ����� �����?", "�� ������ ��� ���������� ������ �� ����, � �� ��������� � ����", "������� ���� ��� � �� �����, ����� ����", "����!!!!1111"};

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
