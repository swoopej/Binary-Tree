
# include "binary_tree.h"
# include <iostream>
using namespace std;


class app {
public:
	app();
	~app();
	int insert(char new_data[]);
	char * retrieve(char search_key[], char * &blank_array, int &num_matches);
	int remove(char search_key[]);
	void display();

private:
	binary_tree * app_tree; //node to point to the root
};
