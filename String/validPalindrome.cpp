#include <iostream>
using namespace std;

bool isPalindrome(string &s){

    int left = 0;
    int right = s.length() - 1;

    while(left <= right){

        if(!isalnum(s[left])){
            left++;
            continue;
        }

        if(!isalnum(s[right])){
            right--;
            continue;
        }

        if(tolower(s[left]) != tolower(s[right])){
            return false;
        }else{
            left++;
            right--;
        }
    }

    return true;
}

int main(){

    string s = "A man, a plan, a canal: Panama";
    if(isPalindrome(s)){
        cout<<"Valid palindrome"<<endl;
    }else{
        cout<<"Invalid"<<endl;
    }
    return 0;
}