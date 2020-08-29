
/*
Clear All Bits From LSB
Send Feedback
You are given two integers N and i. You need to clear all bits from LSB to ith bit (start i from right to left) and return the updated N.
Counting of bits starts from 0 from right to left.
Input Format :
Two integers N and i (separated by space)
Output Format :
Updated N
Sample Input 1 :
87 3
Sample Output 1 :
80
*/

/*
approach : 
n = 87 = 0101 0111; i = 3; ans = 0101 0000
sol : a = (1 << i+1) = 00010000
      b = a-1 = 00001111
      c = ~b = 11110000
      ans = n & c = 01010111 & 11110000 = 01010000
*/

#include<iostream>
using namespace std;

int main(){
    int n,i;
    cin >> n >> i;
    int a = (1 << i+1);
    int b = a-1;
    int c = ~b;
    int ans = n & c;
    cout << ans << endl;
    return 0;
}
