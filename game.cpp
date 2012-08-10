
#include "game.h"
#include <iostream>
using namespace std;

//constructor
game::game() {
	game_tree = new binary_tree;
}

//destructor
game::~game() {
	game_tree = NULL;
}

//insert
int game::insert(char new_data[]) {
	game_tree -> insert(new_data);
}

//retrieve
char * game::retrieve(char search_key[], char * &blank_array, int &num_matches) {
	game_tree -> retrieve(search_key, blank_array, num_matches);
}

//remove
int game::remove(char search_key[]) {
	game_tree -> remove(search_key);
}

//display
void game::display() {
	game_tree -> display();
}
