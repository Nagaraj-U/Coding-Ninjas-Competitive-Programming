/*
Given a string of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. 

Note: The order of characters should be maintained. 

Examples : 

Input : aebcbda
Output : 2
Remove characters 'e' and 'd'
Resultant string will be 'abcba'
which is a palindromic string

Input : geeksforgeeks
Output : 8
*/


//find longest palindromic subsequence of string , then subtract it from total length

int minDeletions(string s) {
  
  
        //finding LPS
        int n = s.length();
        string t = s;
        reverse(s.begin(),s.end());
        int** dp = new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = new int[n+1];
        }
        
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i=0;i<=n;i++){
            dp[0][i] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        
        return (n - dp[n][n]);

}
