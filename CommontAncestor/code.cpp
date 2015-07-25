#include<iostream>
using namespace std;
struct TreeNode{
  int val;
  TreeNode * left;
  TreeNode * right;
  TreeNode(int x):val(x),left(NULL),right(NULL){}
};
TreeNode * InitTheTree();
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

int main(){
 TreeNode* root = InitTheTree();
 TreeNode * p = root->left;
 TreeNode * q = root->right;
 cout<<lowestCommonAncestor(root,p,q)->val; 
  return 0;
}
TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
   if(root->val == p->val || root->val == q->val)
          return root;
   bool left1 = root->val > p->val,left2 = root->val > q->val;
   if(left1 && left2)
	return lowestCommonAncestor(root->left,p,q);
   else if(left1 || left2)
	return root; 
   else
        return lowestCommonAncestor(root->right,p,q);   
}
/*
 * You don't want to see how it was created
 * */
TreeNode * InitTheTree(){
  TreeNode *root = new TreeNode(6);
  TreeNode *l = new TreeNode(2);
  TreeNode *r = new TreeNode(8);
  root->left = l;
  root->right = r;  
  TreeNode *tmp = l; 
  l = new TreeNode(0);
  r = new TreeNode(4);
  tmp->left = l;
  tmp->right = r; 
  tmp = r;
  l = new TreeNode(3);
  r = new TreeNode(5);
  tmp->left = l;
  tmp->right = r;
  tmp = root->right;
  l = new TreeNode(7);
  r = new TreeNode(9);
  tmp->left = l;
  tmp->right = r;
  return root;
}
