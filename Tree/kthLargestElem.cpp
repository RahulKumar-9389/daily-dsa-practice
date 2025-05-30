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

void kthLargest(TreeNode *root, int &ans, int &k){
    if(!root){
        return;
    }

    kthLargest(root->right, ans, k);
    k--;
    if(k == 0){
        ans = root->val;
    }

    if(k < 0){
        return;
    }

    kthLargest(root->left, ans, k);
}

int main() {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(25);

    int k = 3;
    int ans = -1;
    kthLargest(root, ans, k);
    cout<<k<<" th largest element is: "<<ans;
    return 0;
}
