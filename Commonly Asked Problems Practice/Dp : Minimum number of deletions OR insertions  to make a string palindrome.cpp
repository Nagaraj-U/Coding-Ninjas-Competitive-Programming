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

//NUMBER OF INSERTIONS TO MAKE STRING PALINDROME = NUMBER OF DELETIONS TO MAKE STRING PALINDROME

//SPACE O(N) TIME O(N^2)

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        
        int** dp = new int*[2]();
        for(int i=0;i<2;i++){
            dp[i] = new int[n+1]();
        }
        string t = s;
        reverse(t.begin(),t.end());
        int curr = 0;
        for(int i=1;i<=n;i++){
            curr = curr ^ 1;//toggle rows (at a time we need only 2 rows)
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1]){
                    dp[curr][j] = 1 + dp[curr ^ 1][j-1];
                }else{
                    dp[curr][j] = max(dp[curr][j-1],dp[curr^1][j]);
                }
            }
        }
        return (n - dp[curr][n]);
    }
};

//SPACE O(N^2) TIME O(N^2)

/*
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int** dp = new int*[n+1]();
        for(int i=0;i<=n;i++){
            dp[i] = new int[n+1]();
        }
        
        int
        string t = s;
        reverse(t.begin(),t.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return (n-dp[n][n]);
    }
};
*/
