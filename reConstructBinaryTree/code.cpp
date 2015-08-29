#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x),left(NULL),right(NULL) {}
};
TreeNode * RecursiveConstruct(vector<int>pre,int pbegin,int pend,vector<int>in ,int ibegin,int iend);
struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
          if(pre.empty() || in.empty()) return NULL;
          return RecursiveConstruct(pre,0,pre.size() - 1,in,0,in.size() - 1);
    }
    TreeNode * RecursiveConstruct(vector<int>pre,int pbegin,int pend,vector<int>in ,int ibegin,int iend){
          int Val = pre[pbegin];
          TreeNode * root = new TreeNode(Val);
          if(pbegin == pend){
              if(ibegin == iend){
                  return root;
              }
              else return NULL;
          }
          int tmp = ibegin;
          while(in[tmp] != Val && tmp < iend){
              tmp++;
          }
          if(in[tmp] != Val && tmp == iend)
              return NULL;
          int LeftLen = tmp - ibegin;
          int RightLen = iend - tmp;
          if(LeftLen > 0){
              root->left = RecursiveConstruct(pre,pbegin + 1,pbegin + LeftLen,in,ibegin,tmp - 1);
          }
          if(RightLen > 0){
              root->right = RecursiveConstruct(pre,pbegin + LeftLen + 1,pend,in,tmp + 1,iend);
          }  
          return root;
          
    }

int main(){
   int a[] = {1,2,4,7,3,5,6,8};
   int b[] = {4,7,2,1,5,3,8,6};
   vector<int> pre(a,a + 8);
   vector<int> in(b,b + 8);
   TreeNode * root = reConstructBinaryTree(pre,in);
   cout<<root->val<<endl;
   cout<<root->left->val<<endl;   
   cout<<root->right->val<<endl;   
}
