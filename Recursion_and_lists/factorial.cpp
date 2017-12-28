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
void deallocate_r_rec_wrong(mlist& l);

int mfact(int n);

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

// in what sense is this version wrong?
// (what does it do differently
// from what we would expect and why?
void deallocate_r_rec_wrong(mlist& l){
	if(l != NULL){
		mlist nextl = l->next;
		delete l;
		deallocate_r_rec_wrong(nextl);
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
