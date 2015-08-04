#include <iostream>
#include <vector>
using namespace std;
int totalNQueens(int n);
void Permutation(vector<int> &Position,int &ret,int index , int n);
bool Check(vector<int>One,int n);
int main(){
 int n;
 cin>>n;
 int  ret = totalNQueens(n);
 cout<<ret<<endl;
 return 0;
}
int totalNQueens(int n){
    if(n <= 0) return 0;
    int ret = 0 ;
    vector<int>Position(n);
    //initialize 
    for(int i = 0 ; i < n ; i++){
        Position[i] = i; 
    }
    Permutation(Position,ret,0,n);    
    return ret;
}

bool Check(vector<int>One,int n){
    if(One.empty()) return false;
    for(int i = 0 ; i < n ; ++i){
        for(int j = i + 1; j < n; ++j){
            if(j - i == One[i] - One[j] || i - j == One[i] - One[j])
	        return false;	    
	}
    }
    return true;
}


void Permutation(vector<int> &Position,int &ret,int index,int n){
   if(index == n){
       if(Check(Position,n)){
           ret++;
       }
   }
   else{
       for(int i = index ; i < n; i++){
           swap(Position[index],Position[i]); 
           Permutation(Position,ret,index + 1,n);    
	   swap(Position[index],Position[i]); 
       }
   } 
}
