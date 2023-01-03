#include "EpicCharacter.h"
#include "LegendaryCharacter.h"
#include <stdio.h>
using namespace std;
class Player {
	Character** activeCharacters;
	Character** data;
	int data_size;
	void add_character_to_data();
	void add_character_to_active();
	void edit_weapon();
	void show_data();
	void show_active();
	void evaluate();
public:
	Player();
	~Player();
	void game();
};
