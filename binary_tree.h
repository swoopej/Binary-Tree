
#ifndef BINARY_H_INCLUDED
#define BINARY_H_INCLUDED

#include <iostream>
#include <cstring>
using namespace std;

//node struct
struct node {
	node();
	char * data;
	node * left_ptr;
	node * right_ptr;
};

class binary_tree {
public:
	binary_tree();
	~binary_tree();
	//public functions with node arguments
	int insert(char new_data[]);
	int remove(char search_key[]);
	char * retrieve(char search_key[], char * &blank_array);
	//display with no args
	void display();

private:
	//private functions with node arugments
	int pvt_insert(node * &root, char new_data[]);
	int pvt_remove(node * &root, char search_key[]);
	char * pvt_retrieve(node * &root, char search_key[], char * &blank_array);
	void display_in_order(node * &root);
	node * search(node * & current, char search_key[]);
	int find_in_order(node * &current); //finds the in order successor for the remove function
	node * root;

};



#endif
