#include "EpicCharacter.h"
EpicCharacter::EpicCharacter(char* name, char* location, Element type, Weapon weapon, char* eq_weapon) 
	:Character(name,location,type,weapon,eq_weapon,4)
{
}
EpicCharacter::~EpicCharacter() {
}
void EpicCharacter::print() {
	Character::print();
	std::cout << std::endl;
}