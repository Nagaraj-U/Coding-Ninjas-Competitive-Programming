/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
Example 4:

Input: coins = [1], amount = 1
Output: 1
Example 5:

Input: coins = [1], amount = 2
Output: 2
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(M+1,vector<int>(V+1,0));
	    
	    for(int i=1;i<=V;i++){//if no coins exist (make it as infinity)
	        dp[0][i] = 10000;
	    }
	    
	    for(int i=1;i<=M;i++){
	        for(int j=1;j<=V;j++){
	            if(j >= coins[i-1]){
	                dp[i][j] = min(1 + dp[i][j-coins[i-1]] , dp[i-1][j]);
	            }else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    return dp[M][V] == 10000 ? -1 : dp[M][V];
	} 
	  
};
