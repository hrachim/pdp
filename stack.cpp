#include <iostream>
using namespace std;

class stack
{
    private:
        unsigned int _size;
        int _top;
        int* _arr;
    public:
        stack(unsigned int size);
        ~stack();
        int pop();
        void push(int item);
        bool isEmpty();
        bool isFull();
        unsigned int size();
        int peek();
        void print();
};

stack::stack(unsigned int size = 20)
{
    _size = size;
    _top = -1;
    _arr = new int[size];
}

stack::~stack()
{
    delete [] _arr;
}

int stack::pop() {
    if(isEmpty()) {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    return _arr[_top--];
}

void stack::push(int item) {
    if(isFull())
    {
        cout << "Stack is Full" << endl;
    }
    else
    {
        _arr[++_top] = item;
    }
}

unsigned int stack::size() {
    return _top+1;
}

int stack::peek() {
    if(isEmpty()) {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    return _arr[_top];
}

bool stack::isEmpty() {
    return _top == -1;
}

bool stack::isFull() {
    return _top == _size-1;
}

void stack::print() {
    if(isEmpty()) {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        int index = 0;
        while (index != _size) {
            cout << _arr[index++] << " ";
        }
        cout << endl;
    }
}

int main() {
    stack s(3);
    s.print();
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.print();
    cout << "size is " << s.size() << endl;
    cout << "peek " << s.peek() << endl;
    cout << "pop " << s.pop() << endl;
    cout << "peek " << s.peek() << endl;
    cout << "pop " << s.pop() << endl;
    s.print();
    return 0;
}