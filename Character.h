#ifndef character_h
#define character_h
#include "Weapon.h"
#include "Element.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>
class Character {
	char* name;
	char* location;
	Element type;
	Weapon WeaponType;
	char* equippedWeapon;
	int stars;
public:
	Character(char* name,char* location,Element type,Weapon weapon,char* eq_weapon,int stars);
	virtual ~Character();
	char* get_name();
	char* get_location();
	Element get_element_type();
	Weapon get_weapon_type();
	char* get_eq_weapon();
	int get_stars();
	virtual void Attack();
	void EditWeapon(char* weapon);
	void virtual print();
};
#endif