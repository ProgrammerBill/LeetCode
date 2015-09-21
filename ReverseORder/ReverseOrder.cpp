/*
利用树状数组求逆数列的个数 
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int Length = 8;
struct Node{
    int data;
    int pos;
};
/*
由于Cn的范围2^k,ｋ是其对应二进制数的后缀为0的个数，由此需要求上一个
树的，只需要让i减去2的最小幂
*/
int LowBit(int num){
    return num & (num ^ (num - 1));
}
/*
即数组从大到小排列
*/
int cmp(const void *num1,const void *num2){
    return ((Node *)num2)->data - ((Node *)num1)->data;
}

int sum(int *TreeArray,int pos){
    int result = 0 ;
    while(pos){
       result += TreeArray[pos];
       pos -= LowBit(pos); 
    }
    return result;
}

void INC(int * TreeArray,int pos){
    while(pos < Length){
        TreeArray[pos]++;
        pos += LowBit(pos);	
    }
}

void insertNum(int *TreeArray,Node *seq,int &reverseNum){
    for(int i = 1; i < Length;++i){
        cout<<sum(TreeArray,seq[i].pos)<<endl;
    	reverseNum += sum(TreeArray,seq[i].pos);
        INC(TreeArray,seq[i].pos);	
    }
}

int main(){
 int array[] = {3,5,4,8,2,6,9};
 Node seq[Length];
 int TreeArray[Length];
 memset(TreeArray,0,sizeof(TreeArray));
 for(int i = 1;i < Length + 1;++i){
     seq[i].data = array[i - 1];
     seq[i].pos = i;   
 }
 qsort(seq + 1,Length - 1,sizeof(Node),cmp);
 for(int i = 1;i < Length + 1;++i)
     cout<<seq[i].data<<" ";
 cout<<endl;
 for(int i = 1;i < Length + 1;++i)
     cout<<seq[ip]<<" ";
 cout<<endl;


 int reverseNum = 0;
 insertNum(TreeArray,seq,reverseNum);
 cout<<reverseNum<<endl;
 for(int i = 0 ; i < Length;++i){
     cout<<TreeArray[i]<<" ";
 }
 return 0;
}
