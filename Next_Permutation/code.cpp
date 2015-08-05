#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void nextPermutation(vector <int>& nums );
int main(){
 int a[] = {1,2};
 vector<int> array(a,a + 2);
 nextPermutation(array);
 for(unsigned int i = 0 ; i < array.size();i++ ){
   cout<<array[i];
 }
 return  0;
}
void nextPermutation(vector <int>& nums ){
  int End = nums.size() - 1;
  int p,q;
  p = End;
  int Find;
  while(p > 0){
    q = p;
    p--; 
    if(nums[q] > nums[p]){
       Find = End;
       while(nums[Find] <= nums[p]){
            Find--;
       }
       swap(nums[p],nums[Find]);
       reverse(nums.begin() + q,nums.end()); 
       return; 
    }
  }
  reverse(nums.begin(),nums.end());
}
