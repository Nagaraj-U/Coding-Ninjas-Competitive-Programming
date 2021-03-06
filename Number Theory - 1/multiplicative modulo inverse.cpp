/*

Intution: 
There exist integral roots x,y for equation ax+by = c if c = gcd(a,b) 
ie 
gcd(a,b) devides a and b
gcd(a,b) also devides a+b
then gcd(a,b) devides ax+by for some integers x and y
Extended Euclid algorithm
ax+by = gcd(a,b) then find x,y
ax+by = gcd(a,b) = gcd(b,a%b)
then
bx1 + (a%b)y1 = gcd(b,a%b) = gcd(a,b)    rewriting
bx1 + (a - b*floor(a/b))y1 = ax+by
comparing coeff of a and b
b(x1 - floor(a/b)) + ay1 = ax+by
x = y1
y = (x1 - y1*floor(a/b))





Multiplicative modulo inverse : (a*b) mod m = 1
5*b mod 17 = 1 find b
ans = 5*7 mod 17 = 1 hence multiplicative modulo inverse is 7


ie ((a*b) - 1 ) mod m  = 0
a*b - 1 = mq  (multiple of m)
a*b - mq = 1
a*b + m(-q) = 1  ie gcd(a,m) = 1 for m to exist  (a and m should be co-prinme numbers) gcd(a,m) = 1
so apply euclid algo to find ans 
ax+by = gcd(a,b)
here find value of x which is b(multiplicative modulo inverse)



*/


#include<iostream>
using namespace std;


class Triplet{
    public:
        int x;
        int y;
        int gcd;
};

Triplet extendedEuclid(int a,int b){

    if(b == 0){  //ax+by = gcd(a,b) if b=0 then ax = gcd(a,0) = a hence x = 1, y = 0 , gcd = a; 
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    Triplet smallOutput = extendedEuclid(b,a%b);
    Triplet ans;
    ans.gcd = smallOutput.gcd;
    ans.x = smallOutput.y;
    ans.y = smallOutput.x -  smallOutput.y*(a/b);
    return ans;
}

int multiplicativeModuloInverse(int a,int m){
    Triplet ans = extendedEuclid(a,m);
    return ans.x;
}

int main(){
    int a,m;
    cout << "enter values of 'a' and 'm' " << endl; //(a*b)mod m = 1
    cin >> a >> m;
    int ans = multiplicativeModuloInverse(a,m);
    cout << "multiplicative modulo inverse is " << ans; 
    return 0;
}
