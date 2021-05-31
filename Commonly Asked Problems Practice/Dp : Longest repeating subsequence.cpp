


/*
Given a string, find the length of the longest repeating subsequence such that the two subsequences don’t have same 
string character at the same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the
 original string.

 example : aabebcdd 
 longest repeating subsequence is "abd"

 contraint : every character in original string can be used atmost one time in two subsequence

 s1 = aabebcdd
 s2 = aabebcdd


 example 2 : abccab
 ans : ab
*/

#include<bits/stdc++.h>
using namespace std;


string getLRS(string s)
{
	int n = s.length();
	string** dp = new string*[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = new string[n+1];
		for(int j=0;j<=n;j++){
			dp[i][j] = "";
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i-1] == s[j-1] && i != j){ //using same characters in two subsequence is not allowed
				dp[i][j] = dp[i-1][j-1] + s[i-1];  
			}else{
				dp[i][j] = dp[i-1][j].length() > dp[i][j-1].length() ? dp[i-1][j] : dp[i][j-1];
			}
		}
	}

	return dp[n][n];
}

int main()
{
	string s;
	cin >> s;
	string str = getLRS(s);
	cout << str << endl;
}
