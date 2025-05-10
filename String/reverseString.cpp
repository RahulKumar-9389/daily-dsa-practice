#include <iostream>
using namespace std;

void reverseString(string &str){

    // Initialize two pointers
    int left = 0;
    int right = str.length() - 1;

    while(left < right){
        swap(str[left], str[right]);
        left++;
        right--;
    }
}

int main(){

    string str = "Hello World";
    reverseString(str);
    cout<<str<<" ";
    return 0;
}