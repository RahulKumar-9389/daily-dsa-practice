#include <iostream>
using namespace std;


int majorityElem(int arr[], int n){

    // Initialize two pointers
    int count = 0;
    int ans = -1;

    for(int i = 0; i < n; i++){

        if(count == 0){
            ans = arr[i];
        }

        if(arr[i] == ans){
            count++;
        }else{
            count--;
        }
    }

    return ans;
}

int main(){

    int arr[6] = {2, 2, 1, 1, 1, 1};
    cout<<majorityElem(arr, 6)<<" is appears more than n/2 times!!";
    return 0;
}