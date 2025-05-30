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

void helper(TreeNode *root, bool &ans, int &prev, bool &firstNode) {
    if (!root || !ans) return;

    helper(root->left, ans, prev, firstNode);

    if (!firstNode && root->val <= prev) {
        ans = false;
        return;
    }

    prev = root->val;
    firstNode = false;

    helper(root->right, ans, prev, firstNode);
}

bool isBST(TreeNode *root) {
    bool ans = true;
    bool firstNode = true;
    int prev = INT_MIN;

    helper(root, ans, prev, firstNode);
    return ans;
}

int main() {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(2);  // This makes it not a BST

    if (isBST(root)) {
        cout << "Given Tree is a Binary Search Tree!!";
    } else {
        cout << "Not a BST!!!";
    }
    return 0;
}
