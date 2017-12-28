#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
 	
void conclude();

struct intlist{
	int val;
	intlist* next;
};

int main() {

	
	
	ifstream infile;
	string input;
	intlist element;
	intlist* l = NULL;
	intlist* tmp_list = l;
	
	cout << "Looking for a list to get things going in lonely times, if you know what I mean ;)" << endl;
	cin >> input;
	
	infile.open(input.c_str());
	
	if( !infile.is_open() ){
		cout << "could not open input file" << endl;
		exit(EXIT_FAILURE);
	}
	
	while (infile >> element.val){
		
		tmp_list = new intlist;
		
		tmp_list->val = element.val;
		tmp_list->next = l;
		l = tmp_list;
	}
	
	infile.close();
	
	cout << endl;
	tmp_list = l;
		while (tmp_list != NULL) {
			cout << tmp_list->val << endl;
			tmp_list = tmp_list->next;
		}



	while (l != NULL) {
		tmp_list = l->next;
		delete l;
		l = tmp_list;
	}

	conclude();

	return 0;
}

void conclude() {
	cout << endl << "L_A_I" << endl;
	cout << "	-Tyl-e" << endl;
}

