#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>&value, vector<int>&weight, int W, int n, vector<vector<int>>&dp){

    if(n == 0 || W == 0){
        return 0;
    }

    if(dp[n][W] != -1){
        return dp[n][W];
    }

    int pick = 0;

    if(weight[n-1] <= W){
        pick = value[n-1] + knapsack(value, weight, W - weight[n-1], n-1, dp);
    }


    // if we don't pick the element
    int not_pick = knapsack(value, weight, W, n-1, dp);

    return dp[n][W] =  max(pick, not_pick);
}


int main(){
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W = 4;
    int n = val.size();

    vector<vector<int>>dp(n+1, vector<int>(W+1, -1));

    cout << knapsack(val, wt, W, n, dp) << endl;
    return 0;
}