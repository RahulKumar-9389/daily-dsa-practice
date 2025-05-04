#include <bits/stdc++.h>
using namespace std;


int secondLargestElement(int arr[], int n){

    if(n < 2){
        return -1;
    }

    int largestElem       = INT_MIN;
    int secondLargestElem = INT_MIN;

    for(int i = 0; i<n; i++){

        if(arr[i] > largestElem){
            secondLargestElem = largestElem;
            largestElem = arr[i];
        }

        if(arr[i] > secondLargestElem && arr[i] < largestElem){
            secondLargestElem = arr[i];
        }
    }

    return secondLargestElem;
}


int main(){

    int arr[7] = {3, 2, 0, 6, 9, 9, 6};
    cout<<"Second largest element is: "<<secondLargestElement(arr, 7);
    return 0;
}