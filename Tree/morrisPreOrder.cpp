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

void MorrisPreOrder(TreeNode *root){


    while(root){

        // If left child does not exist
        if(!root->left){
            cout<<root->val<<" ";
            root = root->right;
        }
        else{
            TreeNode *current = root->left;

            while(current->right && current->right != root){
                current = current->right;
            }

            if(current->right == root){
                current->right = nullptr;
                root = root->right;
            }
            else{
                cout<<root->val<<" ";
                current->right = root;
                root = root->left;
            }
        }
    }
}

int main(){
    TreeNode *root = new TreeNode(1);

    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left  = new TreeNode(4);
    root->left->right = new TreeNode(5);

    MorrisPreOrder(root);
    return 0;
}