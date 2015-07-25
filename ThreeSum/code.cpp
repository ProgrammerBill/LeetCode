#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<vector<int> > threeSum(vector<int>& nums);
int Recursive(vector<int> & nums,int left,int right,int Target);
int main(){
 int a[] = {3,0,-2,-1,1,2};
 vector<int> A(a,a + 6);
 vector<vector<int> > B = threeSum(A);
 for(size_t i = 0 ; i < B.size();i++){
   for(size_t j = 0 ; j < B[i].size(); j++){
      cout<<B[i][j]<<" "; 
   }
   cout<<endl;
 } 
 return 0;
}

vector<vector<int> > threeSum(vector<int>& nums) {
   vector<vector<int> > result;
   if(nums.empty()) return result;     
   sort(nums.begin(),nums.end());
   set<pair<int,int> > exist;
   int left,right,mid;
   left = 0;
   right = (int)(nums.size() - 1); 
   while(nums[left] < 0){
      int tmp; 
      int leftIndex = left;
      int rightIndex = right;
      while(nums[rightIndex] > 0 ){
        if(2 * nums[rightIndex] + nums[leftIndex] < 0 ) break;
	int record = rightIndex;      
	tmp = -(nums[leftIndex] + nums[rightIndex]);
	mid = Recursive(nums,leftIndex,rightIndex,tmp);        	
        rightIndex = record;
	if(mid > 0){
	  bool Flag = true;	
          if(exist.find(make_pair(nums[left],nums[mid])) != exist.end()){
	    Flag = false;
	  }
	  if(Flag == true){
	    vector<int>Oneline;
            Oneline.push_back(nums[left]);
            Oneline.push_back(nums[mid]); 
            Oneline.push_back(nums[rightIndex]); 
            result.push_back(Oneline);
            exist.insert(make_pair(nums[left],nums[mid])); 
	  } 
	}
	--rightIndex;
      }
      ++left;
   }
   int count = 0;
   for(int i = 0 ;i < nums.size();i++){
      if(nums[i] == 0)
	    count++;
      if(count == 3){
	vector<int> Oneline(3,0);
	result.push_back(Oneline);
	break;
      }
   }
   return result;  
}

int Recursive(vector<int> & nums,int left,int right,int Target){
     if(left >= right) return 0;
     int mid = (left + right) / 2;
     if(mid == left || mid == right) return 0;
     if(nums[mid] < Target){
       return Recursive(nums,mid,right,Target);     
     }
     else if(nums[mid] > Target){
       return Recursive(nums,left,mid,Target);     
     }
     else{
       return mid; 
     }
}

