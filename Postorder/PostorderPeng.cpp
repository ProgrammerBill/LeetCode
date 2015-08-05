#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <algorithm>
using namespace std;
struct TreeNode{
  int val;
  TreeNode * left;
  TreeNode * right;
  TreeNode(int x):val(x),left(NULL),right(NULL){}
};
vector<int> PostorderTraversal(TreeNode * root);
TreeNode * Initialize();
int main(){
 TreeNode * root = Initialize();
 vector <int> ret = PostorderTraversal(root);
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

vector<int> PostorderTraversal(TreeNode * root){
   vector<int> ret;
   if(root == NULL) return ret;
   unordered_set<TreeNode*>mySet;
   stack<TreeNode*>myStack;
   myStack.push(root);
   while(!myStack.empty()){
       TreeNode *tmp = myStack.top();
       if(tmp->left != NULL && mySet.find(tmp->left) == mySet.end()){
            myStack.push(tmp->left);
            mySet.insert(tmp->left);
       }
       else if(tmp->right != NULL && mySet.find(tmp->right) == mySet.end()){
            myStack.push(tmp->right);
            mySet.insert(tmp->right);
            }
       else{
            ret.push_back(tmp->val);
            myStack.pop();
        }
    }
      return ret;
}

