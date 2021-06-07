/*
Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions, i.e.,
arr[i] may be present at arr[i+1] or arr[i-1]. Write an efficient function to search an element in this array. 
Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1].

For example consider the array {2, 3, 10, 4, 40}, 4 is moved to next position and 10 is moved to previous position.

Example :

Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
Output: 2 
Output is index of 40 in given array

Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 90
Output: -1
-1 is returned to indicate element is not present

*/

#include<bits/stdc++.h>
using namespace std;

void binary_search(int* arr,int start,int end,int key,int n)
{
    int idx = -1;
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] == key){
            idx = mid;
            break;
        }else if(mid+1 < n && arr[mid+1] == key){
            idx = mid+1;
            break;
        }else if(mid-1 > 0 && arr[mid-1] == key){
            idx = mid-1;
            break;
        }else if(key <= arr[mid]){
            end = mid-2;
        }else{
            start = mid+2;
        }
    }

    if(idx == -1){
        cout << "not found" << endl;
    }else{
        cout << "present at index " << idx << endl;
    }


}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int key;
    cout << "enter key" << endl;
    cin >> key;
    binary_search(arr,0,n-1,key,n);
    return 0;
}
