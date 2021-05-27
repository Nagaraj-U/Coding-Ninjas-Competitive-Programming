
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
