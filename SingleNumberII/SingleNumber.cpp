#include <iostream>
#include <vector>
using namespace std;
int singleNumber(vector<int> &nums){
   if(nums.empty()) return 0;
   int bits[32] = {0};
   int ret = 0; 
   for(int i = 0 ; i < 32;++i){
       for(int j = 0 ; j < (int)nums.size();++j){
            bits[i] += (nums[j]>>i) & 1;  
       }
       ret |= ( (bits[i] % 3) << i );
   }
   return ret; 
}
int main(){
   int a[] = {1,1,2,1,4,8,6,8,6,2,6,8,2};
   vector<int> A(a,a + sizeof(a)/sizeof(int));
   cout<<singleNumber(A)<<endl;
   return 0;
}
