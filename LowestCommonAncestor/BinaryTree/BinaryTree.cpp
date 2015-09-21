#include <iostream>
#include <stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode * lowestCommonAncestor(TreeNode * root,TreeNode * p,TreeNode * q);
bool Traverse(TreeNode * root,TreeNode *node,stack<TreeNode*>&path);
int main(){
   TreeNode * root =new TreeNode(3);
   root->left = new TreeNode(5);	
   root->right = new TreeNode(1); 
   
   root->left->left = new TreeNode(6);
   root->left->right = new TreeNode(2);
   root->left->right->left = new TreeNode(7);
   root->left->right->right = new TreeNode(4);

   root->right->left = new TreeNode(0);
   root->right->right = new TreeNode(8);
   TreeNode *p = root->left;
   TreeNode *q = root->right->right;
   TreeNode *ret = lowestCommonAncestor(root,p,q); 
   cout<<ret->val<<endl;
   return 0;
}

TreeNode * lowestCommonAncestor(TreeNode * root,TreeNode * p,TreeNode * q){
    stack<TreeNode*>list1;
    stack<TreeNode*>list2;
    Traverse(root,p,list1);
    Traverse(root,q,list2);
    cout<<"traverse done "<<list1.size()<<" "<<list2.size()<<endl;
    TreeNode * Common = NULL;
    while(!list1.empty() && !list2.empty()){
       if(list1.top() == list2.top()){
           Common = list1.top(); 
	   list1.pop();
           list2.pop();	   
       }
       else
	   break; 
    }
    return Common;
}

bool Traverse(TreeNode * root,TreeNode *node,stack<TreeNode*>&path){
     if(root == NULL)
	     return false;
     if(root == node){
             path.push(node);
	     return true;
     }	     
     else{
         if(Traverse(root->left,node,path)){
	     path.push(root);
	     return true; 
	 }
	 else if(Traverse(root->right,node,path)){
	     path.push(root);
	     return true; 
	 }
         else{
	     return false;
	 }
     }

}
