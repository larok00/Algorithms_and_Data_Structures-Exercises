#include <iostream>

using namespace std;

typedef int list_t;

struct listnode{
	list_t val;
	listnode* next;
};

typedef listnode* mlist;

void consref(list_t el, mlist& l);
mlist consret(list_t el, mlist l);

mlist constail_rec(list_t el, mlist l);

void printlist_rec(mlist l);
void printrevlist_rec(mlist l);

void deallocate_r_rec(mlist& l);
mlist deallocate_c_rec(mlist l);

int mfact(int n);

int mexponent2(int n);
int length_of_list(mlist l);
int how_many(mlist l, int value);
mlist without_item(list_t el, mlist l);
void ordered_insert(list_t el, mlist& l);

int main(){
	
	mlist la = NULL;
	mlist lb = NULL;
	
	int n;
	list_t el;
	cout << "how many elements?" << endl;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		
		cin >> el;
		
		la=consret(el, la);
		lb=constail_rec(el, lb);
	}
	
	cout << endl;
	
	cout << "print in the normal order:" << endl;
	printlist_rec(la);
	cout << endl;
	printlist_rec(lb);
	
	cout << endl;
	
	cout << "print in reverse order:" << endl;
	printrevlist_rec(la);
	cout << endl;
	printrevlist_rec(lb);
	
	cout << endl;
	
	deallocate_r_rec(la);
	cout << la << endl;
	lb=deallocate_c_rec(lb);
	cout << lb << endl;
	
	return 0;
}

int mfact(int n){
	if(n == 0){
		return 1;
	}
	else{
	return n * mfact(n-1);
	}
}

int mexponent2(int n){
	if(n == 0){
		return 1;
	}
	else{
		return 2 * mexponent2(n-1);
	}
}

int length_of_list(mlist l){
	int n=0;
	
	while(l != NULL){
		n++;
		l = l->next;
	}
	
	return n;
}

int how_many(mlist l, int value){
	int n=0;
	
	while(l != NULL){
		if(l->val = value){
			n++;
		}
		l = l->next;
	}
	
	return n;
}

mlist without_item(list_t el, mlist l){
	mlist tmp = NULL;
	
	if(l != NULL && l->val != el){
		tmp = new listnode;
		tmp->val = l->val;
		tmp->next = without_item(el, l->next);
	}
	
	return tmp;
}

void ordered_insert(list_t el, mlist& l){
	if(l == NULL || l->val <= el){
		mlist tmp = new listnode;
		tmp->val = el;
		tmp->next = l;
		l = tmp;
		return;
	}
	
	ordered_insert(el, l->next);
}	

void consref(list_t el, mlist l){
	mlist tmpp = new listnode;
	tmpp->val = el;
	tmpp->next = l;
	l = tmpp;
}

mlist consret(list_t el, mlist l){
	mlist tmpp = new listnode;
	tmpp->val = mfact(el);
	tmpp->next = l;
	return tmpp;
}

//add el at the end of the list l
mlist constail_rec(list_t el, mlist l){
	if(l == NULL){
		return consret(el, l);
		// if the list empty
		// just do the usual insertion
		// at the beginning (and return the result)
	}
	else{
		l->next = constail_rec(el, l->next);
		return l;
		// otherwise return the list that is obtained
		// as a result of adding el at the end the
		// rest of the current list
	}
}

// printhead in seperate function
// is useful in case e.g. list_t is a structured type
void printhead(mlist l){
	cout << l->val << endl;
}

// "in order to print a non-empty list
// print the first element and then
// print the resy of the list"
void printlist_rec(mlist l){
	if(l != NULL){
		printhead(l);
		printlist_rec(l->next);
	}
}

// "in order to print a non-empty list
// in reversed order
// print the rest of the list
// the print the current element"
void printrevlist_rec(mlist l){
	if(l != NULL ){
		printrevlist_rec(l->next);
		printhead(l);
	}
}

void deallocate_r_rec(mlist& l){
	if(l != NULL){
		mlist tmp = l;
		l = l->next;
		delete tmp;
		deallocate_r_rec(l);
	}
}

mlist deallocate_c_rec(mlist l){
	if(l == NULL){
		return l;
	}
	else{
		mlist nextl = l->next;
		delete l;
		return deallocate_c_rec(nextl);
	}
}
