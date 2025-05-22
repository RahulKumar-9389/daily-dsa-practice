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


void SumOfTree(TreeNode*root, int &sum){
    if(root == nullptr){
        return;
    }

    sum += root->val;
    SumOfTree(root->left, sum);
    SumOfTree(root->right, sum);
}




int main(){

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);


    int sum = 0;
    SumOfTree(root, sum);
    cout<<"Size of the tree is: "<<sum;

    return 0;
}