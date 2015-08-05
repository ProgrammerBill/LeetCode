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

vector <int >PostorderTraversal(TreeNode * root); 
TreeNode * Initialize();
int main(){
 TreeNode * root = Initialize();
 vector<int>  ret = PostorderTraversal(root);
    for(unsigned int j = 0; j < ret.size();++j){
      cout<<ret[j]<<" "; 
    }
 return 0;
}
vector <int >PostorderTraversal(TreeNode * root){
    vector<int> ret;
    if(root == NULL) return ret; 
    stack<TreeNode *>myStack;
    myStack.push(root);
    while(!myStack.empty()){
        TreeNode * tmp = myStack.top();
        myStack.pop();
        ret.push_back(tmp->val);
        if(tmp->left != NULL)
	    myStack.push(tmp->left);	
        if(tmp->right != NULL)
	    myStack.push(tmp->right);	
    }
    reverse(ret.begin(),ret.end());
    return ret;
} 

TreeNode * Initialize(){
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    TreeNode *Rr = root->right;
    Rr->left = new TreeNode(3); 
    return root;
}
