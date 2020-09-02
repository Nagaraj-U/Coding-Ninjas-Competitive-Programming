
/*
amantha and Sam are playing a numbers game. Given a number as a string, no leading zeros, determine the sum of all integer values of substrings of the string. For example, if the string is , the substrings are  and . Their sum is .

Given an integer as a string, sum all of its substrings cast as integers. As the number may become large, return the value modulo 10^9+7 .

Function Description

Complete the substrings function in the editor below. It should return the sum of the integer values of all substrings in a string representation of a number, modulo .

substrings has the following parameter(s):

n: the string representation of an integer
Input Format

A single line containing an integer as a string without leading zeros.

Output Format

A single line which is sum of the substrings, 

Sample Input 0

16
Sample Output 0

23
Explanation 0

The substring of number 16 are 16, 1 and 6 which sums to 23.

Sample Input 1

123
Sample Output 1

164
Explanation 1

The sub-strings of 123 are 1, 2, 3, 12, 23, 123 which sums to 164.
*/

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


int main(){
    string s;
    cin >> s;
    long long currentSum = s[0] - '0';
    long long totalSum = currentSum;
    for(int i=1;i<s.length();i++){
        currentSum = currentSum*10 + (s[i] - '0')*(i+1);
        currentSum = currentSum % MOD;
        totalSum = totalSum + currentSum;
        totalSum = totalSum % MOD;
    }
    cout << totalSum << endl;
}














