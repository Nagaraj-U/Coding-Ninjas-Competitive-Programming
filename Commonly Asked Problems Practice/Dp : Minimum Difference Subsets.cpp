/*

Given an integer array A containing N integers.

You need to divide the array A into two subsets S1 and S2 such that the absolute difference between their sums is minimum.

Find and return this minimum possible absolute difference.

NOTE:

Subsets can contain elements from A in any order (not necessary to be contiguous).
Each element of A should belong to any one subset S1 or S2, not both.
It may be possible that one subset remains empty.


Problem Constraints
1 <= N <= 100

1 <= A[i] <= 100



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the minimum possible difference among the sums of two subsets.



Example Input
Input 1:

 A = [1, 6, 11, 5]


Example Output
Output 1:

 1


Example Explanation
Explanation 1:

 Subset1 = {1, 5, 6}, sum of Subset1 = 12
 Subset2 = {11}, sum of Subset2 = 11

*/

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int sum = 0;
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        mini = min(A[i],mini);
        sum = sum + A[i];
    }
    
    bool** dp = new bool*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] =  new bool[sum+1];
        for(int j=0;j<=sum;j++){
            dp[i][j] = false;
        }
    }
    
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j >= A[i-1]){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    //one of the subset is always <= sum/2  (consider s1 <= sum/2)  and s2 = sum-s1;
    int ans = INT_MAX;
    int index ;
    for(int j=0;j<=sum;j++){
        if(dp[n][j]){
            int s1 = j;
            int s2 = sum - s1;
            if(abs(s1-s2) <= ans){
                ans = abs(s1-s2);
                index = s1;
            }
            
        }
    }
    
    return ans;
}
