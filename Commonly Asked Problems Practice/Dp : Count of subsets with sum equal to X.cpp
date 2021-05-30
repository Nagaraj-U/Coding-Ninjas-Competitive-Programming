/*
Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X.

Examples: 

Input: arr[] = {1, 2, 3, 3}, X = 6 
Output: 3 
All the possible subsets are {1, 2, 3}, 
{1, 2, 3} and {3, 3}
 

Input: arr[] = {1, 1, 1, 1}, X = 1 
Output: 4 
*/


//count all subsets with given sum
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int sum;
	cin >> sum;
	int* arr = new int[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}

	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = new int[sum+1];
		for(int j=0;j<=sum;j++){
			dp[i][j] = 0;
		}
	}

	for(int i=0;i<=n;i++){
		dp[i][0] = 1;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j >= arr[i-1]){
				dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}


	cout << dp[n][sum] << endl;
}
