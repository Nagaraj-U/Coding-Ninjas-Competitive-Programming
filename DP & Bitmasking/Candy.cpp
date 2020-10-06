/*
Candy
Send Feedback
Gary is a teacher at XYZ school. To reward his N students he bought a packet of N candies all with different flavours. But the problem is some students like certain flavour while some doesn't. Now Gary wants to know the number of ways he can distribute these N candies to his N students such that every student gets exactly one candy he likes.
Input Format :
Line 1 : An integer N (1<= N <= 16) denoting number of students and candies.
Next N lines : N integers describing the preferences of one student. 1 at i'th (0 <= i < N) position denotes that this student likes i'th candy , 0 means he doesn't.
Assume input to be 0-indexed based.
Output Format :
Return the number of ways Gary can distribute these N candies to his N students such that every student gets exactly one candy he likes.``
Sample Input:
3
1 1 1
1 1 1
1 1 1
Sample Output:
6
*/



#include<bits/stdc++.h>
using namespace std;
#define MAXN 16

long long solve(int like[][MAXN],int n)
{
	// Write your code here.
    int* dp = new int[1<<n];
    for(int i=0;i<(1<<n);i++){
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int mask=0;mask<((1<<n)-1);mask++){
        int temp = mask;
        int count = 0;
        while(temp > 0){
            count += (temp&1);
            temp = (temp >> 1);
        }
        
        for(int j=0;j<n;j++){
            if(!(mask&(1<<j))){
                if(like[count][j] == 1){  //count th person has to like
                    dp[mask|(1<<j)] += dp[mask];
                }
            }
        }
    }
    return dp[(1<<n)-1];
}


int main()
{
	int n,like[MAXN][MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++){
			cin>>like[i][j];
		}
	}
	cout<<solve(like,n)<<endl;
}
