#include <iostream>
#include <vector>
using namespace std;



int rob(vector<int>&nums){
    int n = nums.size();
    
    vector<int>dp(n, 0);

    dp[0] = nums[0];

    for(int i = 1; i < n; i++){

        int pick = nums[i];
        if(i > 1){
            pick += dp[i-2];
        }

        int not_pick = 0 + dp[i-1];

        dp[i] = max(pick, not_pick);
    }

    return dp[n-1];
}

int main(){

    vector<int>arr = {2, 4, 1, 9};
    cout<<rob(arr)<<endl;
    return 0;
}