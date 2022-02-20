#include <iostream>
using namespace std;

struct avl_node
{
	int data;
	avl_node *left;
	avl_node *right;
	int height;
}*root;

class avl_tree
{
	public:
		avl_tree();
		~avl_tree();
		void insert(int);
		void remove(int);
		void display();
	private:
		void inorder(avl_node *, string, bool);
		void empty(avl_node *);
		avl_node *insert(int, avl_node *);
		int height(avl_node *);
		int bal_factor(avl_node *);
		avl_node *remove(int, avl_node *);
		avl_node *findMin(avl_node *);
		avl_node *findMax(avl_node *);
		avl_node *ll_rotation(avl_node *);
		avl_node *rr_rotation(avl_node *);
		avl_node *rl_rotation(avl_node *);
		avl_node *lr_rotation(avl_node *);
};

avl_tree::avl_tree()
{
	root = NULL;
}

avl_tree::~avl_tree()
{
	empty(root);
}

void avl_tree::insert(int x)
{
	root = insert(x, root);
}

void avl_tree::remove(int x)
{
	root = remove(x, root);
}

void avl_tree::display()
{
	inorder(root, "", true);
	cout << endl;
}

void avl_tree::inorder(avl_node *t, string indent, bool last)
{
		if (t == NULL) return;
  	cout << indent;
    if (last) {
      cout << "R----";
      indent += "   ";
    } else {
      cout << "L----";
      indent += "|  ";
    }
		cout << t->data << endl;
  	inorder(t->left, indent, false);
  	inorder(t->right, indent, true);
}

void avl_tree::empty(avl_node *t)
{
	if (t == NULL) return;
	empty(t->left);
	empty(t->right);
	delete t;
}

avl_node *avl_tree::insert(int value, avl_node *t)
{

	//      5
	//    4   6
	//           7
	//              8

	if (t == NULL)
	{
		t = new avl_node;
		t->data = value;
		t->height = 0;
		t->left = t->right = NULL;
	}
	else if (value < t->data)
	{
		t->left = insert(value, t->left);
		if (height(t->left) - height(t->right) == 2)
		{
			if (value < t->left->data)
				t = ll_rotation(t);
			else
				t = lr_rotation(t);
		}
	}
	else if (value > t->data)
	{
		t->right = insert(value, t->right);
		if (height(t->right) - height(t->left) == 2)
		{
			if (value > t->right->data)
				t = rr_rotation(t);
			else
				t = rl_rotation(t);
		}
	}

	t->height = max(height(t->left), height(t->right)) + 1;
	return t;
}

int avl_tree::height(avl_node *t)
{
	return (t == NULL ? -1 : t->height);
}

int avl_tree::bal_factor(avl_node *t)
{
	if (t == NULL)
		return 0;
	else
		return height(t->left) - height(t->right);
}

avl_node *avl_tree::remove(int x, avl_node *t)
{
	avl_node *temp;

	if (t == NULL)
		return NULL;

	else if (x < t->data)
		t->left = remove(x, t->left);
	else if (x > t->data)
		t->right = remove(x, t->right);

	else if (t->left && t->right)
	{
		temp = findMin(t->right);
		t->data = temp->data;
		t->right = remove(t->data, t->right);
	}
	else
	{
		temp = t;
		if (t->left == NULL)
			t = t->right;
		else if (t->right == NULL)
			t = t->left;
		delete temp;
	}
	if (t == NULL)
		return t;

	t->height = max(height(t->left), height(t->right)) + 1;

	if (height(t->left) - height(t->right) == 2)
	{
		if (height(t->left->left) - height(t->left->right) == 1)
			return rr_rotation(t);
		else
			return rl_rotation(t);
	}
	else if (height(t->right) - height(t->left) == 2)
	{
		if (height(t->right->right) - height(t->right->left) == 1)
			return ll_rotation(t);
		else
			return lr_rotation(t);
	}
	return t;
}

avl_node *avl_tree::findMin(avl_node *t)
{
	if (t == NULL)
		return NULL;
	else if (t->left == NULL)
		return t;
	else
		return findMin(t->left);
}

avl_node *avl_tree::findMax(avl_node *t)
{
	if (t == NULL)
		return NULL;
	else if (t->right == NULL)
		return t;
	else
		return findMax(t->right);
}

avl_node *avl_tree::ll_rotation(avl_node *t)
{
	avl_node *u = t->left;
	t->left = u->right;
	u->right = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	u->height = max(height(u->left), t->height) + 1;
	return u;
}

avl_node *avl_tree::rr_rotation(avl_node *t)
{
	avl_node *u = t->right;
	t->right = u->left;
	u->left = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	u->height = max(height(t->right), t->height) + 1;
	return u;
}

avl_node *avl_tree::rl_rotation(avl_node *t)
{
	t->right = ll_rotation(t->right);
	return rr_rotation(t);
}

avl_node *avl_tree::lr_rotation(avl_node *t)
{
	t->left = rr_rotation(t->left);
	return ll_rotation(t);
}

int main()
{
	avl_tree t;
	t.insert(20);
	t.insert(25);
	t.insert(15);
	t.insert(10);
	t.insert(30);
	t.insert(5);
	t.insert(35);
	t.insert(67);
	t.insert(43);
	t.insert(21);
	t.insert(10);
	t.insert(89);
	t.insert(38);
	t.insert(69);
	t.insert(345);
	t.insert(6);
	t.insert(13);
	t.insert(81);
	t.insert(90);
	t.insert(79);
	t.insert(38);
	t.insert(89);
	t.insert(2);
	t.insert(4);
	t.insert(6);
	t.insert(7);
	t.display();
}