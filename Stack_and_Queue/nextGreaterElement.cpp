#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int>nextGreater(vector<int>&arr){
    stack<int>s;
    int n = arr.size();

    vector<int>ans(n, -1);

    for(int i = (n-1); i>=0; i--){

        while(!s.empty() && arr[i] >= s.top()){
            s.pop();
        }

        if(s.empty()){
            ans[i] = -1;
        }else{
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    return ans;
}


int main(){

    vector<int>arr = {11, 13, 21, 3, 5, 7};
    vector<int>res = nextGreater(arr);

    for(int elem:res){
        cout<<elem<<" ";
    }
    return 0;
}