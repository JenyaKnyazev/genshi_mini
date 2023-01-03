#include "Character.h"
class LegendaryCharacter:public Character{
	char* signatureWeapon;
public:
	LegendaryCharacter(char* name, char* location, Element type, Weapon weapon, char* eq_weapon,char* signatureWeapon);
	~LegendaryCharacter();
	void virtual Attack();
	void virtual print();
};
