#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // Constructor
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};


// Print the list
void printList(Node* head){

    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
}


int main(){

    Node *head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);

    printList(head);
    return 0;
}