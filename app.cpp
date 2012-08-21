
#include "app.h"
#include <iostream>
using namespace std;

//constructor
app::app() {
	app_tree = new binary_tree; //create a new binary tree
}

//destructor
app::~app() {
	app_tree = NULL;
}

//insert
int app::insert(char new_data[]) {
	app_tree -> insert(new_data);
}

//retrieve
char * app::retrieve(char search_key[], char * &blank_array) {
	app_tree -> retrieve(search_key, blank_array);
}

//remove
int app::remove(char search_key[]) {
	app_tree -> remove(search_key);
}

//display
void app::display() {
	app_tree -> display();
}
