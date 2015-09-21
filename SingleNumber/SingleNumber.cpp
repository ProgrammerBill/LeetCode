#include <iostream>
#include <vector>
using namespace std;
int singleNumber(vector<int> &nums){
   if(nums.empty()) return 0;
   int ret = nums[0];
   for(int i = 1; i < nums.size();++i){
       ret ^= nums[i];
   }   
   return ret;
}
int main(){
   int a[9] = {1,1,2,4,6,8,6,8,4};
   vector<int> A(a,a + 9);
   cout<<singleNumber(A);
   return 0;
}
