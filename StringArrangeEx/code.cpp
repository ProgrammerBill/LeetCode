#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void Combination(char *A);
void ReverseCombination(char * A,int i,vector<char> &One);
int main(){
 char str[] = "abc";
 Combination(str);
 return 0;
}

void Combination(char * A){
  if(A == NULL) return;
  int size = strlen(A);
  vector<char> oneLine;
  for(int i = 1 ;i <= size; i++){
    ReverseCombination(A,i,oneLine); 
  }
}

void ReverseCombination(char * A,int i,vector<char> &One){
   if(A == NULL) return;
   if(i == 0){
      vector<char>::iterator itr = One.begin();
      for(;itr != One.end();++itr){
          cout<<*itr;
      } 
      cout<<endl;
      return; 
   }
   if(*A == '\0')
      return;
   /*
    *put the first element into the vector,and then 
    reverse to next one,to get i - 1 element
    or
    do not put the first element into the vector,just 
    reverse to next step,and get i element
    * */
   One.push_back(*A);
   ReverseCombination(A + 1,i - 1,One);
   One.pop_back();
   ReverseCombination(A + 1,i,One);
}
