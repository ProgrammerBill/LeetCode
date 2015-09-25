#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
int main(){
  string str;
  getline(std::cin,str);
  size_t pos = 0;
  int m = 0,n = 0;
  vector<vector<int> >Map;
  while((pos = str.find(';')) != string::npos){
      vector<int> line;
      string Oneline = str.substr(0,pos);
      size_t sp =0;
      while((sp = Oneline.find(' ')) != string::npos){
           int digit = atoi(Oneline.substr(0,sp).c_str());
	   line.push_back(digit); 
	   Oneline = Oneline.substr(sp + 1);
      }
      line.push_back(atoi(Oneline.c_str()));
      n = line.size();
      Map.push_back(line);
      str = str.substr(pos + 1);
      if(str.find(';') == string::npos){
	  Oneline = str;
	  line.clear();
          while((sp = Oneline.find(' ')) != string::npos){
            int digit = atoi(Oneline.substr(0,sp).c_str());
	    line.push_back(digit); 
	    Oneline = Oneline.substr(sp + 1);
          }
	  line.push_back(atoi(Oneline.c_str()));
          Map.push_back(line);
      }
  }
  

  /*  
  for(size_t i = 0 ; i < Map.size();i++){
	  for(int j = 0; j < n;j++){
	      cout<<Map[i][j]<<" "; 
	  }
          cout<<endl;
  }
  */
  int sum = 0;
  m = Map.size();
  for(int i = 0 ; i < m - 1;i++){
      for(int j = 0 ; j < n - 1;j++){
          if(Map[i][j] + Map[i][j + 1] + Map[i + 1][j] + Map[i + 1][j+ 1] > sum){
	     sum = Map[i][j] + Map[i][j + 1] + Map[i + 1][j] + Map[i + 1][j+ 1];
	  } 
      }
  }
  cout<<sum<<endl;
  return 0;
}
