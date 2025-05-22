#include <iostream>
#include <queue>
using namespace std;


class TreeNode{
public:
    int val;
    TreeNode*left;
    TreeNode *right;

    // constructor
    TreeNode(int val){
        this->val = val;
        this->left = this->right = nullptr;
    }
};


// Build the level order tree
TreeNode *buildTree(){

    queue<TreeNode*>q;

    int rootVal;    
    cout<<"Enter the value of root node: ";
    cin>>rootVal;

    TreeNode* root = new TreeNode(rootVal);
    q.push(root);

    while(!q.empty()){

        TreeNode*temp = q.front();
        q.pop();

        int leftVal;
        cout<<"Enter the value of "<<temp->val<<" left node: ";
        cin>>leftVal;

        if(leftVal != -1){
            temp->left = new TreeNode(leftVal);
            q.push(temp->left);
        }

        int rightVal;
        cout<<"Enter the value of" <<temp->val <<" right node: ";
        cin>>rightVal;

        if(rightVal != -1){
            temp->right = new TreeNode(rightVal);
            q.push(temp->right);
        }
    }

    return root;
}

int main(){

    TreeNode *root = buildTree();
    return 0;
}