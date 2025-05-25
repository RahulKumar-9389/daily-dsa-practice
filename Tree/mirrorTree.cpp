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


void mirrorTree(TreeNode *root){
    if(!root){
        return;
    }

    swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
    
}




int main(){

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout<<root->val;
    cout<<root->left->val;
    cout<<root->right->val;

    
    return 0;
}