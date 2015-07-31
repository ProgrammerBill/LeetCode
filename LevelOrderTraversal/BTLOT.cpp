#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode{
  int val;
  TreeNode * left;
  TreeNode * right;
  TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<vector<int> >levelOrder(TreeNode * root);
TreeNode * Initialize();
int main(){
 TreeNode * root = Initialize();
 vector<vector<int> > ret = levelOrder(root);
 for(unsigned int i = 0 ; i < ret.size();++i ){
    for(unsigned int j = 0; j < ret[i].size();++j){
      cout<<ret[i][j]<<" "; 
    }
    cout<<endl;
 }
 
 return 0;
}
vector<vector<int> >levelOrder(TreeNode * root){
   vector<vector<int> > result;
   if(root == NULL) return result;
   queue<TreeNode*>Q;
   Q.push(root);
   int visisted = 0;
   int currentCnt =1;
   int nextCnt = 0;
   vector<int >Oneline;
   while(!Q.empty()){
      TreeNode * tmp = Q.front();
      Q.pop();
      Oneline.push_back(tmp->val);
      visisted++;
      if(tmp->left != NULL){
          Q.push(tmp->left);
	  nextCnt++; 
      }
      if(tmp->right != NULL){
          Q.push(tmp->right);
	  nextCnt++; 
      }
      if(visisted == currentCnt){
         currentCnt = nextCnt;
	 visisted = 0;
	 nextCnt = 0;
	 result.push_back(Oneline);
	 Oneline.clear(); 
      }
   }
    return result;
}
TreeNode * Initialize(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    TreeNode *Rr = root->right;
    Rr->left = new TreeNode(15); 
    Rr->right = new TreeNode(7); 
    return root;
}
