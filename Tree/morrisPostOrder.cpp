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

vector<int> morrisPostOrder(TreeNode *root){

    vector<int>ans;

    while(root){
        
        if(!root->right){
            ans.push_back(root->val);
            root = root->left;
        }
        else{
            TreeNode *current = root->right;

            while(current->left && current->left != root){
                current = current->left;
            }

            if(current->left == root){
                current->left = nullptr;
                root = root->left;
            }else{
                ans.push_back(root->val);
                current->left = root;
                root = root->right;
            }
        }
    }

    return ans;

}
int main(){
    TreeNode *root = new TreeNode(1);

    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);

    root->right->left  = new TreeNode(4);
    root->right->right = new TreeNode(5);

   vector<int>res =  morrisPostOrder(root);
   for(int i = res.size() - 1; i>=0; i--){
    cout<<res[i]<<" ";
   }
    return 0;
}