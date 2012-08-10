
# include "binary_tree.h"
# include <iostream>
using namespace std;

class game {
public:
	game();
	~game();
	int insert(char new_data[]);
	char * retrieve(char search_key[], char * &blank_array, int &num_matches);
	int remove(char search_key[]);
	void display();

private:
	binary_tree * game_tree; //pointer to root
};
