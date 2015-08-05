#include <iostream>
using namespace std;
int g_number = 0;
void EightQueen();
void Permutation(int * ,int , int);
bool Check(int *,int);
void Print(int *,int);
int main(){
 EightQueen();
 return 0;
}

void EightQueen(){
    const int queens = 8;
    int ColumnIndex[queens];
    //Init
    for(int i = 0 ; i < queens; ++i ){
        ColumnIndex[i] = i; 
    }
    Permutation(ColumnIndex,queens,0);
}

bool Check(int * ColumnIndex,int length){
    for(int i = 0 ; i < length; ++i){
       //because i is not equal to j, so we just need to check if
       //it is in a diagonal line	    
       for(int j = i + 1 ; j < length ;++j){
           //Check if both of these position are in a diagonal
	   if(i - j == ColumnIndex[i] - ColumnIndex[j] ||
		j - i == ColumnIndex[i] - ColumnIndex[j]){
               return false; 	   
	   }           
       }
    }
    return true;
}


void Permutation(int * ColumnIndex,int length,int index){
   if(length == index){
       if(Check(ColumnIndex,length)){
           g_number++; 
           Print(ColumnIndex,length); 
       } 
   }
   else{
       for(int i = index ; i < length;++i ){
           swap(ColumnIndex[index],ColumnIndex[i]); 
           Permutation(ColumnIndex,length,index + 1);
	   swap(ColumnIndex[index],ColumnIndex[i]); 
       }
   } 
}

void Print(int * ColumnIndex,int length){
    cout<<"g_number = "<<g_number<<endl;
    for(int i = 0 ; i < length ; i++){
	    cout<<ColumnIndex[i]<<endl;
    }
    cout<<endl;
}
