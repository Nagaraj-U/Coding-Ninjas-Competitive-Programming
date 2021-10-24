/*

Divisors Of Factorial
Send Feedback
Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.
Input
The first line contains T, number of testcases.


T lines follows each containing the number N.
Output
Print T lines of output each containing the answer.
Constraints
1 <= T <= 500

0 <= N <= 50000
Sample Input:
3
2
3
4
Sample Output:
2
4
8
*/

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;


/*
link : https://www.geeksforgeeks.org/count-divisors-of-factorial/

Count Divisors of Factorial
Last Updated: 23-01-2019
Given a number n, count total number of divisors of n!.

Examples:

Input : n = 4
Output: 24
4! is 24. Divisors of 24 are 1, 2, 3, 4, 6,
8, 12 and 24.

Input : n = 5
Output : 16
5! is 120. Divisors of 120 are 1, 2, 3, 4, 
5, 6, 8, 10, 12, 15, 20, 24 30, 40, 60 and 
120

Input : n = 6
Output : 30


A Simple Solution is to first compute factorial of given number, then count number divisors of the factorial. 
This solution is not efficient and may cause overflow due to factorial computation.

A better solution is based on Legendre’s formula . Below are the steps.

1. Find all prime numbers less than or equal to n (input number). We can use Sieve Algorithm for this.
Let n be 6. All prime numbers less than 6 are {2, 3, 5}.

2. For each prime number p find the largest power of it that divides n!. 
We use below Legendre’s formula formula for this purpose.
The value of largest power that divides p is ⌊n/p⌋ + ⌊n/(p2)⌋ + ⌊n/(p3)⌋ + ……
Let these values be exp1, exp2, exp3,.. Using the above formula, we get below values for n = 6.
    The largest power of 2 that divides 6!, exp1 = 4.
    The largest power of 3 that divides 6!, exp2 = 2.
    The largest power of 5 that divides 6!, exp3 = 1.
    
3. The result is (exp1 + 1) * (exp2 + 1) * (exp3 + 1) … for all prime numbers, For n = 6, 
the values exp1, exp2, and exp3 are 4 2 and 1 respectively (computed in above step 2).
So our result is (4 + 1)*(2 + 1) * (1 + 1) = 30
*/

#define MOD 1000000007
#define MAX 50001
typedef long long ll;
using namespace std;
#define pb push_back

vector<int>* sieve(){
    bool isPrimes[MAX];
    for(int i=2;i<=MAX;i++){
        isPrimes[i] = true;
    }
    vector<int>* primes = new vector<int>();
    for(int i=2;i*i<=MAX;i++){
        if(isPrimes[i]){
            for(int j=i*i;j<=MAX;j+=i){
                isPrimes[j] = false;
            }
        }
    }
    
    primes->pb(2);
    for(int i=3;i<=MAX;i+=2){
        if(isPrimes[i]){
            primes->pb(i);
        }
    }
    
    return primes;
}

ll devisors(int n,vector<int>* primes){
    ll result = 1;
    for(int i=0;primes->at(i)<=n;i++){
        ll count = 0;
        int k = primes->at(i);
        while((n/k)!=0){  //legendres formula to get larget power of prime that devides n!
            count = count + (n/k);
            k = k * primes->at(i);
        }
        result = (result * ((count+1)%MOD))%MOD;
    }
    return result;
}

int main(){
	// Write your code here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>* primes = sieve();
        int ans = devisors(n,primes);
        cout << ans << endl;
    }
	return 0;
}
