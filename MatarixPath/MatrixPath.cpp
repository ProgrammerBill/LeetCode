#include<iostream>
#include<cstring>
using namespace std;
bool hasPath(char* matrix, int rows, int cols, char* str);
bool hasPathCore(char * matrix,int rows,int cols,int row,int col,
char * str,int & pathLength,bool *visited);
int main(){
 char matrix[] = "abcesfcsadee";
 char str[] = "bcced";
 cout<<hasPath(matrix,3,4,str)<<endl;
 return 0;
}
bool hasPath(char* matrix, int rows, int cols, char* str){
    if(matrix == NULL || rows <= 0 || cols <= 0 || str == NULL)
	    return false;
    bool *visited = new bool[rows * cols];
    memset(visited,false,rows * cols);
    int pathLength = 0 ;
    for(int row = 0;row < rows;++row){
	for(int col = 0 ;col < cols; ++col){
        	if(hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited))
			return true;
	}
    }
    delete []visited;
    return false;
}

bool hasPathCore(char * matrix,int rows,int cols,int row,int col,
char * str,int & pathLength,bool *visited){
    if(str[pathLength] == '\0')
	    return true;
    bool hasPath = false;
    if(row >= 0 && row < rows && col >=0 && col < cols 
    && matrix[row * cols + col] == str[pathLength] 
    && visited[row * cols + col] == false){
       ++pathLength; 
       visited[row * cols + col] = true;
       hasPath = hasPathCore(matrix,rows,cols,row + 1,col,str,pathLength,visited) 
 ||  hasPathCore(matrix,rows,cols,row - 1,col,str,pathLength,visited)
 ||  hasPathCore(matrix,rows,cols,row,col - 1,str,pathLength,visited)
 ||  hasPathCore(matrix,rows,cols,row,col + 1,str,pathLength,visited);
     if(!hasPath){
         --pathLength;
	 visited[row * cols + col] = false;
     }
   }
   return hasPath;
}
