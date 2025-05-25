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


int heightOfTree(TreeNode *root){
    if(!root){
        return 0;
    }


    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}


int main(){

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->left->right = new TreeNode(7);

    cout<<"Max height of binary tree is: "<<heightOfTree(root);
    return 0;
}