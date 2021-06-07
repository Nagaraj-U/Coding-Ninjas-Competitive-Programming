#include<bits/stdc++.h>
using namespace std;

void print(int** sol,int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int row,int col,int n,int** arr,int** sol)
{
    if(row >= n || col >= n || row < 0 || col < 0 || arr[row][col] == 0 || sol[row][col]){
        return false;
    }
    return true;
}



bool helper(int** arr,int** &sol,int row,int col,int n)
{
    
    if(row == n-1 && col == n-1){
        sol[row][col] = 1;
        print(sol,n);
        return true;
    }
    
    if(isSafe(row,col,n,arr,sol)){
        sol[row][col] = 1;
        if(helper(arr,sol,row+1,col,n)){
            return true;
        }
        if(helper(arr,sol,row,col+1,n)){
            return true;
        }
        sol[row][col] = 0;
        return false;
    }
    return false;
    
}

int main()
{
    int n;
    cin >> n;
    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    int** sol = new int*[n];
    for(int i=0;i<n;i++){
        sol[i] = new int[n];
        for(int j=0;j<n;j++){
            sol[i][j] = 0;
        }
    }
    bool ans = helper(arr,sol,0,0,n);
    return 0;
}
