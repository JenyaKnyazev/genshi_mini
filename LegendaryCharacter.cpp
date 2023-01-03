#include "LegendaryCharacter.h"
LegendaryCharacter::LegendaryCharacter(char* name, char* location, Element type, Weapon weapon, char* eq_weapon, char* signatureWeapon) 
:Character(name,location,type,weapon,eq_weapon,5){
	this->signatureWeapon = _strdup(signatureWeapon);
}
LegendaryCharacter::~LegendaryCharacter() {
	free(this->signatureWeapon);
}
void LegendaryCharacter::Attack() {
	Character::Attack();
	std::cout << this->get_name() << " has a Signature Weapon equipped! Double demage!\n";
}
void LegendaryCharacter::print() {
	Character::print();
	for(int i=0;signatureWeapon[i];i++)
		if (signatureWeapon[i] == '\n') {
			signatureWeapon[i] = 0;
			break;
		}
	std:: cout << this->signatureWeapon << std::endl;
}