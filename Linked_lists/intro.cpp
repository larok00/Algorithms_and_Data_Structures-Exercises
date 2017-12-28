#include <iostream>

using namespace std;

void conclude();

struct intlist{
	int val;
	intlist* next;
};

int main() {

	intlist* l = NULL;

	int n, el;
	cout << "how many elements?" << endl;
	cin >> n;

	for (int i = 0; i<n; i++) {
		cout << "enter element " << i + 1 << endl;
		cin >> el;

		intlist* tmp = new intlist;

		tmp->val = el;
		//   same as (*tmp).item = el;

		tmp->next = l;
		//   same as (*tmp).next = el;
		l = tmp;
	}
	cout << endl;
	intlist* list = l;
		while (list != NULL) {
			cout << list-> val << endl;
			list = list->next;
		}



	while (l != NULL) {
		intlist* tmpl = l->next;
		delete l;
		l = tmpl;
	}

	conclude();

	return 0;
}

void conclude() {
	cout << endl << "L_A_I" << endl;
	cout << "	-Tyl-e" << endl;
}

