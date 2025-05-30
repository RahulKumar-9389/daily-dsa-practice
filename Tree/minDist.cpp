#include <iostream>
#include <climits>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

void helper(TreeNode *root, int &prev, int &ans){
    if(!root){
        return;
    }

    helper(root->left, prev, ans);
    ans = min(ans, root->val - prev);
    prev = root->val;
    helper(root->right, prev, ans);
}

int minDist(TreeNode *root){
  
    int prev = 0;
    int ans = INT_MAX;

    helper(root, prev, ans);
    return ans;
}

int main() {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(25);  // This makes it not a BST

    cout<<"Minimum diffrence between two nodes is: "<<minDist(root);
    return 0;
}
