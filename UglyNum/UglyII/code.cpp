#include<iostream>
using namespace std;
int nthUglyNumber(int n);
int main(){
 cout<<"Please input the index"<<endl;
 int n;
 cin>>n;
 cout<<"the Ugly Num is "<<nthUglyNumber(n)<<endl;
 return 0;
}

int Min3(int a,int b,int c){
   int min = (a < b)?a:b;
   return (c < min)?c:min;
}


int nthUglyNumber(int n){
  if(n <= 0) return 0;
  int * UglyNum = new int[n];
  UglyNum[0] = 1;
  int nextIndex = 1;
  int *p1 = UglyNum;
  int *p2 = UglyNum;
  int *p3 = UglyNum;
  while(nextIndex <= n){
   int min = Min3( *p1 * 2 , *p2 * 3, *p3 * 5 );
   UglyNum[nextIndex] = min;
   while(*p1 * 2 <= min){
       p1++;
   }   
   while(*p2 * 3 <= min){
       p2++;
   }   
   while(*p3 * 5 <= min){
       p3++;
   }   
   nextIndex++;
  }
  int ret = UglyNum[ n - 1];
  delete []UglyNum;
  return ret; 
}
