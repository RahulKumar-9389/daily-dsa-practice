#include<iostream>
using namespace std;


int maxProfit(int arr[], int n){

    int maxProfit = 0;
    int bestBuy   = arr[0];


    for(int i = 1; i < n; i++){

        if(arr[i] > bestBuy){
            int profit = arr[i] - bestBuy;
            maxProfit = max(maxProfit, profit);
        }

        bestBuy = min(arr[i], bestBuy);
    }

    return maxProfit;
}


int main(){

    int arr[6] = {7,1,5,3,6,4};
    cout<<"Maximum profit we can achive is: "<<maxProfit(arr, 6);
    return 0;
}