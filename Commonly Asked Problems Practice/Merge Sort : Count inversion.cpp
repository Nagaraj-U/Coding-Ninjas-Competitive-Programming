/*
In an array, , the elements at indices  and  (where ) form an inversion if . In other words, inverted elements  and  are considered to be "out of order". 
To correct an inversion, we can swap adjacent elements.

Example


To sort the array, we must perform the following two swaps to correct the inversions:

The sort has two inversions:  and .
Given an array , return the number of inversions to sort the array.

Function Description

Complete the function countInversions in the editor below.

countInversions has the following parameter(s):

int arr[n]: an array of integers to sort
Returns

int: the number of inversions
Input Format

The first line contains an integer, , the number of datasets.

Each of the next  pairs of lines is as follows:

The first line contains an integer, , the number of elements in .
The second line contains  space-separated integers, .
Constraints

Sample Input

STDIN       Function
-----       --------
2           d = 2
5           arr[] size n = 5 for the first dataset
1 1 1 2 2   arr = [1, 1, 1, 2, 2]
5           arr[] size n = 5 for the second dataset     
2 1 3 1 2   arr = [2, 1, 3, 1, 2]
Sample Output

0  
4   
*/

#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

ll merge(vector<int> &arr,int &start,int &mid,int &end){
    vector<int> temp(end-start+1);

    int i = start;
    int j = mid+1;
    ll count = 0;
    int index = 0;
    while(i <= mid and j <= end){
        if(arr[i] <= arr[j]){
            temp[index++] = arr[i++];
        }else{
            count += (mid-i+1);//every number after "i" makes inversion pair with arr[j] , since elements after arr[i] greater than or equal to arr[i]
            temp[index++] = arr[j++];
        }
    }
    
    while(i <= mid){
        temp[index++] = arr[i++];
    }
    while(j <= end){
        temp[index++] = arr[j++];
    }
    int k = start;
    for(int i=0;i<temp.size();i++){
        arr[k++] = temp[i];
    }
    return count;
}

ll mergesort(vector<int> &arr,int start,int end){
    if(start >= end){
        return 0;
    }
    
    int mid = (start+end)/2;
    return mergesort(arr,start,mid) + mergesort(arr,mid+1,end) + merge(arr,start,mid,end);
}

long countInversions(vector<int> &arr) {
    return mergesort(arr,0,arr.size()-1);
}
