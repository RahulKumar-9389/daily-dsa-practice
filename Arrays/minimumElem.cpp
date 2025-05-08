#include <bits/stdc++.h>
using namespace std;

int findMinimum(int arr[], int n){

    int low = 0;
    int high = (n - 1);
    int ans = INT_MAX;

    while(low <= high){

        int mid = low + (high - low) / 2;

        if(arr[low] <= arr[high]){
            ans = min(ans, arr[low]);
            break;
        }

        // left part is sorted
        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }else{
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }

    return ans;
}


int main(){

    int arr[5] = {3, 4, 5, 1, 2};
    cout<<"Minimum element is: "<<findMinimum(arr, 5)<<endl;
    return 0;
}