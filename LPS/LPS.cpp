#include <iostream>
#include <string>
using namespace std;

string LPS_Dp(const string str);
int main(){
 int n;
 cin>>n;
 while(n--){
  string buffer;
  cin>>buffer;
  cout<<LPS_Dp(buffer)<<endl; 
 }
       
 return 0;
}

string LPS_Dp(const string str){
    int start = 0,maxlen = 1,n = str.size();
    bool isPal[1000][1000] = {false};
    for(int i = n - 1;i >= 0;i--){
        for(int j = i;j < n;j++){
            if((i + 1 > j - 1 || isPal[i + 1][j - 1]) && str[i] == str[j]){
	        isPal[i][j] = 1;
	        if(j - i + 1 > maxlen){
		    maxlen = j - i + 1;
		    start = i;
		} 	
	    } 
	
	} 
    }
    return str.substr(start,maxlen);
}



