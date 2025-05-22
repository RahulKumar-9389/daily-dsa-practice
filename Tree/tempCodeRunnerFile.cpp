#include <iostream>
#include <queue>
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


int sizeOfTree(TreeNode*root){
    if(root == nullptr){
        return 0;
    }

    return (1 + sizeOfTree(root->left) + sizeOfTree(root->right));
}




int main(){

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout<<"Size of the tree is: "<<sizeOfTree(root);

    return 0;
}