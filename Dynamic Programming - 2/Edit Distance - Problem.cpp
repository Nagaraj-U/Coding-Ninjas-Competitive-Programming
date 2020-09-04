/*
Edit Distance - Problem
Send Feedback
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make
one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 20
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/



#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

int helper(char* s1,char* s2,int m,int n,int** dp){
    if(m == 0){
        return n;
    } 
    
    if(n == 0){
        return m;
    }
    
    if(m == 0 || n == 0){
        return 0;
    }
    
    if(dp[m][n] > -1){
        return dp[m][n];
    }
    
    int ans = 0;
    //NOTE : here we editing string s1 to get s2 (all changes are only to s1)
    if(s1[0] == s2[0]){
        ans = helper(s1+1, s2+1, m-1, n-1, dp);
    }else{
        int replace = 1 + helper(s1+1, s2+1, m-1, n-1, dp);
        int del = 1 + helper(s1+1, s2, m-1, n, dp);
        int insert = 1 + helper(s1, s2+1, m, n-1, dp);
        ans = min(replace, min(del, insert));
    }
    
    dp[m][n] = ans;
    return ans;
    
}


int editDistance(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    
    char* arr1 = new char[m];
    char* arr2 = new char[n];
    
    for(int i=0;i<m;i++){
        arr1[i] = s1[i];
    }
    
    for(int j=0;j<n;j++){
        arr2[j] = s2[j];
    }
    
    
    int** dp = new int*[m+1];
    
    for(int i=0;i<=m;i++){
        dp[i] = new int[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j] = -1;
        }
    }
    
    int ans = helper(arr1,arr2,m,n,dp);
    return ans;
}



// int editDistance(string s1, string s2){
//     if(s1.length() == 0){
//         return s2.length();
//     }
//     if(s2.length() == 0){
//         return s1.length();
//     }
//     if(s1.length() == 0 && s2.length() == 0){
//         return 0;
//     }
//     int ans = 0;
//     if(s1[0] == s2[0]){
//         ans = editDistance(s1.substr(1),s2.substr(1));
//     }else{
//         int replace = 1+editDistance(s1.substr(1),s2.substr(1));
//         int del = 1+editDistance(s1.substr(1),s2);
//         int insert = 1+editDistance(s1,s2.substr(1));
//         ans = min(replace,min(del,insert));
//     }
//     return ans;
    
// }

int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}


