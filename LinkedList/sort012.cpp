#include <iostream>
using namespace std;


class Node{
    public:
        int val;
        Node *next;

    // constructor
    Node(int val){
        this->val  = val;
        this->next = nullptr;
    }
};

Node *sort012(Node*head){

    Node *zeroHead = new Node(-1);
    Node *oneHead  = new Node(-1);
    Node *twoHead  = new Node(-1);

    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;

    Node *temp = head;

    while(temp){
        if(temp->val == 0){
            zero->next = temp;
            temp = temp->next;
            zero = zero->next;
        }else if(temp->val == 1){
            one->next = temp;
            temp = temp->next;
            one = one->next;
        }else{
            two->next = temp;
            temp = temp->next;
            two = two->next;
        }
    }

    zero->next = oneHead->next ? oneHead->next : twoHead->next;
    oneHead->next = twoHead->next;

    return zeroHead->next;
}

int main(){

    Node *head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(2);

    
    return 0;
}