/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color. 
Since answer can be large return it modulo 10^9 + 7.
*/

class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        if(n==1){
            return k;
        }
        //same[i] : number of ways can be painted such that last two fences are of same color
        //diff[i] :number of ways can be painted such that last two fences are of different color
        vector<long long> same(n+1,0);
        vector<long long> diff(n+1,0);
        const int mod = 1e9+7;
        same[2] = k;
        diff[2] = k*(k-1);
        for(int i=3;i<=n;i++){
            same[i] = diff[i-1]%mod;//all prev different colors , we cant add prev n-1 same colors (given : at most 2 of same color)
            diff[i] = ( (diff[i-1] % mod + same[i-1] % mod) * (k-1) )%mod;//we can take all prev same and diff ways and add them with diff color ie (k-1)
            
        }
        return (same[n]%mod + diff[n]%mod)%mod;
        
    }
};

/*
n = 3 , k=2 (lets say red , blue)
n = 1 , same = k ways = 2 (r,b) , diff = 0
n = 2 , same = (rr,bb) = 2 , diff = (rb,br) = 2;
n = 3 , same = (rb,br) * (k-1) = (rbr,brb) = 2  , diff = same + diff = (rr,bb)+(rb,br) = (rrb,bbr,rbr,brb) = 4
total = 2 + 4 = 6
*/
