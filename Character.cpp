#include "Character.h"
#include <stdio.h>
Character::Character(char* name, char* location, Element type, Weapon weapon, char* eq_weapon, int stars) {
	this->name = _strdup(name);
	this->location = _strdup(location);
	this->type = type;
	this->WeaponType = weapon;
	this->equippedWeapon = _strdup(eq_weapon);
	this->stars = stars;
}
Character::~Character() {
	free(name);
	free(location);
	free(equippedWeapon);
}
char* Character::get_name() {
	return _strdup(this->name);
}
char* Character::get_eq_weapon() {
	return  _strdup(this->equippedWeapon);
}
char* Character::get_location() {
	return _strdup(this->location);
}
int Character::get_stars() {
	return this->stars;
}
Weapon Character::get_weapon_type() {
	return this->WeaponType;
}
Element Character::get_element_type() {
	return this->type;
}
void Character::EditWeapon(char* weapon) {
	free(this->equippedWeapon);
	this->equippedWeapon = _strdup(weapon);
}
void Character::Attack() {
	std::cout << this->name;
	switch (WeaponType) {
		case Sword:
			std::cout << " swing swifty the sword\n";
			break;
		case Polearm:
			std::cout << " agile with polearm\n";
			break;
		case Bow:
			std::cout << " shot from afar with the bow\n";
			break;
		case Claymore:
			std::cout << " swing the heavy claymore\n";
			break;
		case Catalyst:
			std::cout << " cast spells with catalyst";
			break;
	}
}
void Character::print() {
	const char* elem="none";
	switch (this->type) {
	case Anemo:
		elem = "Anemo";
		break;
	case Pyro:
		elem = "Pyro";
		break;
	case Cyro:
		elem = "Cyro";
		break;
	case Hydro:
		elem = "Hydro";
		break;
	case Electro:
		elem = "Electro";
		break;
	case Geo:
		elem = "Geo";
		break;
	case Dendro:
		elem = "Dendro";
		break;
	}
	const char* wea="none";
	//Sword,Polearm,Catalyst,Claymore,Bow
	switch (this->WeaponType) {
	case Sword:
		wea = "Sword";
		break;
	case Polearm:
		wea = "Polearm";
		break;
	case Catalyst:
		wea = "Catalyst";
		break;
	case Claymore:
		wea = "Claymore";
		break;
	case Bow:
		wea = "Bow";
		break;
	}
	for (int i = 0; name[i]; i++)
		if (name[i] == '\n') {
			name[i] = 0;
			break;
		}
	for(int i=0;equippedWeapon[i];i++)
		if (equippedWeapon[i] == '\n') {
			equippedWeapon[i] = 0;
			break;
		}
	for(int i=0;location[i];i++)
		if (location[i] == '\n') {
			location[i] = 0;
			break;
		}
	printf("%s\t\t%d %s %s\t%s\t%s\t",this->name,this->stars,elem,wea,this->location,this->equippedWeapon);
}