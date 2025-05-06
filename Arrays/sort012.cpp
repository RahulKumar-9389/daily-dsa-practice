#include <iostream>
using namespace std;

void sort012(int arr[], int n){

    // Initialize three pointers
    int low = 0;
    int mid = 0;
    int high = (n-1);

    while(mid < high){

        // check some conditions
        if(arr[mid] == 0){
            swap(arr[mid++], arr[low++]);
        }else if(arr[mid] == 1){
            mid++;
        }else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}


int main(){

    int arr[6] = {2, 1, 0, 1, 2, 0};
    sort012(arr, 6);
    
    // print the array
    for(int i = 0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}