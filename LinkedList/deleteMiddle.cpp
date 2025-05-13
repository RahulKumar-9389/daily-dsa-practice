#include <iostream>
using namespace std;


class Node{
    public:
        int val;
        Node *next;

    // Constructor
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};

Node*deleteMiddle(Node*head){
    if(!head || !head->next){
        return nullptr;
    }

    Node *slow = head;
    Node *fast = head->next->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = slow->next->next;
    return head;
}


// print list
void printList(Node*head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
}


int main(){

    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next = new Node(5);

    head = deleteMiddle(head);
    printList(head);
    return 0;
}