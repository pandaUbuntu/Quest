#pragma once
#include "Npc.h"

class Mob : public Npc
{
	private:
		int sizeSub = 8;
		string sub[8] = {"�����", "�������", "�������", "������", "������", "�������", "���������", "����������"};
		
		int sizeName = 24;
		string nameList[24] = {"�������", "������", "�������", "�����", "�������", "�������", "��������",
							   "�������", "������", "�������", "��������", "��������", "�������", "�������",
							   "��������", "�����������", "������������", "���������", "��������", "�����", 
							   "�������", "�������", "���", "�����"};

		int sizePhraseStart = 4;
		string phraseStart[4] = {"�� �� ����?", "�� �����?", "�� �� ������� ���� ����", "���� � ������� ��� ����������"};
		
		int sizephraseRandom = 4;
		string phraseRandom[4] = {"�� �������, �� ����� �����?", "�� ������ ��� ���������� ������ �� ����, � �� ��������� � ����", "������� ���� ��� � �� �����, ����� ����", "����!!!!1111"};

		string generateName() {
			return sub[rand() % sizeSub] + " " + nameList[rand() % sizeName];
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
