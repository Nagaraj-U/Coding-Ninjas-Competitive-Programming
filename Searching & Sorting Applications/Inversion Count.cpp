/*
For a given integer array/list of size N, find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
A pair (arr[i], arr[j]) is said to be an inversion when,
1. arr[i] > arr[j] 
2. i < j

Where 'arr' is the input array/list, 'i' and 'j' denote the indices ranging from [0, N).
Input format :
The first line of input contains an integer N, denoting the size of the array.

The second line of input contains N integers separated by a single space, denoting the elements of the array.
Output format :
The only line of output prints the total count of inversions in the array.
Note:
You are not required to print anything. Return the total number of inversion count.
Constraints :
1 <= N <= 10^5 
1 <= arr[i] <= 10^9

Time Limit: 1sec
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Explanation of Sample Input 1:
We have a total of three pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
Sample Input 2 :
5
2 5 1 3 4
Sample Output 2 :
4
*/


#include <iostream>
using namespace std;

#include "solution.h"

long long merge(long long arr[],int left,int mid,int right){
    long long temp[right-left+1];
    int i = left;
    int j=mid;
    int k = 0;
    long long count = 0;
    while(i < mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
			count += mid - i;
            temp[k++] = arr[j++];
        }
    }
    while(i<mid){
        temp[k++] = arr[i++];
    }
    while(j<=right){
        temp[k++] = arr[j++];
    }
    for(int i=left,k=0;i<=right;i++,k++){
        arr[i] = temp[k];
    }
    return count;
 
}

long long merge_sort(long long  arr[],int left,int right){
    long long count = 0;
    if(right > left){
        int mid = (left+right)/2;
        long long leftCount = merge_sort(arr,left,mid);
        long long rightCount = merge_sort(arr,mid+1,right);
        long long mergeCount = merge(arr,left,mid+1,right); 
        return leftCount + rightCount + mergeCount;
    }
    
    return count;
}

long long getInversions(long long *arr, int n)
{
    //Write your code here
    long long ans = merge_sort(arr,0,n-1);
    return ans;
}

int main()
{
    int n;
    cin >> n;

    long long* arr = new long long[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << getInversions(arr, n);

    delete arr;
}
