#include<iostream>
using namespace std;


/*
Recursive solution: 

to find power of a^b
Given a,b,c find a^b and take %c to ans to get integer answer
if: b is even we find a^(b/2)*a^(b/2) example: 2^6 = 2^3*2^3
if: b is odd we find a^(b/2) * a^(b/2) * a example: 2^7 = 2^3 * 2^3 * 2

Iterative solution:

represent 'b' in binary form
to find (3^45) -> b=45 -> 101101 -> 3^(2^5) * 3^(2^3) * 3^(2^2) * 3^(2^0) -> 3^32 * 3^8 * 3^4 * 3^1 = 3^40

time complexity by modular exponentiation : O(log(n)) 

note: 

int*int = int
int*long = long
(a*b)%c = ((a%c)*(b%c))%c
(a+c)%c to make ans positive


*/


//recursive solution
int modularExpo(int a,int b,int c){
    if(a == 0){
        return 0;
    }

    if(b == 0){
        return 1;
    }
    long ans; //since int*int may cross int range so we store it in long
    if((b%2)==0){
        long smallAns = modularExpo(a,b/2,c); //though ans is in int we store it in long
        ans = (smallAns * smallAns)%c;  
    }else{
        long smallAns = modularExpo(a,b-1,c);
        ans = (a%c); //since 'a' may larger than c
        ans = (ans * smallAns)%c;
    }

    return int((ans + c)%c); //avoid negative values by adding 'c' since we got ans in range of 'c' by adding 'c' to and makes ans positive
}

int modularExpo1(int a,int b,int c){
    long ans = 1;
    long temp = a;
    while(b != 0){
        if((1&b) == 1){
            ans = (ans*temp);
        }
        temp = (temp*temp)%c;//wether we multiply it to ans or not keep temp multiplying at each step
        b = (b>>1);//right shift 
    }
    return (int)((ans+c)%c);
}

int main(){
    int a,b,c;
    cout << "Enter a,b,c " << endl;
    cin >> a >> b >> c;
    cout << " recursive : " << modularExpo(a,b,c) << endl;
    cout << "iterative  :  " << modularExpo1(a,b,c) << endl;
    return 0;
}
