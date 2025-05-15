#include <iostream>
using namespace std;

class Queue{

    // Initialize some variables
    int size = 10;
    int currentSize = 0;
    int st = -1, end = -1;

    int arr[10];

public:

    // push function
    void push(int val){
        if(currentSize == size){
            cout<<"Queue is overflow!!"<<endl;
            return;
        }

        if(currentSize == 0){
            st += 1;
            end += 1;
        }else{
            end = (end + 1) % size;
        }

        arr[end] = val;
        currentSize += 1;
    }


    // pop function
    void pop(){
        if(currentSize == 0){
            cout<<"There is not element to remove!!"<<endl;
            return;
        }

        int elem = arr[st];

        if(currentSize == 1){
            st = -1;
            end = -1;
        }else{
            st = (st + 1) % size;
            currentSize -= 1;
            return;
        }
    }

    // return the top element
    int top(){
        if(currentSize == 0){
            cout<<"Queue is empty!!"<<endl;
            return -1;
        }else{
            return arr[st];
        }
    }
};

int main(){

    Queue *q = new Queue();
    q->push(10);
    q->push(20);
    q->push(30);

   cout<<q->top()<<endl;
   q->pop();
   cout<<q->top()<<endl;
    return 0;
}