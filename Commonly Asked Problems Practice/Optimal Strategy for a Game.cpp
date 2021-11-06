/*
877. Stone Game
Medium

1678

1798

Add to List

Share
Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. 
This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

 

Example 1:

Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alice, so we return true.
Example 2:

Input: piles = [3,7,2,3]
Output: true
 

Constraints:

2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles[i]) is odd.



*/
https://leetcode.com/problems/stone-game/


/*
	Time complexity: O(N ^ 2)
	Space Complexity: O(N ^ 2)
	
	Where N is the number of coins. 
*/

class Solution {
public:
    
    int helper(vector<int> &piles,int start,int end,int n,vector<vector<int>> &dp){
        if(n == 0){
            return 1000000;
        }
        
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        
        int option1 = piles[start] + helper(piles,start+1,end,n-1,dp);
        int option2 = piles[end] + helper(piles,start,end-1,n-1,dp);
        
        dp[start][end] = min(option1,option2);//since bob also playing optimally
        return dp[start][end];
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int total = 0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            total += piles[i];
        }
        int aliceCount = helper(piles,0,n-1,n,dp);
        int bobCount = total - aliceCount;
        
        return aliceCount > bobCount;
    }
};
