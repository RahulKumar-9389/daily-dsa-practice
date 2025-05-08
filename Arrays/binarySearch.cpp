#include <iostream>
using namespace std;

int binarySearch(int arr[], int target, int n){


    // Initialize two pointers
    int left  = 0;
    int right = (n - 1);

    while(left <= right){

        // calculate the mid
        int mid = left + (right - left) / 2;

        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    return -1;

}

int main(){

    int arr[6] = {2, 4, 6, 10, 14};
    cout<<"Element is present at index: "<<binarySearch(arr, 10, 6)<<endl;
    return 0;
}