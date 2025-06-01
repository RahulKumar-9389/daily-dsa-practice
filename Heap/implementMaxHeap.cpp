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
        while(index > 0 && arr[(index - 1) / 2] < arr[index]){
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2;
        }
    }


    void Heapify(int index){

        int left  = 2 * index + 1;
        int right = 2 * index + 2;

        int maxi = index;

        if(left < size && arr[left] > maxi){
            maxi = left;
        }

        if(right < size && arr[right] > maxi){
            maxi = right;
        }

        if(maxi != index){
            swap(arr[index], arr[maxi]);
            Heapify(maxi);
        }
    }


    // Delete
    void remove(){

        if(size == 0){
            cout<<"There is no element in heap to delete!!";
            return;
        }

        swap(arr[0], arr[size-1]);
        size--;

        if(size == 0){
            return;
        }

        Heapify(0);

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

    h->remove();
    h->print();
    return 0;
}