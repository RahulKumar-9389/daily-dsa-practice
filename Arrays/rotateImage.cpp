#include <iostream>
#include <algorithm>
using namespace std;

void rotateImage(int arr[][3], int n){

    // Transpose the matrix
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            swap(arr[i], arr[j]);
        }
    }

    // now rerverse the every row
    for(int i = 0; i<n; i++){
        reverse(arr[i].begin(), arr[i].end());
    }
}


int main(){

    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    return 0;
}