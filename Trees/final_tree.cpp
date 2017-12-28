#include <iostream>

using namespace std;

typedef int tree_t;

struct treenode{
	tree_t val;
	treenode* left;
	treenode* right;
};

typedef treenode* mtree;

mtree constree(tree_t el, mtree l, mtree r);

mtree instree(tree_t el, mtree t);

void printtree(mtree t);

mtree deletefromtree(tree_t el, mtree t);
mtree deleteroot(mtree t);

tree_t minvalnode(mtree t);

void deletetree(mtree t);

int n_of_nodes(mtree t);
int h_of_tree(mtree t);
bool find(tree_t el, mtree t);
int how_many_less(tree_t el, mtree t);

int main(){
	int n;
	mtree t = NULL;
	tree_t tmp;
	cout << "how many elements?" << endl;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		t = instree(tmp, t);
	}
	
	cout << endl;
	printtree(t);
	
	cout << "enter element to delete:" << endl;
	cin >> n;
	
	if( !find(n, t) ){
		cout << "this element does not exist." << endl;
	}else{
		cout << "there are " << how_many_less(n, t) << " elements whose value is less than the deleted one." << endl;
	}
	
	t = deletefromtree(n, t);
	
	cout << endl;
	printtree(t);
	
	cout << "this tree now has " << n_of_nodes << " elements." << endl;
	cout << "the tree's height is " << h_of_tree << "." << endl;
	
	deletetree(t);
	t = NULL;
	
	return 0;
}

// this function dreates a root node
// containing element el
// with l and r respectively
// as left and right subteees
mtree constree(tree_t el, mtree l, mtree r){
	mtree tmp = new treenode;
	tmp->val = el;
	tmp->left = l;
	tmp->right = r;
	return tmp;
}

//ordered insertion
mtree instree(tree_t el, mtree t){
	if(t == NULL){
		return constree(el, NULL, NULL);
	}
	else if(el < t->val){
		t->left = instree(el, t->left);
		return t;
	}
	else{
		t->right = instree(el, t->right);
		return t;
	}
}

// useful as a seperate function
// in case the node content type
// cannot be directly printed
void printroot(mtree t){
	cout << t->val << endl;
}

// printing a tree in order:
// first print the left subtree
// then the current node
// then the right subtree
void printtree(mtree t){
	if(t != NULL){
		printtree(t->left);
		printroot(t);
		printtree(t->right);
	}
}

mtree deletefromtree(tree_t el, mtree t){
	if(t == NULL){
		return t;
	}
	else if(el == t->val){
		return deleteroot(t);
	}
	else if(el < t->val){
		t->left = deletefromtree(el, t->left);
		return t;
	}
	else{
		t->right = deletefromtree(el, t->right);
		return t;
	}
}

mtree deleteroot(mtree t){
	if(t == NULL){
		return NULL;
	}
	else if( (t->left == NULL) && (t->right == NULL) ){
		delete t;
		return NULL;
	}
	else if(t->left == NULL){
		mtree temp = t->right;
		delete t;
		return temp;
	}
	else if(t->right == NULL){
		mtree temp = t->left;
		delete t;
		return temp;
	}
	else{
		t->val = minvalnode(t->right);
		t->right = deletefromtree(t->val, t->right);
		return t;
	}
}

tree_t minvalnode(mtree t){
	if(t->left == NULL){
		return t->val;
	}
	else{
		return minvalnode(t->left);
	}
}

// delete the root after deleting the subtrees
void deletetree(mtree t){
	if(t != NULL){
		deletetree(t->left);
		deletetree(t->right);
		delete t;
	}
}

int n_of_nodes(mtree t){
	if(t == NULL){
		return 0;
	}else{
		return 1 + n_of_nodes(t->left) + n_of_nodes(t->right);
	}
}

int h_of_tree(mtree t){
	if(t == NULL){
		return 0;
	}else{
		int n = h_of_tree(t->left);
		int m = h_of_tree(t->right);
		if(n >= m){
			return n+1;
		}else{
			return m+1;
		}
	}
}

bool find(tree_t el, mtree t){
	if(t == NULL){
		return false;
	}
	else if(el == t->val){
		return true;
	}
	else if(el < t->val){
		return find(el, t->left);
	}
	else{
		return find(el, t->right);
	}
}

int how_many_less(tree_t el, mtree t){
	if(t == NULL){
		return 0;
	}
	else if(t->val < el){
		return 1 + how_many_less(el, t->left) + how_many_less(el, t->right);
	}
	else{
		return how_many_less(el, t->left);
	}
}
