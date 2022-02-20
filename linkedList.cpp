#include <iostream>
#include <cstdlib>
using namespace std;

class node
{
    public:
        int _value;
        node * _next;
};


class linkedList
{
    private:
        int _length;
        node* _head;
    public:
        linkedList();
        ~linkedList(){};
        void add(int value);
        void print();
    };

linkedList::linkedList()
{
    _head = NULL;
}

void linkedList::add(int value) {
    node* n = new node;
    n->_value = value;
    n->_next = _head;
    _head = n;
}

void linkedList::print() {
    node* n = _head;
    while (n)
    {
        cout << n->_value << " ";
        n = n->_next;
    }
    cout << endl;
}

int main() {
    linkedList l;
    l.add(4);
    l.add(5);
    l.add(6);
    l.add(7);
    l.add(8);
    l.print();
}