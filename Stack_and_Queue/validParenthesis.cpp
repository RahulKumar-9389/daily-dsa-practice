#include <iostream>
#include <stack>

using namespace std;


bool isValid(string &s){

    stack<char>st;

    for(int i = 0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                return false;
            }

            char ch = st.top();
            st.pop();

            if(ch == '(' && s[i] != ')'
            || ch == '{' && s[i] != '}'
            || ch == '[' && s[i] != ']'){
                return false;
            }
        }
    }

    return st.empty();
}


int main(){

    string st = "(){}[()]";
    if(isValid(st)){
        cout<<"Given string is a valid string!!"<<endl;
    }else{
        cout<<"Not a valid string!!"<<endl;
    }
    return 0;
}