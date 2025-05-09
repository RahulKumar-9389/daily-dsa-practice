#include <iostream>
using namespace std;

int singleElement(int arr[], int n){

    if(n == 1){
        return arr[0];
    }

    if(arr[0] != arr[1]){
        return arr[0];
    }

    if(arr[n-1] != arr[n-2]){
        return arr[n-1];
    }

    int low = 1;
    int high = (n-2);

    while(low <= high){

        int mid = low + (high - low) / 2;

        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid+1]){
            return arr[mid];
        }

        if(mid % 2 == 0){
            if(arr[mid] == arr[mid-1]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if(arr[mid] == arr[mid-1]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main(){

    int arr[7] = {3, 3, 7, 7, 10, 11, 11};

    cout<<"Single element is: "<<singleElement(arr, 7)<<endl;
    return 0;
}