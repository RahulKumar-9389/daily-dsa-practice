#include <iostream>
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


// preOrder
void preOrder(TreeNode *root){
    
    if(root == nullptr){
        return;
    }

    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}




int main(){

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    preOrder(root);
    return 0;
}