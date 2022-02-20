#include <iostream>
#include <cstdlib>
using namespace std;

class queue
{
    private:
        unsigned int _count;
        unsigned int _capasity;
        int _head;
        int _tail;
        int* _arr;
    public:
        queue(unsigned int size);
        ~queue();
        void dequeue();
        void enqueue(int item);
        bool isEmpty();
        bool isFull();
        unsigned int size();
        int peek();
        void print();
};

queue::queue(unsigned int size = 20)
{
    _capasity = size;
    _count = 0;
    _head = 0;
    _tail = -1;
    _arr = new int[size];
}

queue::~queue()
{
    delete [] _arr;
}

void queue::dequeue() {
    if(isEmpty()) {
        cout << "queue is Empty" << endl;
        // exit(EXIT_FAILURE);
    }
    else
    {
        cout << "Removing . . . " << _arr[_head] << endl;
        _head = ++_head % _capasity;
        --_count;
    }
}

void queue::enqueue(int item) {
    if(isFull())
    {
        cout << "queue is Full" << endl;
        // exit(EXIT_FAILURE);
    }
    else
    {
        cout << "Inserting . . . " << item << endl;
        _tail = ++_tail % _capasity;
        _arr[_tail] = item;
        ++_count;
    }
}

int queue::peek() {
    if(isEmpty()) {
        cout << "queue is Empty" << endl;
        exit(EXIT_FAILURE);
    }
    return _arr[_head];
}

bool queue::isEmpty() {
    return size() == 0;
}

bool queue::isFull() {
    return size() == _capasity;
}

unsigned int queue::size() {
    return _count;
}

void queue::print() {
    if(isEmpty()) {
        cout << "queue is Empty" << endl;
    }
    else
    {
        int index = _head;
        while (index != _tail+1) {
            cout << _arr[index++] << " ";
        }
        cout << endl;
    }
}

int main() {
    queue q(5);
    q.print();
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.print();
    cout << "size is " << q.size() << endl;
    cout << "peek " << q.peek() << endl;
    q.dequeue();
    cout << "peek " << q.peek() << endl;
    return 0;
}