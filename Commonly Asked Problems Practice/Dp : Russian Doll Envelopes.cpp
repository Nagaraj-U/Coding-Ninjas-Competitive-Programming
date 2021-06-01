/*

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

 

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
 

Constraints:

1 <= envelopes.length <= 5000
envelopes[i].length == 2
1 <= wi, hi <= 104

*/


/*
sort on basis of first element
then find longest increasing subsequence based on second element

note : while sorting if you find same first values , then sort on basis on second element which has greater value

example : (2,3) , (5,4) , (6,4),(6,7) (default sort) actual ans = 3 , got answer = 4 
(2,3) , (5,4) , (6,7) , (6,4)   : answer = LIS = 3

*/

bool compare(vector<int> v1,vector<int> v2)
{
    if(v1[0] == v2[0]){
        return v1[1] > v2[1];
    }

    return v1[0] < v2[0];
}

class Solution {
public:

    int maxEnvelopes(vector<vector<int>>& v) {
        int n = v.size();
        sort(v.begin(),v.end(),compare);
        int* dp = new int[n+1]();
        for(int i=0;i<n;i++){
            dp[i] = 1;
        }
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(v[j][1] < v[i][1]){
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }
        
        int maxi = -1;
        for(int i=0;i<n;i++){
            maxi = max(maxi,dp[i]);
        }
        
        return maxi;
    }
};
