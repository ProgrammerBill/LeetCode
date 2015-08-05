#include <iostream>
#include <vector> 
using namespace std;
struct TreeNode{
  int val;
  TreeNode * left;
  TreeNode * right;
  TreeNode(int x):val(x),left(NULL),right(NULL){}
};
vector<int> InorderMorrisTraversal(TreeNode * root);
TreeNode * Initialize();
int main(){
 TreeNode * root = Initialize();
 vector <int> ret = InorderMorrisTraversal(root);
 cout<<"ret!"<<endl;
 for(unsigned int i = 0 ;i < ret.size(); ++i){
   cout<<ret[i]<<" "; 
 } 
 return 0;
}
TreeNode * Initialize(){
   TreeNode * root = new TreeNode(6);
   root->left = new TreeNode(2);
   root->right = new TreeNode(7);
   TreeNode *ll = root->left;
   ll->left = new TreeNode(1);
   ll->right = new TreeNode(4);
   TreeNode * llr = ll->right;
   llr->left = new TreeNode(3);
   llr->right = new TreeNode(5);
   TreeNode * rr= root->right;
   rr->right = new TreeNode(9);
   TreeNode * rrr = rr->right;
   rrr->left = new TreeNode(8);
   return root;
}

vector<int> InorderMorrisTraversal(TreeNode * root){
   vector<int> ret;
   if(root == NULL) return ret;
   TreeNode * cur = root;
   TreeNode * pre = NULL;
   while(cur != NULL){
     if(cur->left == NULL){
        ret.push_back(cur->val); 
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
	  pre->right = NULL;
          ret.push_back(cur->val); 
	  cur = cur->right; 
	}
     } 
   } 
   return ret;
}
