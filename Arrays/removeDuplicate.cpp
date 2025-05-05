#include <iostream>
using namespace std;

int removeDuplicate(int nums[], int n){

    int i = 0;

    for(int j = 1; j < n; j++){
        if(nums[j] != nums[i]){
            nums[i+1] = nums[j];
            i++;
        }
    }

    return i;
}

int main(){

    int nums[10] = {0,0,1,1,1,2,2,3,3,4};
    int limit = removeDuplicate(nums, 10);

    for(int i = 0; i <= limit; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}