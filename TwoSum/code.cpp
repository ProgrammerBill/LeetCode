#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target);

int main(){
 int a[] = {3,2,4};
 vector<int> A(a,a+3);
 vector <int> B = twoSum(A,6);
 vector<int>::iterator it;
 for(it = B.begin();it != B.end();it++){
   cout<<*it<<" ";
 }
 return 0;
}

vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int,int>myMap;
        for(size_t i = 0 ; i < nums.size();i++){
            myMap.insert(make_pair(nums[i],i+1));
        }
        vector<int> result;
        for(size_t i = 0 ; i < nums.size();i++){
            multimap<int,int>::iterator itr;
            int tmp = target - nums[i];
            itr = myMap.lower_bound(tmp);
            while(itr != myMap.upper_bound(tmp)){
               if((int)(i + 1)!= itr->second){
	    	result.push_back(i+1);
                result.push_back(itr->second);
		return result;
	       }
               itr++;	       
	    }
        }
	return result;
}
