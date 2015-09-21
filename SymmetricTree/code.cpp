/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode *left,TreeNode *right){
        if(left == NULL && right == NULL) return true;
        if((left == NULL && right != NULL) || (left != NULL && right == NULL) || (left->val != right->val)) return false;
        return dfs(left->left,right->right) && dfs(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return true;
        return dfs(root->left,root->right);
    }
    
};
