/*
Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, -6) print "-6 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. 
You can print pairs in any order, just be careful about the order of elements in a pair.
Input format :
Line 1 : Integer N (Array size)
Line 2 : Array elements (separated by space)
Output format :

Line 1 : Pair 1 elements (separated by space)
Line 2 : Pair 2 elements (separated by space)
Line 3 : and so on
Constraints :
0 <= N <= 10^4
Sample Input:
5
2 1 -2 2 3
Sample Output :
-2 2
-2 2
*/



#include <bits/stdc++.h>
using namespace std;
#include "solution.h"


#include<algorithm>
void pairSum(int *input, int n) 
{
    //Write your code here
    sort(input,input+n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(input[i] + input[j] == 0){
                cout << input[i] << " " << input[j] << endl;
            }
        }
    }
    return;
}


int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	pairSum(arr, n);

	delete[] arr;

	return 0;
}
