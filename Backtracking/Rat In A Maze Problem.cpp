/*
You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any 
direc­tion ( left, right, up and down).
Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.
Input Format
Line 1 : Integer N
Next N Lines : Each line will contain ith row elements (separated by space)
Output Format :
One Line for every possible solution. 
Every line will have N*N maze elements printed row wise and are separated by space. Only cells that are part of solution path should be 1, rest all cells should be 0.
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Sample Output 1 Explanation :
Only 1 path is possible
Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 
Sample Output 2 Explanation :
4 paths are possible
*/


#include<iostream>
using namespace std;

#include<bits/stdc++.h>

void printSolution(int** solution,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << solution[i][j] << " ";
        }
    }
    cout << endl;
}

void mazeHelper(int maze[][20],int n ,int** solution,int x,int y){
    if(x == n-1 && y == n-1){
        solution[x][y] = 1;
        printSolution(solution,n);
        solution[x][y] = 0;
        return;  
    }
    if(x < 0 || y < 0 || y >= n || x >= n || maze[x][y] == 0 || solution[x][y]==1){
        return ;     
    }
    solution[x][y] = 1;
    mazeHelper(maze,n,solution,x-1,y);
    mazeHelper(maze,n,solution,x+1,y);
    mazeHelper(maze,n,solution,x,y-1);
    mazeHelper(maze,n,solution,x,y+1);
    solution[x][y] = 0;
}

void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    int** solution = new int*[n];
    for(int i=0;i<n;i++){
        solution[i] = new int[n];
    }
    mazeHelper(maze,n,solution,0,0);
    return;
}


int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}


