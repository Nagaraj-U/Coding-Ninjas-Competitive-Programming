//count number subsets S1 and S2 with given given difference "d"
//similar as number of subsets with given sum = sum - diff 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int diff;
	cin >> diff;
	int* arr = new int[n];
	int sum =0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		sum = sum + arr[i];
	}

	sum = sum - diff;

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
