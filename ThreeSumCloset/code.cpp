#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int threeSumClosest(vector<int>& nums, int target);
int main(){
 int a[] = {-1,2,1,-4};
 vector<int>A(a,a+4);
 int target = 1; 
 cout<<threeSumClosest(A,target);
 return 0;
}

int threeSumClosest(vector<int>& nums, int target) {
      if(nums.size() < 3) return 0;
      int closest = nums[0] + nums[1] + nums[2];
      sort(nums.begin(),nums.end()); 
      for(int first = 0 ;first < (int)nums.size() - 2 ;++first ){
         if(nums[first] == nums[first - 1] && first > 0) continue;
	 int second = first + 1;
         int third = nums.size() - 1;	 
         while(second < third){
	   int cursum = nums[first] + nums[second] + nums[third]; 
	   if(cursum == target) return cursum;
           if(abs(cursum - target) < abs(closest -target)){
	        closest = cursum; 
	   }
           if(cursum <= target)
               ++second;
           else
	      --third;
	 }     
      }
      return closest;           
}
