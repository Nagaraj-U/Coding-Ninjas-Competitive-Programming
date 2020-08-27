/*
You are given an integer Ni. You need to make first set bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.
Input Format :
Integer N 
Output Format :
Updated N
Sample Input 1 :
4
Sample Output 1 :
0
Sample Input 2 :
12 
Sample Output 2 :
8
*/

#include <iostream>
using namespace std;

#include<bits/stdc++.h>
int turnOffFirstSetBit(int n){
   
    if(n == 0){
        return 0;
    }
     if((n & n-1) == 0){
               return 0;
        }	
    int i=0;
    while(1){
         
     if((n & (1 << i)) == 0){
        i++;           
        }else{
            int z;
            z = n^(1 << i);
            return z;
         
       }
    }
    // int i=0;
    // while((n & (1<<i)) == 0){
    //     i++;
    // }
    // return n^(1<<i);
}



int main() {
	int n;

	cin >> n;
	
	cout<< turnOffFirstSetBit(n) <<endl;
		
	return 0;
}

