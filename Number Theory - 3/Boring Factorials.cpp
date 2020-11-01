/*
Boring Factorials
Send Feedback
Sameer and Arpit want to overcome their fear of Maths and so they have been recently practicing Maths problems a lot. Aman, their friend has been helping them out. But as it goes, Sameer and Arpit have got bored of problems involving factorials. Reason being, the factorials are too easy to calculate in problems as they only require the residue modulo some prime and that is easy to calculate in linear time. So to make things interesting for them, Aman - The Mathemagician, gives them an interesting task. He gives them a prime number P and an integer N close to P, and asks them to find N! modulo P. He asks T such queries.
Input
First line contains an integer T, the number of queries asked.

Next T lines contains T queries of the form “N P”. (quotes for clarity)
Output
Output exactly T lines, containing N! modulo P.
Constraints:
1 <= T <= 1000

1 < P <= 2*10^9

1 <= N <= 2*10^9

Abs(N-P) <= 1000
Sample Input:
3
2 5
5 11
21 71
Sample Output:
2
10
6
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
wilsons theorom:
(p-1)! mod p = -1 or (p-1)  given p is prime

fermats little theorom::
(1/a)%p = (a^(p-2))%p  where 'p' is prime and 'a' is integer (here 1/a = a inverse)
 
 
application : find (n!)%p

1. for n>p  (n!)%p = 0 since 'p' is one of factor

2. for n<p  (n!)%p can be written as

((1*2*3...n)(n+1*n+2*....p-1))%p = -1 (wilson theorom)
(n!)%p = -1 * (n+1)^-1 % p * (n+2)^-1%p * .... * (p-1)^-1 % p   note : (here (n+1)^-1 is (n+1) inverse)

now applying fermats little theorom (1/a)%p = (a^(p-2))%p  where 'p' is prime and 'a' is integer (here 1/a = a inverse)
*/



// overall time complexity is O(1000*1000*log(p))
ll power(ll num,ll p,ll mod){ //this takes log p  time
    if(p == 0){
        return 1;
    }
    if(p == 1){
        return num;
    }
    ll ans = power(num,p/2,mod)%mod;
    ans = ((ans) * (ans))%mod;
    if(p%2 != 0){
        ans = (ans%mod * num%mod)%mod;
    }
    
    return ans;
}

int main() {

	// Write your code here
    int t;
    cin >> t;
    while(t--){ //this can be max 1000
        ll n,p;
        cin >> n >> p;
        if(n>=p){
            cout << 0 << endl;
            continue;
        }else{
            ll ans = -1;
            for(ll i=(n+1);i<=(p-1);i++){ //this is max = 1000 itertaion
                ll res = power(i,p-2,p); 
                res = res%p;
                ans = ((ans%p) * (res%p))%p;
                ans = (ans+p)%p;
            }
            cout << ans << endl;
        }
    }
}
