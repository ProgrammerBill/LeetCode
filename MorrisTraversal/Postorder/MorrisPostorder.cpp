#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct TreeNode{
  int val;
  TreeNode * left;
  TreeNode * right;
  TreeNode(int x):val(x),left(NULL),right(NULL){}
};
vector<int> PostorderMorrisTraversal(TreeNode * root);
vector<int> ReverseAction(TreeNode * from,TreeNode * to);
TreeNode * Initialize();
int main(){
 TreeNode * root = Initialize();
 vector <int> ret = PostorderMorrisTraversal(root);
 for(unsigned int i = 0 ;i < ret.size(); ++i){
   cout<<ret[i]<<" "; 
 } 
 return 0;
}
TreeNode * Initialize(){
   TreeNode * root = new TreeNode(9);
   root->left = new TreeNode(5);
   root->right = new TreeNode(8);
   TreeNode *ll = root->left;
   ll->left = new TreeNode(1);
   ll->right = new TreeNode(4);
   TreeNode * llr = ll->right;
   llr->left = new TreeNode(2);
   llr->right = new TreeNode(3);
   TreeNode * rr= root->right;
   rr->right = new TreeNode(7);
   TreeNode * rrr = rr->right;
   rrr->left = new TreeNode(6);
   return root;
}

vector<int> PostorderMorrisTraversal(TreeNode * root){
   vector<int> ret;
   if(root == NULL) return ret;
   TreeNode *dump = new TreeNode(0);
   dump->left = root;
   TreeNode * cur = dump;
   TreeNode * pre = NULL;
   while(cur != NULL){
     if(cur->left == NULL){
        cur = cur->right;
     } 
     else{
        /**
	 Find the current node's precursor
	 */
	pre = cur->left;
        while(pre->right != NULL && pre->right != cur){
            pre = pre->right;	
	} 
        if(pre->right == NULL){
	  pre->right = cur;
	  cur = cur->left;
	} 
        else{
	  vector<int>FromTo = ReverseAction(cur->left,pre);
	  ret.insert(ret.end(),FromTo.begin(),FromTo.end()); 
	  pre->right = NULL;
	  cur = cur->right;
	}
     } 
   } 
   return ret;
}
vector<int> ReverseAction(TreeNode * from,TreeNode * to){
    vector<int>ret;
    TreeNode * tmp = from;
    while(tmp != to){
      ret.push_back(tmp->val);   
      tmp = tmp->right; 
    }
    ret.push_back(to->val);
    reverse(ret.begin(),ret.end());
    return ret;
}
