/*
You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However,
if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

 

Example 1:

Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
Example 2:

Input: k = 2, n = 6
Output: 3
Example 3:

Input: k = 3, n = 14
Output: 4
 

Constraints:

1 <= k <= 100
1 <= n <= 104
*/


/*
optmize the bad luck
calculate max moves from each of the floors and finally take min from all floors

example lets say you are at stage where 
eggs = 2 , floors = 3  (2,3)
you can drop egg from 1 or 2 or 3rd floor

and whenever you drop from kth floor there are 2 possibilities either egg break o survives

consider 1st floor 
when breaks you have 1 egg , and check for above floors since we know that below floors cannot be answer

therefore 
from 1st floor , 
breaks    ----> (1,0) , check for below 0 floors (egg count reduced)
survives ----> (2,2)  , check for above 2 floors

from 2nd floor
breaks ----> (1,1) below 1 floors
survive ---> (2,1) above 1 floors

from 3rd floor
breaks ---> (1,2) below 2 floors
survives --->(2,0) no above floors left

//choosing max at each floor , because we need answer in worst case(guerenteed answer) , regardless of where 
the floor lies

take min (max(1st break,1st survive) , max(2nd break , 2nd survive) , max(3rd break,3rd survive))
*/

class Solution {
public:
    int superEggDrop(int k, int n) {
        int** dp = new int*[k+1];
        for(int i=0;i<=k;i++){
            dp[i] = new int[n+1];
        }
        
        //rows : eggs (k)
        //cols : floors (n)
        
        //first and second row
        for(int i=0;i<=n;i++){
            dp[0][i] = INT_MAX; //0 eggs ,then not possible(INT_MAX)
            dp[1][i] = i; //1 egg , moves required are same as number of floors(try dropping from each floor)
        }
        
        
        //first col
        for(int i=0;i<=k;i++){ //0 floors , then zero moves required
            dp[i][0] = 0;
        }
        
        //2nd col
        for(int i=2;i<=k;i++){ //1 floor , always 1 move is required
            dp[i][1] = 1;
        }
        
        
        //
        for(int i=2;i<=k;i++){
            for(int j=2;j<=n;j++){
                int start = 0;
                int end = j-1;
                int overall_min = INT_MAX;
                while(start < j and end >= 0){
                    int break_count = dp[i-1][start];
                    int survive_count = dp[i][end];
                    int maxi = max(break_count,survive_count);
                    overall_min = min(overall_min,maxi);
                    
                    start++;
                    end--;
                }
                dp[i][j] = 1+ overall_min;
            }
        }
        
        return dp[k][n];
        
    }
};
