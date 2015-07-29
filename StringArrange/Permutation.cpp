#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool NextPermutation(char *A);
int main(){
 char str[] = "bac";
 sort(str,str+3); 
 do{
  cout<<str<<endl; 
 }
 while(NextPermutation(str)); 
 return 0;
}
/*
 *全排列的非递归形式,就是从后向前找到替换数和替换点,比如数字926520,首先从后找到第一个非递增数字组合,即20,52,65都不能满足,直到26,其中2为替换数,
 于是从2后,再从后往前找比2大的数,与替换数进行交换,即5,替换为956220,并将
 替换数位置后的数进行倒序得,950226
 *
 * */
bool NextPermutation(char *A){
  if(A == NULL || strlen(A) == 0)return false;
  char *pEnd = A + strlen(A);
   
  char * p = pEnd;
  char * q;
  char * pFind;
  while(p != A){
      q = p;
      p--; 
      if(*p < *q){
          pFind = pEnd;
	  while(*pFind < *p){
	     --pFind;
	  }
          swap(*p,*pFind);
	  reverse(q,pEnd);
	  return true; 
      }
  }
  reverse(A,pEnd); 
  return false;
} 
