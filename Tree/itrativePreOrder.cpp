#include <iostream>
#include <stack>
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

void preOrder(TreeNode *root){

    stack<TreeNode*>st;

    st.push(root);

    while(!st.empty()){

        TreeNode *temp = st.top();
        st.pop();

        cout<<temp->val<<" ";

        if(temp->right){
            st.push(temp->right);
        }

        if(temp->left){
            st.push(temp->left);
        }

        
    }
}

int main(){

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    preOrder(root);
    return 0;
}