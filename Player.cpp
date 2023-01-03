#define _CRT_SECURE_NO_WARNINGS
#include "Player.h"
Player::Player() {
	this->activeCharacters = new Character*[4];
	this->data = nullptr;
	this->data_size = 0;
	for (int i = 0; i < 4; i++)
		activeCharacters[i] = nullptr;
}
Player::~Player() {
	if (data_size) {
		for (int i = 0; i < data_size; i++)
			delete data[i];
		delete[]data;
	}
	delete[] activeCharacters;
}
void Player::add_character_to_data() {
	char name[100];
	char location[100];
	char weapon_name[100];
	char sig_weapon[100];
	Element element;
	Weapon weapon;
	int is_leg=0;
	Character* p;
	cout << "enter charater name: ";
	fgets(name,100,stdin);
	name[strlen(name) - 1] = 0;
	cout << "enter character location: ";
	fgets(location, 100, stdin);
	location[strlen(location) - 1] = 0;
	cout << "enter weapon name: ";
	fgets(weapon_name, 100, stdin);
	cout << "enter element type 0-6:\n";
	//Anemo,Pyro,Cyro,Hydro,Electro,Geo,Dendro
	cout << "0 = Anemo\n1 = Pyro\n2 = Cyro\n3 = Hydro\n4 = Electro\n5 = Geo\n6 = Dendro\n";
	scanf("%d", &element);
	getchar();
	cout << "enter weapon type 0-6:\n";
	//Sword,Polearm,Catalyst,Claymore,Bow
	cout << "0 = Sword\n1 = Polearm\n2 = Catalyst\n3 = Clymore\n4 = Bow\n";
	scanf("%d", &weapon);
	getchar();
	cout << "is the character is legendary for legendary enter 1: ";
	scanf("%d", &is_leg);
	getchar();
	if (is_leg==1) {
		cout << "enter signature weapon name: ";
		fgets(sig_weapon, 100, stdin);
		p = new LegendaryCharacter(name, location, element, weapon, weapon_name, sig_weapon);
	}
	else {
		p = new EpicCharacter(name, location, element, weapon, weapon_name);
	}
	Character** temp = data;
	data = new Character *[++data_size];
	for (int i = 0; i < data_size - 1; i++)
		data[i] = temp[i];
	data[data_size - 1] = p;
}
void Player::add_character_to_active() {
	char name[100];
	int pos;
	Character* p=nullptr;
	bool is_found = false;
	cout << "enter character name to move to active or switch inside active\n";
	fgets(name, 100, stdin);
	name[strlen(name) - 1] = 0;
	cout << "enter character position 1-4: ";
	scanf("%d", &pos);
	getchar();
	for(int i=0;i<data_size;i++)
		if (strcmp(data[i]->get_name(), name)==0) {
			p = data[i];
			is_found = true;
			break;
		}
	if (!is_found) {
		cout << "Character not found\n";
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (activeCharacters[i] != nullptr && strcmp(activeCharacters[i]->get_name(), name) == 0) {
			Character* t = activeCharacters[i];
			activeCharacters[i] = activeCharacters[pos-1];
			activeCharacters[pos-1] = t;
			cout << "switched between character at positon: " << pos + 1 << "and character at position: " << i + 1<<endl;
			return;
		}
	}
	activeCharacters[pos - 1] = p;
	cout << p->get_name() << " from data is in position: " << pos << endl;
}
void Player::show_active() {
	for (int i = 0; i < 4; i++) {
		printf("1: ");
		if (activeCharacters[i] == nullptr)
			printf("Empty\n");
		else
			activeCharacters[i]->print();
	}
}
void Player::show_data() {
	if (data_size == 0)
		printf("The data is empty\n");
	else {
		for (int i = 0; i < data_size; i++)
			data[i]->print();
	}
}
void Player::evaluate() {
	for (int i = 0; i < 4; i++) {
		if (activeCharacters[i] != nullptr)
			activeCharacters[i]->Attack();
	}
	printf("\nPassable Elements Reactions:\n");
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			if (i!=j&&activeCharacters[i] != nullptr && activeCharacters[j] != nullptr) {
				Element a, b;
				a = activeCharacters[i]->get_element_type();
				b = activeCharacters[j]->get_element_type();
				if (a == Cyro && b == Anemo)
					printf("Blizzard\n");
				else if (a == Dendro && b == Pyro)
					printf("Burn\n");
				else if (a == Geo && (b == Cyro || b == Electro || b == Hydro || b == Pyro))
					printf("Crystalize\n");
				else if (a == Geo && b == Anemo)
					printf("Dust\n");
				else if (a == Electro && b == Hydro)
					printf("Electro-Charged\n");
				else if (a == Cyro && b == Hydro)
					printf("Frozen\n");
				else if (a == Geo && b == Pyro)
					printf("Magma\n");
				else if (a == Cyro && b == Pyro)
					printf("Melt\n");
				else if (a == Geo && b == Hydro)
					printf("Mud\n");
				else if (a == Electro && b == Pyro)
					printf("Overloaded\n");
				else if (a == Dendro && b == Hydro)
					printf("Poison\n");
				else if (a == Geo && b == Cyro)
					printf("Shatter\n");
				else if (a == Cyro && b == Electro)
					printf("Superconduct\n");
				else if (a == Anemo && (b == Cyro || b == Electro || b == Hydro || b == Pyro))
					printf("Swirl\n");
				else if (a == Geo && b == Dendro)
					printf("Thorn\n");
				else if (a == Hydro && b == Pyro)
					printf("Vaporize\n");
			}
		}
	for (int i = 0; i < 4; i++) {
		int count = 1;
		for (int j = i + 1; j < 4; j++)
			if (activeCharacters[i] != nullptr && activeCharacters[j] != nullptr) {
				if (strcmp(activeCharacters[i]->get_location(), activeCharacters[j]->get_location()) == 0)
					count++;
			}
		if (count > 1) {
			printf("%d Characterws from the same location:\nadding %d% coordination\n", count, count * 10);
		}
		if (count + i == 4)
			break;
	}
}
void Player::edit_weapon() {
	char name[100];
	char wea[100];
	cout << "enter character name: ";
	fgets(name, 100, stdin);
	cout << "enter new weapon name: ";
	fgets(wea, 100, stdin);
	for(int i=0;i<data_size;i++)
		if (strcmp(data[i]->get_name(), name) == 0) {
			data[i]->EditWeapon(wea);
			printf("weapon edite succecfuly\n");
			return;
		}
	printf("character not found\n");
}
void Player::game() {
	int choise;
	do {
		printf("1. Add New Character to data\n");
		printf("2. Edit Weapon to character (by name)\n");
		printf("3. Edit active team (you choose who you want to swap - can be empty)\n");
		printf("\ta. Character1\n\ta. Character2\n\ta. Character3\n\ta. Character4\n");
		printf("4. Evaluate Team\n");
		printf("5.show active team\n");
		printf("6.show data\n");
		printf("7.exit\n");
		scanf("%d", &choise);
		getchar();
		switch (choise) {
		case 1:
			this->add_character_to_data();
			break;
		case 2:
			this->edit_weapon();
			break;
		case 3:
			this->add_character_to_active();
			break;
		case 4:
			this->evaluate();
			break;
		case 5:
			this->show_active();
			break;
		case 6:
			this->show_data();
			break;
		}
	} while (choise != 7);
}
