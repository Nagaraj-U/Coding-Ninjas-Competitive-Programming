/*
Given:
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

int main(){
    int a,b;
    cout << "enter two numbers" << endl;
    cin >> a >> b;
    Triplet ans = extendedEuclid(a,b);
    cout << "x = " << ans.x << " y = " << ans.y << " Gcd is " << ans.gcd <<  endl; 
    return 0;
}
