/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen anywhere from T) results in the string S.)

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
 

Note:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.

*/


/*
worst case 
supersequence = s1 + s2
find common longest subsequence between s1 and s2
and  final add characters to string orderwise (keeping LCS charaters only once in final string and adding all remain charactrs in s1 and s2 )

*/

class Solution {
public:
    
    string getLCS(string s1,string s2,int n1,int n2)
    {
        string** dp = new string*[n1+1];
        for(int i=0;i<=n1;i++){
            dp[i] = new string[n2+1];
            for(int j=0;j<=n2;j++){
                dp[i][j] = "";
            }
        }
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + s1[i-1];
                }else{
                    int temp1 = dp[i-1][j].length();
                    int temp2 = dp[i][j-1].length();
                    if(temp1 > temp2){
                        dp[i][j] = dp[i-1][j];
                    }else{
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        cout << dp[n1][n2] << endl;
        return dp[n1][n2];
        
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        string s = getLCS(str1,str2,n1,n2);
        int n3 = s.length();
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        string ans = "";
        while(p3 != n3){
           while(str1[p1] != s[p3]){
               ans = ans + str1[p1];
               p1++;
           }
            while(str2[p2] != s[p3]){
                ans = ans + str2[p2];
                p2++;
            }
            ans = ans + s[p3];
            p3++;
            p2++;p1++;
        }
        
        while(p1 < n1){
            ans = ans + str1[p1];
            p1++;
        }
        
        while(p2 < n2){
            ans = ans + str2[p2];
            p2++;
        }
        
        return ans;
    }
};

