/*
A and B are playing a game. At the beginning there are n coins. 
Given two more numbers x and y. In each move a player can pick x or y or 1 coins. 
A always starts the game. The player who picks the last coin wins the game or 
the person who is not able to pick any coin loses the game. For a given value of n,
find whether A will win the game or not if both are playing optimally.

Input :  n = 5, x = 3, y = 4
Output : A
There are 5 coins, every player can pick 1 or
3 or 4 coins on his/her turn.
A can win by picking 3 coins in first chance.
Now 2 coins will be left so B will pick one 
coin and now A can win by picking the last coin.

Input : 2 3 4
Output : B
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x,y;
    cin >> n >> x >> y;

    vector<bool> dp(n+1,false);

    dp[0] = false;//given that if player didnt collect any point , he is loser
    dp[1] = true;//player A can always make 1 move

    //dp[i] : wether player can win till 'i'

    //if player A lose at any of the dp[i-1] or dp[i-x] or dp[i-y] then definetely he wins at i
    //since both are playing optimally "B" would have chosen that move in which dp[i-1] or dp[i-x] or dp[i-y] is false
    
    for(int i=2;i<=n;i++){
        if(i-1 >= 0 and !dp[i-1]){
            dp[i] = true;
        }else if(i-x >=0 and !dp[i-x]){
            dp[i-x] = true;
        }else if(i-y >=0 and !dp[i-y]){
            dp[i-y] = true;
        }
    }

    cout << "winner " << endl;
    if(dp[n]){
        cout << "A";
    }else{
        cout << "B";
    }
    return 0;
}


