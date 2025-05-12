#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;


    // constructor
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};


// find middle node
Node*middleNode(Node*head){

    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main(){

    Node*head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node*res = middleNode(head);
    cout<<"Middle node is: "<<res->val<<endl;
    return 0;
}