#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x):val(x),next(NULL){}
};
void deleteNode(ListNode* node);
int main(){
    ListNode * root = new ListNode(1);
    ListNode * head = root; 
    
    while(root != NULL){
        cout<<root->val<<" "; 
        root = root->next;
    }
    root = head;
    deleteNode(root);
    cout<<endl;
    while(root != NULL){
        cout<<root->val<<" "; 
        root = root->next;
    }
    return 0;
}


void deleteNode(ListNode* node) {
   if(node == NULL) return;
   if(node->next == NULL){
       delete(node);
       node = NULL;
       return;
   }
   ListNode * next = node->next;
   ListNode * prev = node;
   while(next != NULL){
       node->val = next->val;
       prev = node;
       node = next;
       next = next->next;
   }
   prev->next = NULL; 
   delete(node);
}
