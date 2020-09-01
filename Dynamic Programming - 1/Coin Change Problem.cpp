/*
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make
change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
*/


#include<iostream>
using namespace std;
int getCount(int* arr,int n,int value,int** temp){
    if(value == 0){
        return 1;
    }
    if(n == 0){
        return 0;
    }
    if(value < 0){
        return 0;
    }
    if(temp[n][value] > -1){
        return temp[n][value];
    }
    int first = getCount(arr,n,value-arr[0],temp);
    int second = getCount(arr+1,n-1,value,temp);
    temp[n][value] = first+second;
    return first+second;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int** temp = new int*[11];
    for(int i=0;i<11;i++){
        temp[i] = new int[1001];
    }
    for(int i=0;i<11;i++){
        for(int j=0;j<1001;j++){
            temp[i][j] = -1;
        }
    }
	return getCount(denominations,numDenominations,value,temp);

}



int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}


