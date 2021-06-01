/*
5
10 5 20 30 5
60
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}

	int* dp = new int[n];
	for(int i=0;i<n;i++){
		dp[i] = arr[i];
	}


	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0;j--){
			if(arr[j] < arr[i]){
				dp[i] = max(dp[i] , dp[j]+arr[i]);
			}
		}
	}

	int maxi = -1;
	for(int i=0;i<n;i++){
		maxi = max(maxi,dp[i]);
	}

	cout << maxi << endl;
	return 0;
}
