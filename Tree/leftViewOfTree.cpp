#include <iostream>
#include <vector>
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


void helper(TreeNode *root, vector<int>&ans, int level){

    if(!root){
        return;
    }

    if(level == ans.size()){
        ans.push_back(root->val);
    }

    helper(root->left, ans, level+1);
    helper(root->right, ans, level+1);
}

vector<int> leftView(TreeNode *root){
   vector<int>ans;
   helper(root, ans, 0);
   return ans;
}

int main(){

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(8);

    vector<int>res = leftView(root);
    for(int elem:res){
        cout<<elem<<" ";
    }
    return 0;
}