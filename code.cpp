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
    void BinaryRecursive(vector<string>&ret,TreeNode *root,string t){
        if(root->left == NULL && root->right == NULL){ 
            ret.push_back(t);
            return;
        }
        if(root->left)
            BinaryRecursive(ret,root->left,t + "->" + to_string(root->left->val));
        if(root->right)
            BinaryRecursive(ret,root->right,t + "->" + to_string(root->right->val));
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string>ret;
         if(root == NULL)
             return ret;
         BinaryRecursive(ret,root,to_string(root->val));
         return ret;
    }
};
