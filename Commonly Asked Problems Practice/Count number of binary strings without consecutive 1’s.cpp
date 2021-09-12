
/*
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s.
Eg

Input:  N = 2
Output: 3
// The 3 strings are 00, 01, 10

Input: N = 3
Output: 5
// The 5 strings are 000, 001, 010, 100, 101


APPROACH : 
Let a[i] be the number of binary strings of length i which do not contain any two consecutive 1’s and which end in 0.
Similarly, let b[i] be the number of such strings which end in 1.

Note : We can append either 0 or 1 to a string ending in 0, 
but we can only append 0 to a string ending in 1.

*/
#include <iostream>
using namespace std;

int countStrings(int n)
{
	int* dp1 = new int[n]();
	int* dp2 = new int[n]();
  	dp1[0] = 1; //number of binary strings with length of i which ends with 0 
  	dp2[0] = 1; // number of binary strings of length of i which ends with 1
  	
  	for(int i=1;i<n;i++){
		    dp1[i] = dp1[i-1] + dp2[i-1];  //ends with 0 , hence we have two choices , append with 0 or 1 
      	dp2[i] = dp1[i-1];     //ends with 1 , so only choice is append with 0
    }
  	return dp1[n-1] + dp2[n-1];
}


// Driver program to test above functions
int main()
{
	cout << countStrings(4) << endl;
	return 0;
}
