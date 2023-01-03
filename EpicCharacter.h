#include "Character.h"
class EpicCharacter:public Character {
public:
	EpicCharacter(char* name, char* location, Element type, Weapon weapon, char* eq_weapon);
	~EpicCharacter();
	void virtual print();
};
