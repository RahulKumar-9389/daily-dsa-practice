#include <iostream>
using namespace std;

int solve(int x, int n){

    if(n == 0){
        return 1;
    }

    if(n == 1){
        return x;
    }

    int ans = solve(x, n/2);

    if(n%2 == 0){
        return ans * ans;
    }else{
        return ans * ans * x;
    }

    return -1;

}

int main(){
    int base;
    int power;

    cout<<"Enter the base: ";
    cin>>base;

    cout<<"Enter the power: ";
    cin>>power;

    cout<<base <<" raised to the power "<<power<<" is: "<<solve(base, power)<<endl;
    return 0;
}