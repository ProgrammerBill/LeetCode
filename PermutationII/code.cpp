#include <iostream>
#include <vector>
using namespace std;
vector <vector <int> > permuteUnique(vector<int> &nums); 
void RecursivePermute(vector<int>& nums,int i,vector<vector <int> >& result);
bool IsSwap(int i,vector<int>&nums);
int main(){
 int a[] = {1,1,2};
 vector<int> array(a,a + 3);
 vector<vector <int> > result = permuteUnique(array);
 for(unsigned int i = 0 ;i < result.size();i++){
     for(unsigned int j = 0 ;j < result[i].size();j++){
        cout<<result[i][j];
     }
     cout<<endl;
 }
 return 0;
}

vector <vector <int> > permuteUnique(vector<int> &nums){
     vector<vector<int> >result;
     if(nums.size() == 0)
	     return result;
     RecursivePermute(nums,0,result);
     return result;
} 

void RecursivePermute(vector<int>& nums,int i,vector<vector <int> >& result){
   if(nums.empty()) return;
   if(i == (int)nums.size() - 1){
      result.push_back(nums);    
   }
   else{
      for(int j = i;j < (int)nums.size();j++){
	if(IsSwap(j,nums)){
         swap(nums[i],nums[j]); 
         RecursivePermute(nums,i + 1,result);   
	 swap(nums[i],nums[j]); 
	}
      }
   }
}
bool IsSwap(int i,vector<int>&nums){
    if(nums.empty()) return false;
    for(int j = i + 1;j < (int)nums.size();j++){
       if(nums[i] == nums[j]) 
          return false;
    }
    return true;
}
