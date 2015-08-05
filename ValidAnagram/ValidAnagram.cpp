#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isAnagram(string s, string t) {
   sort(s.begin(),s.end());
   sort(t.begin(),t.end());
   return s.compare(t)?false:true;   
}
int main(){
 string A = "anagram";
 string B= "nagaram";
 cout<<isAnagram(A,B);
 return 0;
}
