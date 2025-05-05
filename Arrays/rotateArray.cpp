#include <iostream>
using namespace std;


void reverse(int arr[], int left, int right){
        
    while(left <= right){
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void rotateArray(int nums[], int n, int k){

        k = k % n;

        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
}

int main(){

    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotateArray(arr, 7, k);

    for(int i = 0; i < 7; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}