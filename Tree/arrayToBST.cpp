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

TreeNode *arrayToBST(int arr[], int s, int e){
    if(s > e){
        return nullptr;
    }

    int mid = (s + e) / 2;
    TreeNode *root = new TreeNode(arr[mid]);

    root->left = arrayToBST(arr, s, mid-1);
    root->right = arrayToBST(arr, mid+1, e);
    return root;
}

void inOrder(TreeNode *root){
    if(!root){
        return;
    }

    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

int main() {
    
    int arr[6] = {1, 2, 3, 4, 5, 6};
    TreeNode *root = arrayToBST(arr, 0, 5);
    inOrder(root);
    return 0;
}
