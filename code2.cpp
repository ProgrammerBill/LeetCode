#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;
int main(){
 vector<int>myVec;
 string str; 
 getline(std::cin,str);
 size_t pos;
 while((pos = str.find(' ')) != string::npos){
     string line = str.substr(0,pos);
     int digit = atoi(line.c_str()); 
     myVec.push_back(digit);
     str = str.substr(pos + 1);
 }
 myVec.push_back(atoi(str.c_str()));
 

 size_t maxlen = 0;
 int sum = 0;
 vector<int>MaxLine;
 for(size_t i = 0; i < myVec.size();i++){
     vector<int>tmp;
     for(size_t j = i;j < myVec.size();j++){
        sum += myVec[j];
	tmp.push_back(myVec[j]);
          if(sum == 0 && tmp.size() > maxlen){
	      maxlen = tmp.size();
	      MaxLine = tmp;
	  }    	
	}	
 }

 for(size_t i = 0; i < MaxLine.size();i++){
     cout<<MaxLine[i]<<" "; 
 }


 return 0;
}
