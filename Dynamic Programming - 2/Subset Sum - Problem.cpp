/*
Subset Sum - Problem
Send Feedback
Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
Input Format
First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Sample Input
3
1 2 3
4
Sample Output
Yes
*/


#include <bits/stdc++.h>
using namespace std;


//RECURSIVE SOLUTION
bool getAns(int* arr,int n,int sum,int** dp){
    if(n == 0){
        if( sum > 0){
            return false;
        }else{
            return true;
        }
    }
    if(n < 0){
        return false;
    }
    
    if(dp[n][sum] >= 0){
        return dp[n][sum];
    }
    
    bool ans;
    if(arr[n-1] <= sum){
        bool option1 = getAns(arr,n-1,sum-arr[n-1],dp);
        bool option2 = getAns(arr,n-1,sum,dp);
        ans = (option1 || option2);
    }else{
        bool option1 = getAns(arr,n-1,sum,dp);
        ans = option1;
    }
    
    dp[n][sum] = ans;
    return ans;
}



//ITERRATIVE SOLUTION
// bool getAns(int* arr,int n,int sum){
//     bool** dp = new bool*[n+1];
//     for(int i=0;i<=n;i++){
//         dp[i] = new bool[sum+1];
//     }
    
//     for(int i=0;i<=sum;i++){
//         dp[0][i] = false;
//     }
    
//     for(int i=0;i<=n;i++){
//         dp[i][0] = true;
//     }
    
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=sum;j++){
//             dp[i][j] = dp[i-1][j];
//             if(j >= arr[i-1]){
//                 dp[i][j] = (dp[i][j] || dp[i-1][j - arr[i-1]]);
//             }
//         }
//     }
//    if(dp[n][sum]){
//        return true;
//    }else{
//        return false;
//    }
    
// }



//ITERATIVE SOLUTION WITH REDUCED SPACE COMPEXEITY
// bool getAns(int* arr,int n,int sum){
//     bool** dp = new bool*[2];
//     for(int i=0;i<=1;i++){
//         dp[i] = new bool[sum+1];
//     }
    
//     for(int i=0;i<=sum;i++){
//         dp[0][i] = false;
//     }
    
//     dp[0][0] = true;
//     int flag = 1;  //start filling from first row using zeroth row and keep toggling(1 ^ 0 = 1 and 1 ^ 1 = 0)
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=sum;j++){
//             dp[flag][j] = dp[flag ^ 1][j];
//             if(j >= arr[i-1]){
//                 dp[flag][j] = (dp[flag][j] || dp[flag ^ 1][j-arr[i-1]]);
//             }
//         }
//         flag = flag ^ 1; //toggling flag to fill zeroth row using first row
//     }
//     bool ans = dp[flag ^ 1][sum];
//     return ans;
// }





int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[sum+1];
        for(int j=0;j<=sum;j++){
            dp[i][j] = -1;
        }
    }
    
    
    //for recursive solution
    
    if( getAns(arr,n,sum,dp)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    //for iterative solution 
    
    // if(getAns(arr,n,sum)){
    //     cout << "Yes" << endl; 
    // }else{
    //     cout << "No" << endl;
    // }
    
    
    
    //for iterative solution  with reduced space
    
    // if(getAns(arr,n,sum)){
    //     cout << "Yes" << endl; 
    // }else{
    //     cout << "No" << endl;
    // }
    return 0;
}
