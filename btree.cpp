#include <iostream>
using namespace std;

struct node {
	int value;
	node *left;
	node *right;
};

class Btree {
	private:
		node *root;
		void insert(int key, node *next);
		node *search(int key, node *next);
		void print(node *lnexteaf);
	public:
		Btree() { root = NULL; };
		~Btree() { destroy(root); };
		void destroy(node *next);
		void insert(int key);
		node *search(int key);
		void print();
};

void Btree::destroy(node *next) {
	if (next != NULL) {
		destroy(next->left);
		destroy(next->right);
		delete next;
	}
}

void Btree::insert(int key, node *next) {
	if (key < next->value) {
		if (next->left != NULL)	{
			insert(key, next->left);
		}	else {
			next->left = new node;
			next->left->value = key;
			next->left->left = NULL;
			next->left->right = NULL;
		}
	}
	else if (key >= next->value) {
		if (next->right != NULL) {
			insert(key, next->right);
		}	else {
			next->right = new node;
			next->right->value = key;
			next->right->right = NULL;
			next->right->left = NULL;
		}
	}
}

void Btree::insert(int key) {
	if (root != NULL)	{
		insert(key, root);
	}	else {
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node *Btree::search(int key, node *next) {
	if (next != NULL)	{
		if (key == next->value)	{
			return next;
		}
		if (key < next->value) {
			return search(key, next->left);
		}	else {
			return search(key, next->right);
		}
	}	else {
		return NULL;
	}
}

node *Btree::search(int key) {
	cout << "dssdd";
	return search(key, root);
}

void Btree::print() {
	print(root);
	cout << "\n";
}

void Btree::print(node *next) {
	if (next != NULL) {
		print(next->left);
		print(next->right);
		cout << next->value << ",";
	}
}

int main() {
	Btree *tree = new Btree();

	tree->insert(10);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	tree->insert(18);
	tree->print();
	tree->search(10);
	delete tree;
}