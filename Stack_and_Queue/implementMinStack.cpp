#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack{
    public:
        stack<int>st;
        int mini = INT_MAX;

    // PUSH
    void push(int val){
        // stack is empty
        if(st.empty()){
            mini = val;
            st.push(val);
        }else{
            if(val < mini){
                st.push(2 * val - mini);
                mini = val;
            }else{
                st.push(val);
            }
        }
    }


    // POP
    void pop(){
        if(st.empty()){
            cout<<"Stack is empty!!"<<endl;
            return;
        }

        int x = st.top();
        st.pop();

        if(x < mini){
            mini = (2 * mini - x);
        }
    }


    // TOP
    int peek(){

        int top_value = st.top();

        if(top_value < mini){
            return mini;
        }else{
            return top_value;
        }
    }

    // MINIMUM VALUE
    int getMin(){
        return mini;
    }


};


int main(){
    MinStack *s = new MinStack();
    s->push(2);
    s->push(3);
    cout<<"Top element is: "<<s->peek()<<endl;
    cout<<"Minimum value is: "<<s->getMin()<<endl;
    s->push(1);
    cout<<"Minimum value is: "<<s->getMin()<<endl;
    s->pop();
    cout<<"Minimum value is: "<<s->getMin()<<endl;


    return 0;
}