/*
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format
Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house
Output Format
 Line 1 : Maximum amount of money looted
Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4
Sample Input :
6
5 5 10 100 10 5
Sample Output 1 :
110
*/


#include <iostream>
using namespace std;

#include<bits/stdc++.h>

// int getMaxMoney(int arr[], int n){

// 	/*Write your code here.
// 	 *Don’t write main(). 
// 	 *Don’t take input, it is passed as function argument.
// 	 *Don’t print output.
// 	 *Taking input and printing output is handled automatically.
//     */ 
//     long* output = new long[n];
//     output[0] = arr[0];
//     output[1] = (max((long)arr[0],output[1])); 
//     for(int i=2;i<n;i++){
//         output[i] = (max(output[i-1],(long)arr[i]+output[i-2]));
//     }
//     long ans = output[n-1];
// 	return ans;

// }


int getMaxMoney(int* arr,int n,int i = 0,int* temp = new int[10001]()){
    if(i >= n){
        return 0;
    }
    if(temp[i] > 0){
        return temp[i];
    }
    int include = arr[i]+getMaxMoney(arr,n,i+2,temp);
    int not_include = getMaxMoney(arr,n,i+1,temp);
    int maximum = max(include,not_include);
    temp[i] = maximum;
    return maximum;
}


int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);
}

