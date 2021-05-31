/*
Uncrossed Lines
Medium

1174

23

Add to List

Share
We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

nums1[i] == nums2[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.

 

Example 1:


Input: nums1 = [1,4,2], nums2 = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from nums1[1]=4 to nums2[2]=4 will intersect the line from nums1[2]=2 to nums2[1]=2.
Example 2:

Input: nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
Output: 3
Example 3:

Input: nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
Output: 2
 

Note:

1 <= nums1.length <= 500
1 <= nums2.length <= 500
1 <= nums1[i], nums2[i] <= 2000

*/

class Solution {
public:
    
    
    int helper(vector<int> v1,vector<int> v2,int len1,int len2,int n1,int n2,int** dp)
    {
        if(len1 <= 0 || len2 <= 0 ){
            return 0;
        }
        
        if(dp[n1][n2] != -1){
            return dp[n1][n2];
        }
        int ans  =0;
        if(v1[n1] == v2[n2]){
            ans  = 1 + helper(v1,v2,len1-1,len2-1,n1+1,n2+1,dp);
        }else{
            int op1 = helper(v1,v2,len1-1,len2,n1+1,n2,dp);
            int op2 = helper(v1,v2,len1,len2-1,n1,n2+1,dp);
            ans = max(op1,op2);
        }
        dp[n1][n2] = ans;
        return ans;
        
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        int** dp = new int*[nums1.size()+1];
        for(int i=0;i<=nums1.size();i++){
            dp[i] = new int[nums2.size()+1];
            for(int j=0;j<=nums2.size();j++){
                dp[i][j] = -1;
            }
        }
       return helper(nums1,nums2,nums1.size(),nums2.size(),0,0,dp);
    }
    
    
//     int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         int** dp = new int*[n1+1];
//         for(int i=0;i<=n1;i++){
//             dp[i] = new int[n2+1];
//             for(int j=0;j<=n2;j++){
//                 dp[i][j] = 0;
//             }
//         }
        
//         for(int i=1;i<=n1;i++){
//             for(int j=1;j<=n2;j++){
//                 if(nums1[i-1] == nums2[j-1]){
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 }else{
//                     dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
        
//         return dp[n1][n2];
//     }
};
