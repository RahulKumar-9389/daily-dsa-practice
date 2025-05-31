#include <iostream>
#include <vector>
#include <climits>
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

TreeNode *buildBST(vector<int>&arr, int &index, int lower, int higher){

    if(index < 0 || arr[index] < lower || arr[index] > higher){
        return nullptr;
    }

    int val = arr[index];
    TreeNode *root = new TreeNode(val);
    index--;

    root->right = buildBST(arr, index, root->val, higher);
    root->left = buildBST(arr, index, lower, root->val);

    return root;
}


void preOrder(TreeNode *root){
    if(!root){
        return;
    }

    preOrder(root->left);
    preOrder(root->right);
    cout<<root->val<<" ";
}

int main(){

    vector<int>arr = {1, 7, 5, 50, 40, 10};
    int index = arr.size() - 1;

    TreeNode *root = buildBST(arr, index, INT_MIN, INT_MAX);
    preOrder(root);
    return 0;
}