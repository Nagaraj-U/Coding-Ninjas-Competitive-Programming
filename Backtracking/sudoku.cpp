/*
Sudoku
Write a program to find a solution to a sudoku puzzle. The input will consist of puzzles with exactly one solution. Or in other words, the Sudoku solved must be a legitimate Sudoku!

Input
The input consists of one test case. Each test case will consist of nine lines with nine digits on each line. There will not be any blanks between the digits. The digits '1' through '9' will represent a number and the digit '0' will represent a blank square. The end of input is indicated by the end of the file.

Output
For each test case print, in the format shown below, the solved puzzle. There should be no spaces between digits and lines.

Example
Input:
023456789
406789123
780123456
234067891
567801234
891230567
345678012
678912305
912345670


Output:
123456789
456789123
789123456
234567891
567891234
891234567
345678912
678912345
912345678
*/






#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define n 9



bool isSafeInRow(int grid[n][n],int row,int num){
    for(int i=0;i<n;i++){
        if(grid[row][i] == num){
            return false;
        }
    }
    return true;
}

bool isSafeInCol(int grid[n][n],int col,int num){
    for(int i=0;i<n;i++){
        if(grid[i][col] == num){
            return false;
        }
    }
    return true;
}




bool isSafeInGrid(int grid[n][n],int row,int col,int num){
    int rowFactor = row - (row%3);
    int colFactor = col - (col%3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i+rowFactor][j+colFactor] == num){
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int grid[n][n],int row,int col,int num){
    if(isSafeInRow(grid,row,num) && isSafeInCol(grid,col,num) && isSafeInGrid(grid,row,col,num)){
        return true;
    }
    return false;
}

bool findEmptyLocation(int grid[n][n],int &row,int &col){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}


bool solveSudoku(int grid[n][n]){
    int row,col;
    if(!findEmptyLocation(grid,row,col)){
        return true;
    }
    for(int i=1;i<=9;i++){
        if(isSafe(grid,row,col,i)){
            grid[row][col] = i;
            if(solveSudoku(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int grid[n][n];
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<s.length();j++){
            grid[i][j] = s[j] - '0';
        }
    }
    solveSudoku(grid);
    cout << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << grid[i][j] ;
        }
        cout << endl;
    }
    return 0;
}
