#include<iostream>
using namespace std;
 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
 };
TreeNode *Convert(TreeNode * pRootOfTree);
void RecursiveConvert(TreeNode * pNode,TreeNode **pLast);
TreeNode * Initialize();
int main(){
 TreeNode * root = Initialize();
 root = Convert(root); 
 TreeNode * leftToright = root;
 while(leftToright != NULL){
    cout<<leftToright->val;
    if(leftToright->right != NULL){
	cout<<"->";
        leftToright = leftToright->right;
    }
    else
	break;    
 }
 cout<<endl;
 TreeNode * rightToleft = leftToright;
 cout<<endl;
 while(rightToleft != NULL){
    cout<<rightToleft->val;
    if(rightToleft->left != NULL){
	cout<<"<-";
        rightToleft = rightToleft->left;
    }
    else
	break;
 }
 
 return 0;
}

TreeNode *Convert(TreeNode * pRootOfTree){
   TreeNode * pLastNodeInList = NULL;
   RecursiveConvert(pRootOfTree,&pLastNodeInList);
   TreeNode *pHead = pLastNodeInList;
   while(pHead != NULL && pHead->left != NULL){
       pHead = pHead->left;
   }
   return pHead; 
}

void RecursiveConvert(TreeNode * pNode,TreeNode ** pLast){
   if(pNode == NULL) return;    
   TreeNode * current = pNode;
   if(pNode->left != NULL){
     RecursiveConvert(pNode->left,pLast);
   }
   current->left = *pLast;
   if(*pLast != NULL)
      (*pLast)->right = current;
   *pLast = current;
   if(pNode->right != NULL){
     RecursiveConvert(pNode->right,pLast); 
   }
}

TreeNode* Initialize(){
    TreeNode * root = new TreeNode(10); 
    root->left = new TreeNode(8);
    root->right = new TreeNode(13);
    TreeNode * Rleft = root->left; 
    TreeNode * Rright = root->right; 
    Rleft->left = new TreeNode(2); 
    Rleft->right = new TreeNode(9); 
    Rright->left = new TreeNode(12); 
    Rright->right = new TreeNode(15); 
    return root;
}

