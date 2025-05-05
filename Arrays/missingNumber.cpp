#include <iostream>
using namespace std;

int findMissingNumber(int nums[], int n){

    // Calculate the sum of elements from 1 to n
    int totalSum = n * (n + 1) / 2;

    // Calculate the current sum
    int currentSum = 0;
    for(int i = 0; i<n; i++){
        currentSum += nums[i];
    }

    return totalSum - currentSum;
}

int main(){

    int n = 9;
    int nums[n] = {9,6,4,2,3,5,7,0,1};

    cout<<"Missing number is: "<<findMissingNumber(nums, 9)<<endl;
    return 0;
}