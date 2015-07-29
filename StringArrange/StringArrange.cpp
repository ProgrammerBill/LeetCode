#include <iostream>
using namespace std;
void Permutation(char *ptr);
void RecursivePermutation(char *ptr, char *pbegin);
int main(){
 char str[] = "abc";
 Permutation(str);
 return 0;
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
           char temp = *pCh;
	   *pCh = *pbegin;
	   *pbegin = temp;
	    RecursivePermutation(ptr,pbegin + 1);
	    temp = *pCh;
	   *pCh = *pbegin;
	   *pbegin = temp;
      } 
    }
}
