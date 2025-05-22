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


// postOrder
void postOrder(TreeNode *root){
    
    if(root == nullptr){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";   
}




int main(){

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    postOrder(root);
    return 0;
}