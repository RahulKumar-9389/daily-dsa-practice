#include <iostream>
using namespace std;

int search(int arr[], int n, int target){
    
    int low = 0;
    int high = (n - 1);

    while(low <= high){

        int mid = low + (high - low) / 2;

        if(arr[mid] == target){
            return mid;
        }

        // if left part is sorted
        if(arr[low] <= arr[mid]){

            if(target >= arr[low] && target <= arr[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if(target <= arr[mid] && target <= arr[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }

    return -1;
}


int main(){

    int arr[7] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout<<"Element is present at index: "<<search(arr, 7, target)<<endl;
    return 0;
}