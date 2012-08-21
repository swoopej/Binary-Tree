
# include "binary_tree.h"
# include <iostream>
using namespace std;


class app {
public:
	app();
	~app();
	int insert(char new_data[]);
	int remove(char search_key[]);
	char * retrieve(char search_key[], char * &blank_array);
	void display();

private:
	binary_tree * app_tree; //node to point to the root
};
