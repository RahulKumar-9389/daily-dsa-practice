#include <iostream>
using namespace std;

class MaxHeap{
    public:
    int *arr;
    int size;
    int total_size;

    // constructor
    MaxHeap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
    }


    // insert
    void insert(int val){

        if(size == total_size){
            cout<<"Heap is overflow!!";
            return;
        }

        arr[size] = val;
        int index = size;
        size++;

        // insert at it's right position
        while(index > 0 && arr[(index - 1) / 2] > arr[index]){
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2;
        }
    }


    // print heap elements
    void print(){
        for(int i = 0; i < size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};



int main(){

    MaxHeap *h = new MaxHeap(5);
    h->insert(4);
    h->insert(7);
    h->insert(10);
    h->insert(1);
    h->insert(0);

    h->print();

    return 0;
}