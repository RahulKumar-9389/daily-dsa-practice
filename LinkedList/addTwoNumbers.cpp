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

Node* addTwoNumbers(Node*head1, Node*head2){

    Node*h1 = head1;
    Node*h2 = head2;

    // Create a dummy node
    Node* dummyNode = new Node(-1);
    Node *current = dummyNode;

    int carry = 0;

    while(h1 || h2 || carry){

        int sum = 0;

        if(h1){
            sum += h1->val;
            h1 = h1->next;
        }

        if(h2){
            sum += h2->val;
            h2 = h2->next;
        }

        // if carry 
        sum += carry;
        carry = sum / 10;

        // Create a new node of sum
        Node *temp = new Node(sum % 10);
        current->next = temp;
        current = current->next;

        if(carry){
            current->next = new Node(carry);
        }


    }
         return dummyNode->next;

}

// Function to print the linked list
void printList(Node *head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
}

int main(){

    Node *head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(3);

    Node *head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);

    Node *head = addTwoNumbers(head1, head2);
    printList(head);
    return 0;
}