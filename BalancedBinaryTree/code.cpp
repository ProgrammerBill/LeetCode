/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
       if(root==NULL) return true;
       if(abs(Depth(root->left)-Depth(root->right))>1){
           return false;
       }
       return isBalanced(root->left) && isBalanced(root->right);
        
    }
    int Depth(TreeNode *root){
        if(root==NULL) return 0;
        return std::max(Depth(root->left),Depth(root->right))+1;
    }
    
    
};
