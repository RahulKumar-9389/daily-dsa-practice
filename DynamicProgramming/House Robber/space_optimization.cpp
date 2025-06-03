#include <iostream>
#include <vector>
using namespace std;



int rob(vector<int>&nums){

    int n = nums.size();

    int prev = nums[0];
    int prev_next = 0;

    for(int i = 1; i < n; i++){

        int pick = nums[i];
        if(i > 2){
            pick += prev_next;
        }

        int not_pick = 0 + prev;


        int current = max(pick, not_pick);
        prev_next = prev;
        prev = current;
    }


    return prev;

    
    
}

int main(){

    vector<int>arr = {2, 4, 1, 9};
    cout<<rob(arr)<<endl;
    return 0;
}