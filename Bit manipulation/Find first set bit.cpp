/*
You are given an integer N. You need to return an integer M, in which only one bit is set which at position of lowest set bit of N (from right to left).
Input Format :
Integer N
Output Format :
Integer M
Sample Input 1 :
7
Sample Output 1 :
1
Sample Input 2 :
12
Sample Output 2 :
4
*/

#include <iostream>
using namespace std;

#include<bits/stdc++.h>
int returnFirstSetBit(int n){
    int i=0;
    if(n == 0){
        return 0;
    }
    while(1){
        if((n & (1 << i)) == 0 ){
            i++;
        }else{
            return pow(2,i);
        }
    }  
}



int main() {
	int n;

	cin >> n;
	
	cout<< returnFirstSetBit(n) <<endl;
		
	return 0;
}

