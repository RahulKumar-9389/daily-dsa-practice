#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;


    // constructor
    TreeNode(int val){
        this->val = val;
        this->left = this->right = nullptr;
    }
};

vector<int> postOrder(TreeNode *root){

    stack<TreeNode*>st;
    vector<int>ans;

    st.push(root);

    while(!st.empty()){

        TreeNode *temp = st.top();
        st.pop();

        ans.push_back(temp->val);

        if(temp->left){
            st.push(temp->left);
        }  

        if(temp->right){
            st.push(temp->right);
        }             
    }

    return ans;
}

int main(){

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    vector<int>res = postOrder(root);
    for(int i = res.size() - 1; i>=0; i--){
        cout<<res[i]<<" ";
    }
    return 0;
}