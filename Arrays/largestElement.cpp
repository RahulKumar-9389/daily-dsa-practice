#include <bits/stdc++.h>
using namespace std;


int largestElement(int arr[], int n){

    int largestElem = INT_MIN;

    for(int i = 0; i < n; i++){
        if(arr[i] > largestElem){
            largestElem = arr[i];
        }
    }

    return largestElem;
}


int main(){

    int arr[5] = {3, 2, 0, 6, 9};
    cout<<"Largest Element is: "<<largestElement(arr, 5);
    return 0;
}