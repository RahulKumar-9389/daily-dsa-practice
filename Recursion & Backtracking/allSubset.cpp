#include <iostream>
#include <vector>
using namespace std;

void allSubsets(vector<int>&arr, vector<int>&ans, int index){

    // base condition
    if(index == arr.size()){
        for(int i = 0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }

    // include
    ans.push_back(arr[index]);
    allSubsets(arr, ans, index+1);

    // not include
    ans.pop_back();
    allSubsets(arr, ans, index+1);
}




int main(){

    vector<int>arr = {1, 2, 3};
    vector<int>ans;
    allSubsets(arr, ans, 0);
    return 0;
}