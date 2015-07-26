#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > threeSum(vector<int>& nums);
int main(){
 int a[] = {3,0,-2,-1,1,2};
 vector<int> A(a,a+6);
 vector<vector<int> > B = threeSum(A);
 
 for(int i = 0 ; i < B.size(); i++){
   for(int j = 0 ; j < B[i].size();j++){
      cout<<B[i][j]<<" ";
   }
   cout<<endl;
 }
 
 
 return 0;
}

vector<vector<int> > threeSum(vector<int>& nums) {
  vector<vector<int> > res;
  sort(nums.begin(),nums.end()); 
  for(int i = 0 ; i < (int)nums.size() - 2 ;++i){
      int target = -nums[i]; 
      int front = i + 1;
      int back = nums.size() - 1;
      
      while(front < back){
        int sum = nums[front] + nums[back];
	if(sum < target)
            front++;
	else if(sum > target) 
	    back--;
        else{
	    vector<int>triplet(3,0);
	    triplet[0] = nums[i];
	    triplet[1] = nums[front];
	    triplet[2] = nums[back]; 
	    res.push_back(triplet);
	    while(front < back && nums[front] == triplet[1]) front++;
	    while(front < back && nums[back] == triplet[2]) back--;
	}
      }
      while(i + 1 < (int)nums.size() && nums[i + 1] == nums[i])
	    i++;
  } 
  return res;
}
