/*
Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output Format:
Line 1 : Size of maximum square sub-matrix
Sample Input :
3 3
1 1 0
1 1 1
1 1 1
Sample Output :
1
*/


#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int findMaxSquareWithAllZeros(int** arr,int row,int col){
    int maximum = 0;
    int** temp = new int*[row];
    for(int i=0;i<row;i++){
        temp[i] = new int[col];
    }
    
    if(arr[0][0] == 0){
        temp[0][0] = 1;
        maximum = 1;
    }else{
        temp[0][0] = 0;
    }
    
    for(int i=1;i<col;i++){
        if(arr[0][i] == 0){
            temp[0][i] = 1;
        }else{
            temp[0][i] = 0;
        }
        maximum = max(maximum,temp[0][i]);
    }
    
    for(int i=1;i<row;i++){
        if(arr[1][0] == 0){
            temp[i][0] = 1;
        }else{
            temp[i][0] = 0;
        }
        maximum = max(maximum,temp[i][0]);
    }
    
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(arr[i][j] == 1){
                temp[i][j] = 0;
            }else{
                if(temp[i-1][j] >= 1 && temp[i][j-1] >= 1 && temp[i-1][j-1] >= 1){
                    temp[i][j] = 1+min(temp[i-1][j-1],min(temp[i-1][j],temp[i][j-1]));
                }else{
                    temp[i][j] = 1;
                }
            }
            maximum = max(maximum,temp[i][j]);
        }
    }
    return maximum;
}


