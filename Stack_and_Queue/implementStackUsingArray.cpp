#include <iostream>
using namespace std;

class Stack {
    int top = -1;
    int arr[10];

public:
    // push
    void push(int val) {
        if (top >= 9) {
            cout << "Stack is overflow!!" << endl;
            return;
        }
        top += 1;
        arr[top] = val;
    }

    // pop
    void pop() {
        if (top == -1) {
            cout << "Stack is empty!!" << endl;
            return;
        }
        top -= 1;
    }

    // peek top element
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!!" << endl;
            return -1;
        }
        return arr[top];
    }

    // check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // return size of stack
    int size() {
        return top + 1;
    }
};

int main() {
    Stack* st = new Stack();
    st->push(5);
    cout << "Top element: " << st->peek() << endl;
    delete st;
    return 0;
}
