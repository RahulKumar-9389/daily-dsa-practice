#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    // constructor
    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};


bool isCycle(Node*head){

    Node *slow = head;
    Node *fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }

    return false;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third;

    if(isCycle(head)){
        cout<<"Cycle is detect!!"<<endl;
    }else{
        cout<<"No cycle is present!!"<<endl;
    }

    return 0;
}