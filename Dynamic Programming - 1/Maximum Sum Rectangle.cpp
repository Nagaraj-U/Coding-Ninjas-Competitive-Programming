/*
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/



#include <bits/stdc++.h>
using namespace std;

//to get max subarray sum
int kadane(int* arr,int n){
    int best_sum = INT_MIN;
    int cur_sum = 0;
    for(int i=0;i<n;i++){
        cur_sum += arr[i];
        if(cur_sum > best_sum){
            best_sum = cur_sum;
        }
        if(cur_sum < 0){
            cur_sum = 0;
        }
    }
    return best_sum;
}

int getSum(int** arr,int m ,int n){
    
    int maxsum = INT_MIN;
    for(int left = 0;left<n;left++){
        int* temp = new int[n](); // to store sum
        for(int right = left;right<n;right++){
            for(int i=0;i<m;i++){
                temp[i] += arr[i][right]; 
            }
            maxsum = max(maxsum,kadane(temp,n)); //getting max subarray sum between (left - right) from (top - bottom)
        }
    }
    return maxsum;
}

int main()
{
    int m,n;
    cin >> m >> n;
    int** arr = new int*[m];
    for(int i=0;i<m;i++){
        arr[i] = new int[n];
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    cout << getSum(arr,m,n) << endl;
    return 0;
}
