

#include "binary_tree.h"
#include <iostream>
#include <cstring>
using namespace std;

//node constructor
node::node() {
	data = NULL;
	left_ptr = NULL;
	right_ptr = NULL;
}

//class constructor
binary_tree::binary_tree() {
	root = NULL;
}

//destructor for the class
binary_tree::~binary_tree() {
	delete root -> left_ptr;
	delete root -> right_ptr;
	delete root;
}

//public insert function
int binary_tree::insert(char new_data[]) {
	pvt_insert(root, new_data);
	return 1;
}

//private insert function that requires a node argument 
int binary_tree::pvt_insert(node * &root, char new_data[]) {
	if(!root) {
		//allocate for new node
		root = new node;
		//allocate data within new node
		int x = strlen(new_data);
		root -> data = new char [x + 1];
		//copy over
		strcpy(root -> data, new_data);
		root -> left_ptr = root -> right_ptr = NULL;
	} else if(strcmp(root -> data, new_data) > 0) { //new data is less
		pvt_insert(root -> left_ptr, new_data);
	} else {
		pvt_insert(root -> right_ptr, new_data); //new data is more
	}
	return 1;
}

//search function uses recursion to find the math
node * binary_tree::search(node * &current, char search_key[]) {
	if(!current) {
		return current;
	} else if(strcmp(current -> data, search_key) == 0) { //match foudn
		return current;
	} else if (strcmp(current -> data, search_key) > 0) { //traverse left
		search(current -> left_ptr, search_key);
	} else {
		search(current -> right_ptr, search_key); //traverse right
	}
}

//public function calls the private recursive
int binary_tree::remove(char search_key[]) {
	pvt_remove(root, search_key);
}
//private recursive function
int binary_tree::pvt_remove(node * &root, char search_key[]) {
	if(!root) {
		return 0;
	} else if(strcmp(root -> data, search_key) == 0) {
		if(root -> left_ptr == NULL && root -> right_ptr == NULL) { //node has no children
			delete root;
			root = NULL;
		} else if(root -> left_ptr != NULL && root -> right_ptr == NULL) { //node has only left child
			node * temp = root -> left_ptr;
			delete root;
			root = temp;
		} else if(root -> left_ptr == NULL && root -> right_ptr != NULL) { //node has only right child
			node * temp = root -> right_ptr;
			delete root;
			root = temp;
		} else { //node has two children - need in order successor
			find_in_order(root);
		}
	} else if (strcmp(root -> data, search_key) > 0) { //traverse left
		pvt_remove(root -> left_ptr, search_key);
	} else {
		pvt_remove(root -> right_ptr, search_key); //traverse right
	}
}

//private retrieve function
char * binary_tree::retrieve(char search_key[], char * &blank_array, int &num_matches) {
	char * results = NULL; //variable to store the return of the private function
	results = pvt_retrieve(root, search_key, blank_array, num_matches);
	cout<< "Results test:"<< results;
	return results;
}

//public retrieve function
char * binary_tree::pvt_retrieve(node * &root, char search_key[], char * &blank_array, int &num_matches) {
	if(!root) {
		return 0;
	} else if(strcmp(root -> data, search_key) == 0) { //key is found
		int x = strlen(root -> data + 1);
		char * blank_array = new char[x + 1]; //allocate
		strcpy(blank_array, root -> data); //copy over to new memory
		cout<<"Copy test:"<<blank_array;
		num_matches ++;
		return blank_array; //return result
	} else if(strcmp(root -> data, search_key) > 0) {// key is less than root
		pvt_retrieve(root -> left_ptr, search_key, blank_array, num_matches);
	} else { //key is more than root
		pvt_retrieve(root -> right_ptr, search_key, blank_array, num_matches);
	}
}

//public display function calls the private one
void binary_tree::display() {
	display_in_order(root);
}

//private display function traverses recursively
void binary_tree::display_in_order(node * &root){
	if (!root) {
		return;
	} else {
		display_in_order(root -> left_ptr); //traverse left
		cout<< root -> data << endl;
		display_in_order(root -> right_ptr); //traverse right
	}
}

//function that finds and returns the in order successor of the node passed in argument
int binary_tree::find_in_order(node * &root) {
	node * current = root -> right_ptr; //traverse right one node
	node * previous = NULL;
	while (current -> left_ptr != NULL) { //while there are still more left nodes
		previous = current;
		current = current -> left_ptr;
	}
	delete root -> data; //delete root
	int x = strlen(current -> data); 
	root -> data = new char[x + 1]; //allocate memory in root
	strcpy(root -> data, current -> data); //copy over in order succesor's data
	
	//connects up if their has been any traversal
	if (previous) {
		previous -> left_ptr = current -> right_ptr;
	} else { //sets the right_ptr of root to NULL if there has not been any traversal (current has no children)
		root -> right_ptr = current -> right_ptr;
	}
	delete current;
	
}






