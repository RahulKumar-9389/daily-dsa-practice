#include <iostream>
using namespace std;

int maxConsecutiveOnes(int arr[], int n){

    // Initialize two variables
    int count = 0;
    int ans   = 0;

    for(int i = 0; i<n; i++){
        if(arr[i] == 1){
            count++;
            ans = max(ans, count);
        }else{
            count = 0;
        }
    }

    return ans;
}

int main(){

    int arr[6] = {1, 1, 0, 1, 1, 0};

    cout<<"Maximum consecutive ones are: "<<maxConsecutiveOnes(arr, 6);
    return 0;
}