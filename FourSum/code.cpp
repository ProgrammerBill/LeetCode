#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;
vector< vector<int> > fourSum(vector<int>& nums, int target);
int main(){
 int a[] = {1,0,-1,0,-2,2};
 vector<int>A(a,a + 6);
 vector<vector<int> >B = fourSum(A,0);
 
 for(int i = 0 ;i < B.size();i++ ){
   for(int j = 0 ; j < B[i].size();j++){
      cout<<B[i][j]<<" "; 
   }
   cout<<endl;
 }
 
 
 return 0;
}
vector <vector<int> > fourSum(vector<int>& nums, int target) {
    vector<vector<int> >res;
    if(nums.size() < 4) return res;
    sort(nums.begin(),nums.end());
    
    for(unsigned int i = 0 ;i < nums.size() - 3; i++){
       int target3 = target - nums[i];  
       for(unsigned int j = i + 1;j < nums.size() - 2; j++){
           int target2 = target3 - nums[j]; 
           int front = j + 1;
	   int back = nums.size() - 1;
           while(front < back){
              int sum = nums[front] + nums[back];
              if(sum < target2){
	         front++; 
	      }
	      else if(sum > target2){
	         back--; 
	      }
	      else{
	         vector<int>quadruplet(4,0);
                 quadruplet[0] = nums[i];
                 quadruplet[1] = nums[j];
                 quadruplet[2] = nums[front];
                 quadruplet[3] = nums[back];
                 res.push_back(quadruplet);		  
                 while(front < back && nums[front] == quadruplet[2]) front++;
		 while(front < back && nums[back] == quadruplet[3]) back--;
	      }
	   }
           while( j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
       } 
           while( i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
    }
    return res;
}
