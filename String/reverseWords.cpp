#include <iostream>
#include <algorithm>
using namespace std;

string reverseWords(string s){

    int n = s.length();
    string ans = "";

    reverse(s.begin(), s.end());

    for(int i = 0; i<n; i++){

        string w = "";

        while(i < n && s[i] != ' '){
            w += s[i];
            i++;
        }

        reverse(w.begin(), w.end());

        if(w.length() > 0){
            ans += " " + w;
        }
    }

    return ans.substr(1);
};


int main(){

    string s = "the sky is blue";
    cout<<reverseWords(s)<<endl;
    return 0;
}