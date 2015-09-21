#include<stdlib.h>
#include<stdio.h>
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;
/*
 *N is the total Number,First is the First one to action and val is the one who has to exit when they count
 *
 * */
void JosephCircle(int N,int First,int val){
    LinkList p,r,list,curr;
    p = (LinkList)malloc(sizeof(LNode));
    p->data = 0;
    p->next = p;
    curr = p;
    int i;
    for(i = 1; i < N ; i++){
        LinkList t = (LinkList)malloc(sizeof(LNode));
	t->data = i;
	curr->next = t;
	curr = t;
    }
    curr->next = p;    

    r = curr;
    while(First--){
        r = p;
	p = p->next;
    }
    while(N--){
       int s;	    
       for(s = val - 1;s--;r = p,p = p->next);
       r->next = p->next;
       printf("%d->",p->data);
       free(p);
       p = r->next;
    }
}

int main(){
   JosephCircle(13,4,5);
}



