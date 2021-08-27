/*

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, 
but merely to decide in which order to perform the multiplications.
We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product,
the result will be the same. For example, if we had four matrices A, B, C, and D, we would have: 

(ABC)D = (AB)(CD) = A(BCD) = ....
However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency. 
For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,  

(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations./*
*/
#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int helper(vector<int> &arr,int start,int end){
    if(start == end){//cost to multiply same matrix is 0
        return 0;
    }

    if(dp[start][end] != 0){
        return dp[start][end];
    }

    int ans = INT_MAX;
    for(int i=start;i<end;i++){//  < end , since if we move till last we get one less dimension for matrix 
        int temp = helper(arr,start,i) + helper(arr,i+1,end) + (arr[start-1] * arr[i] * arr[end]);
        ans = min(ans,temp);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << helper(arr,1,n-1);
    return 0;
}
