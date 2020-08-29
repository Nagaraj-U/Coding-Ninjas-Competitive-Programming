/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 40
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/

#include <iostream>
using namespace std;
#include <cmath>

#include<bits/stdc++.h>
// #define mod 1000000007
int balancedBTs(int h) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return the output and don’t print it.
  */
    if( h == 0 || h == 1){
        return 1;
    }
    int mod = pow(10,9) + 7;
    long x = balancedBTs(h-1);
    long y  = balancedBTs(h-2);
    long long ans1 = (long long)(x*x);
    long long ans2 = (long long)(2*x*y);
    int res1 = (int)(ans1%mod);
    int res2 = (int)(ans2%mod);
    int res = (res1+res2)%mod;
    return res;
}


int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}
