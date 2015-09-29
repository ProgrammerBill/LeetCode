#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef multimap<int,int>::iterator it;
int Count(multimap<int,int>& map,int n,int m);

int main(){
 int N,M;
 while(cin>>N>>M){
  if(N == 0 && M == 0) break;
  multimap<int,int>Map;
  int first,second;
  for(int i = 0; i < M;i++){
      cin>>first>>second; 
      Map.insert(make_pair(first,second));  
      Map.insert(make_pair(second,first));  
  }
  cout<<Count(Map,N,M)<<endl;
 }
 return 0;
}

int Count(multimap<int,int>&map,int n,int m){
    int count = -1;
    queue<int> q1;
    q1.push(1);
    int tmp;
    vector<bool>abandon(n,false);
    abandon[0] = true;
    while(!q1.empty()){ 
       tmp = q1.front(); 
       q1.pop();
       count++;
       abandon[tmp - 1] = true;
       it beg = map.lower_bound(tmp);
       while(beg != map.upper_bound(tmp)){
           if(abandon[beg->second - 1] == false)
	       q1.push(beg->second);
           ++beg;	   
       }
    }
    return count;
}
