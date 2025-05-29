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


void flatten(TreeNode *root){
    if (!root)
            return;
        TreeNode* mover = root;
        while (mover) {
            if (mover->left) {
                TreeNode* temp = mover->left;
                while (temp->right)
                    temp = temp->right;
                temp->right = mover->right;
                mover->right = mover->left;
                mover->left = nullptr;
            }
            mover = mover->right;
        }
}


int main(){
    TreeNode *root = new TreeNode(1);

    root->left  = new TreeNode(2);
    root->right = new TreeNode(5);

    root->right->left  = new TreeNode(3);
    root->right->right = new TreeNode(4);
    return 0;
}