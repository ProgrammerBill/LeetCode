#include <iostream>
using namespace std;
void Permutation(char *ptr);
void RecursivePermutation(char *ptr, char *pbegin);
bool isSwap(char * pBegin,char * pEnd);
int main(){
 char str[] = "122";
 Permutation(str);
 return 0;
}

/*
 *去重复的规则即从第一个字符起,与其后面与它不重复的字符向交换
 * */
bool isSwap(char * pBegin,char * pEnd){
   char * p;
   for(p = pBegin;p < pEnd;p++){
      if(*p == *pEnd){
         return false; 
      } 
   }
   return true;
}
void Permutation(char *ptr){
   if(ptr == NULL) return;
   else 
     RecursivePermutation(ptr,ptr);
}
void RecursivePermutation(char *ptr,char *pbegin){
    if(*pbegin == '\0'){
      cout<<ptr<<endl;
    }
    else{
      for(char *pCh = pbegin;*pCh != '\0';pCh++){
          if(isSwap(pbegin,pCh)){  
	   swap(*pCh,*pbegin);
  	   RecursivePermutation(ptr,pbegin + 1);
           swap(*pCh,*pbegin);
	  }  
      } 
    }
}
