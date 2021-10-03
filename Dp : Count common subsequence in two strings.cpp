
/*
To find the number of common subsequences in two string, say S and T,
 we use Dynamic Programming by defining a 2D array dp[][],
  where dp[i][j] is the number of common subsequences in the string S[0…i-1] and T[0….j-1]. 

Now, we can define dp[i][j] as 
= dp[i][j-1] + dp[i-1][j] + 1, when S[i-1] is equal to T[j-1] 
This is because when S[i-1] == S[j-1], using the above fact all the previous 
common sub-sequences are doubled as they get appended by one more character.
 Both dp[i][j-1] and dp[i-1][j] contain dp[i-1][j-1] and
  hence it gets added two times in our recurrence which takes care of
   doubling of count of all previous common sub-sequences.
    Addition of 1 in recurrence is for the latest character match : 
    common sub-sequence made up of s1[i-1] and s2[j-1]
= dp[i-1][j] + dp[i][j-1] – dp[i-1][j-1], when S[i-1] is not equal to T[j-1] 
Here we subtract dp[i-1][j-1] once because it is present in both dp[i][j – 1] and dp[i – 1][j]
 and gets added twice.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str1,str2;
    cin >> str1 >> str2;
    vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1,0));


    //dp[i-1][j] contains dp[i-1][j-1] and dp[i][j-1] also contains dp[i-1][j-1]
    for(int i=1;i<=str1.length();i++){
        for(int j=1;j<=str2.length();j++){
            if(str1[i-1] == str2[j-1]){  //all prev counts are doubled (dont explicity double dp[i-1][j-1] as they are included in dp[i-1][j] and dp[i][j-1])
                dp[i][j] = 1 + dp[i-1][j] + dp[i][j-1]; // 1 + 2*dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - 2*dp[i-1][j-1]
            }else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];//dp[i-1][j-1] added two times , hence subtracting
            }
        }
    }
    cout <<  dp[str1.length()][str2.length()];
    return 0;
}
