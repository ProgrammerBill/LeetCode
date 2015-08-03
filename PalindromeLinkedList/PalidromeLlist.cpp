#include<iostream>
using namespace std;
struct ListNode{
   int val;
   ListNode * next;
   ListNode(int x):val(x),next(NULL){}
};
ListNode * Intialize();
bool isPalindrome(ListNode * head);
int main(){
 ListNode *head = Intialize();
 cout<<isPalindrome(head);
 return 0;
}
ListNode * Reverse(ListNode * head);
ListNode * Intialize(){
   ListNode * head = new ListNode(1);
   ListNode * tmp = head;
   tmp->next = new ListNode(2);
   tmp = tmp->next;
   tmp->next = new ListNode(3);
   tmp = tmp->next;
   tmp->next = new ListNode(5);
   tmp = tmp->next;
   tmp->next = new ListNode(2);
   tmp = tmp->next;
   tmp->next = new ListNode(1);
   return head;
}
bool isPalindrome(ListNode * head){
   if(head == NULL || head->next == NULL) 
       return true;
   ListNode * fast = head;
   ListNode * slow = head;
   while(fast->next != NULL && fast->next->next != NULL){
       fast = fast->next->next;
       slow = slow->next; 
   }
   fast = slow->next;
   slow = NULL;
   ListNode * second = Reverse(fast);
   bool Flag = true;
   while(head != NULL && second != NULL){
       if(head->val == second->val){
          second = second->next;
          head = head->next;  
       }
       else{
           Flag = false;
	   break; 
       }
   }
   return Flag;
}
ListNode * Reverse(ListNode * head){
   ListNode *Rhead = NULL;
   ListNode *Rpre = NULL;
   ListNode *Rcur = head;
   while(Rcur != NULL){
       ListNode * Rnext = Rcur->next;
       if(Rnext == NULL)
           Rhead = Rcur; 
       Rcur->next = Rpre;     
       Rpre = Rcur;
       Rcur = Rnext;
   }
   return Rhead;
}






