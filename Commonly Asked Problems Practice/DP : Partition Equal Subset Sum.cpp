/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2 != 0){ //if sum of all elements is odd we can't divide array into two halves
            return false;
        }
        
        bool** dp = new bool*[n+1];
        int w = sum/2;   //check wether subset of sum/2 is can be made ,if so then automatically other half contain elements that are not present in first array
        for(int i=0;i<=n;i++){
            dp[i] = new bool[w + 1];
            for(int j=0;j<=w;j++){
                dp[i][j] = false;
            }
        }
        
        
        for(int i=0;i<=n;i++){
            dp[i][0] = true;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                if(j >= nums[i-1]){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][w];
    }
};
