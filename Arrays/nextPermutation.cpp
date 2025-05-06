#include <bits/stdc++.h>
using namespace std;


void nextPermutation(vector<int>&arr, int n){

    int pivot = -1;

    for(int i = (n-2); i >=0; i--){
        if(arr[i] < arr[i+1]){
            pivot = i;
        }
    }

    if(pivot == -1){
        reverse(arr.begin(), arr.end());
        return;
    }

    for(int i = (n-1); i>pivot; i--){
        if(arr[i] > arr[pivot]){
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    reverse(arr.begin()+pivot+1, arr.end());
}


int main(){

    vector<int>arr = {1, 2, 3, 6, 5, 4};

    nextPermutation(arr, 6);
    for(int i = 0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}