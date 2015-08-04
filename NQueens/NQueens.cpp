#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<string> >solveNQueens(int n);
void Permutation(vector<vector<string> > &ret,vector<int> &Position ,int index , int n);
bool Check(vector<int>One,int n);
void IntToString(vector<vector<string> >&ret,vector<int>&Position,int n);
int main(){
 int n;
 cin>>n;
 vector<vector<string> > ret = solveNQueens(n);
 for(int k = 0 ; k < (int)ret.size();k++){
     cout<<"number = "<<k + 1<<endl;
     for(int i = 0 ; i < n; ++i){
         cout<<ret[k][i]<<endl; 
     }
     cout<<endl;
 }
 return 0;
}
vector<vector<string> >solveNQueens(int n){
    vector<vector<string> >ret;
    if(n <= 0) return ret;
    vector<int>Position(n);
    //initialize 
    for(int i = 0 ; i < n ; i++){
        Position[i] = i; 
    }
    Permutation(ret,Position,0,n);    
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

void IntToString(vector<vector<string> >& ret,vector<int> & Position,int n){
    vector<string> One; 
    for(int i = 0 ; i < n; ++i){
        string element(n,'.');
	element[Position[i]] = 'Q';
        One.push_back(element);
    }
    ret.push_back(One);
}


void Permutation(vector<vector<string> > &ret,vector<int> &Position,int index,int n){
   if(index == n){
       if(Check(Position,n)){
           IntToString(ret,Position,n); 
       }
   }
   else{
       for(int i = index ; i < n; i++){
           swap(Position[index],Position[i]); 
           Permutation(ret,Position,index + 1,n);    
	   swap(Position[index],Position[i]); 
       }
   } 
}
