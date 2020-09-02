/*
Count BSTs
Send Feedback
Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Input Format :
Integer n 
Output Format :
Count of BSTs
Contraints :
1<= N <=1000
Sample Input 1:
8
Sample Output 1:
1430
Sample Input 2:
3
Sample Output 2:
5
*/



#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#include "solution.h"

int countBST(int n,int* temp = new int[1001]())
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(n == 0){
        return 1;
    }
    if(n == 1){
         return 1;
    }
           
    if(temp[n] > 0){
        return temp[n];
    }
    int mod = 1000000000+7;
    long long ans = 0;
    for(int i=1;i<=n;i++){
        long long left = countBST(i-1,temp)%mod;
        temp[i-1] = left;
        long long right = countBST(n-i,temp)%mod;
        temp[n-i] = right;
        ans += (left*right)%mod;
    }
    ans = ans%mod;
    temp[n] = ans;
    return ans;

}





int main()
{
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}
