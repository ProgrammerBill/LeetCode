#include<iostream>
#include<vector>
using namespace std;
void OddFirstEvenEnd(vector<int>&array){
    if(array.empty() || array.size() == 1)return;
    int head = 0;
    int end = array.size();
    int index = head - 1;
    vector<int>::iterator itr = array.begin();
    while(head < end){
        if(array[head] % 2 == 0){
	    head++;	
	}
	else{
	    if(index != -1 )
	        itr = array.insert(); 
	    head++;
	    index++;
	}

    
    }   
}
int main(){
 int array[] = {1,2,3,4,5,6,7};
 vector<int> A(array,array + 7);
 OddFirstEvenEnd(A);
 for(vector<int>::const_iterator itr = A.begin();itr != A.end();++itr){
     cout<<*itr<<" ";
 }
 return 0;
}
