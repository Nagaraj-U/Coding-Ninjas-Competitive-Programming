/*
LCS - Problem
Send Feedback
Given two strings S1 and S2 with lengths M and N respectively, find the length of the longest common subsequence.
A subsequence of a string S whose length is K, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous.
Subsequences contain all the strings of length varying from 0 to K. For example, subsequences of string "abc" are -- ""(empty string), a, b, c, ab, bc, ac, abc.
Input Format :
Line 1: String S1
Line 2: String s2
Output Format :
Length of the longest common subsequence.
Constraints :
1 <= M <= 100
1 <= N <= 100

Time Limit: 1 sec
Sample Input 1:
adebc
dcadb
Sample Output 1:
3
Explanation of Sample Input 1:
"a", "d", "b", "c", "ad", "ab", "db", "dc" and "adb" are present as a subsequence in both the strings in which "adb" has the maximum length. There are no other common 
subsequence of length greater than 3 and hence the answer.
Sample Input 2:
abcd
acbdef
Sample Output 2:
3
Explanation of Sample Input 2:
"a", "b", "c", "d", "ab", "ac", "ad", "bd", "cd", "abd" and "acd" are present as a subsequence in both the strings S1 and S2 in which "abd" and "acd" are of the maximum length.
There are no other common subsequence of length greater than 3 and hence the answer.
*/



#include <iostream>
#include <string>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
int LCS(char* s1,char* s2,int m,int n,int** dp){  
    if(m == 0 || n == 0){
        return 0;
    }
    if(dp[m][n] > -1){
        return dp[m][n];
    }
    int ans;
    if(s1[0] == s2[0]){
        ans =  1 + LCS(s1+1,s2+1,m-1,n-1,dp);  //if you used string instead of char array do (s+1) as (s.substr(1))
    }else{
        int option1 = LCS(s1,s2+1,m,n-1,dp);
        int option2 = LCS(s1+1,s2,m-1,n,dp);
        ans = max(option1,option2);
    }
    dp[m][n] = ans;
    return ans;
}

int lcs(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    char* arr1 = new char[m];
    char* arr2 = new char[n];
    for(int i=0;i<m;i++){
        arr1[i] = s1[i];
    }
    for(int i=0;i<n;i++){
        arr2[i] = s2[i];
    }
    
    int** dp = new int*[m+1];
    for(int i=0;i<m+1;i++){
        dp[i] = new int[n+1];
        for(int j=0;j<n+1;j++){
            dp[i][j] = -1;
        }
    }
    
    int ans = LCS(arr1,arr2,m,n,dp);
   
    return ans;
    
    
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2);
}









