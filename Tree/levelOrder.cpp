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


// levelOrder
void levelOrder(TreeNode *root){
    
    if(root == nullptr){
        return;
    }

    queue<TreeNode*>q;
    q.push(root);


    while(!q.empty()){
        TreeNode *temp = q.front();
        q.pop();
        cout<<temp->val<<" ";

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}




int main(){

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    levelOrder(root);
    return 0;
}