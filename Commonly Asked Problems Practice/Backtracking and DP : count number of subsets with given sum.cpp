#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;


//RECURSION
int helper(vector<int> &arr,int start,int n,int k)
{
    if(start == n){
        if(k==0){
            return 1;
        }
        return 0;
    }
    
    if(k < 0){
        return 0;
    }
    
    if(k == 0){
        return 1;
    }

	int count = 0;
    count += helper(arr,start+1,n,k);
    count += helper(arr,start+1,n,k-arr[start]);
    return count;
        
}



//DP
int helper(vector<int> arr,int start,int n,int k){
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[k+1];
    }
    
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    
    for(int i=1;i<=k;i++){
        dp[0][i] = 0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j-arr[i-1] >=0){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][k];
}


int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        cout << helper(arr,0,n,k) << endl;
    }
    return 0;
}
