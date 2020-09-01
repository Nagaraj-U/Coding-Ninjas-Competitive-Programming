/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up 
to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :
Integer n (No. of steps)
Constraints :
n <= 70
Sample Input 1:
4
Sample Output 1:
7
*/


#include <iostream>
using namespace std;


long getCount(int n,long* arr){
    if(n == 0 || n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    if(arr[n] > 0){
        return arr[n];
    }
    
  
    long ans1 =  getCount(n-1,arr);
    long ans2 =  getCount(n-2,arr);
    long ans3 =  getCount(n-3,arr);
    arr[n-1] = ans1;
    arr[n-2] = ans2;
    arr[n-3] = ans3;
    long ans = ans1 + ans2 + ans3;
    arr[n] = ans;
    return ans;
}

long staircase(int n)
{
	//Write your code here
    long* arr = new long[n+1]();
    
    return getCount(n,arr);
    
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}
