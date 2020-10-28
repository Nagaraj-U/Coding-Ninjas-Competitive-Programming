/*
Segmented Sieve Problem
Send Feedback
In this problem you have to print all primes from given interval.
Input
t - the number of test cases, then t lines follows. [t <= 150]
On each line are written two integers L and U separated by a blank. L - lower bound of 
interval, U - upper bound of interval. [2 <= L < U <= 2147483647] [U-L <= 1000000].
Output
For each test case output must contain all primes from interval [L; U] in increasing order.
Sample Input:
2
2 10
3 7
Sample Output:
2
3
5
7
3
5
7 
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001 //since 'r' ranges 10^10 we find primes from 2 to 10^5

/*
we cant make array of size > 10^8 
as 'r' ranges to 10^10
we make array of size (r-l+1)
we find all prime number from 2 to sqrt(r)
next from given 'l' to 'r' we find mark all multiples of theese prime numbers as false so we get required primes from 'l' to 'r'
*/

vector<int>* makesieve(){
    bool isPrime[MAX];
    for(int i=0;i<MAX;i++){
        isPrime[i] = true;
    }
    
    vector<int>* primes = new vector<int>(); 
    for(int i=2;i*i<MAX;i++){
        if(isPrime[i]){
            for(int j=i*i;j<MAX;j+=i){
                isPrime[j] = false;
            }
        }
    }
    
    primes->push_back(2);
    for(int i=3;i<MAX;i+=2){
        if(isPrime[i]){
            primes->push_back(i);
        }
    }
    
    return primes;//prime nurbers from 2 to sqrt(r) 
} 

void printPrimes(ll l,ll r,vector<int>* &primes){
    
    bool isPrime[r-l+1];//which can go upto 10^6
    for(int i=0;i<=r-l;i++){
        isPrime[i] = true; //making sieve
    }
    
    for(int i=0;(primes->at(i)*(ll)primes->at(i))<=r;i++){ //iterating upto sqrt(r) ie primes[i]*primes[i] <= r
        int currPrime = primes->at(i);
        ll base = (l/(currPrime))*(currPrime);//getting to nearest left value example: if l=26 and currPrime=5 we get base = (26/5)*5 = 25
        if(base<l){
            base = base + currPrime;  //25+5=30 (make 30 onwards as false)
        }
        for(ll j=base;j<=r;j+=currPrime){
            isPrime[j-l] = false;
        }
        
        
        //case when base itself is prime
        if(base == currPrime){
            isPrime[base-l] = true; //example: l=2 currPrime=3 base=(2/3)*3 = 0 -> 0+3 = 3 -> prime[3] = false(which is wrong) so avoiding this case
        }    
    }
    for(int i=0;i<=r-l;i++){
        if(isPrime[i]){
            cout << i+l << endl;
        }
    }
    return;
}

int main()
{
	// Write your code here
    vector<int>* primes = makesieve();
    int t;
    cin >> t;
    while(t--){
        ll l,r;
        cin >> l >> r;
        printPrimes(l,r,primes);
    }
	return 0;
}
