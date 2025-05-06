#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int>twoSum(int arr[], int n, int target){

    if(n < 2){
        return {-1, -1};
    }

    unordered_map<int, int>mp;

    for(int i = 0; i<n; i++){

        int first  = arr[i];
        int second = target - first;

        if(mp.find(second) != mp.end()){
            return {i, mp[second]};
        }

        mp[first] = i;
    }

    return {-1, -1};

    
}


int main(){

    int arr[5] = {5, 2, 11, 7, 15};
    vector<int>ans = twoSum(arr, 5, 9);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}