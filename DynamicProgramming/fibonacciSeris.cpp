#include <iostream>
using namespace std;

int fib(int n, int arr[]){
    
    if(n <= 1){
        return n;
    }

    if(arr[n] != -1){
        return arr[n];
    }

    return arr[n] =  fib(n-2, arr) + fib(n-1, arr);
}

int main(){

    int n = 4;
    int arr[] = {-1, -1, -1, -1, -1};
    cout<<fib(n, arr);

    return 0;
}