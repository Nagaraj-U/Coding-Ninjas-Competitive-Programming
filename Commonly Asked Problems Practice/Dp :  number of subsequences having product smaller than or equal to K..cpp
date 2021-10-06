/*
Given a positive array, find the number of subsequences having product smaller than or equal to K.
Examples: 
 

Input : [1, 2, 3, 4] 
        k = 10
Output :11 
The subsequences are {1}, {2}, {3}, {4}, 
{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, 
{1, 2, 3}, {1, 2, 4}

Input  : [4, 8, 7, 2] 
         k = 50
Output : 9
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;

    vector<vector<int>> dp(n+1,vector<int>(k+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j/arr[i-1]] + 1;    //+1 since current element alone can make a subsequence
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}
