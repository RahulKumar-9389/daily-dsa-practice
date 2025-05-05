#include <iostream>
using namespace std;

void movesZeros(int nums[], int n){

    if(n == 1){
        return;
    }

    int j = -1;

    // Find the 0 element
    for(int i = 0; i<n; i++){
        if(nums[i] == 0){
            j = i;
            break;
        }
    }

    // swap
    for(int i = (j+1); i < n; i++){
        if(nums[i] != 0){
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main(){

    int nums[5] = {0,1,0,3,12};
    movesZeros(nums, 5);
    

    for(int i = 0; i<5; i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}