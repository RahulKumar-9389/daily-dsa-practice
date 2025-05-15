#include <iostream>
using namespace std;

// Node Class
class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

// Stack Class using Linked List
class Stack {
private:
    Node* top;   // Pointer to the top node
    int sz;      // Keep track of size

public:
    // Constructor
    Stack() {
        top = nullptr;
        sz = 0;
    }

    // Destructor to avoid memory leak
    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }

    // Push function
    void push(int val) {
        Node* temp = new Node(val);
        temp->next = top;
        top = temp;
        sz++;
    }

    // Pop function
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        sz--;
    }

    // Top function
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->val;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Return size
    int size() {
        return sz;
    }
};

int main() {
    Stack* st = new Stack();

    st->push(4);
    st->push(5);
    cout << "Top element: " << st->peek() << endl;
    st->pop();
    cout << "Top element after pop: " << st->peek() << endl;

    delete st; // Free memory
    return 0;
}
