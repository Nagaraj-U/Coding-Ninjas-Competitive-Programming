

/*
Given a sorted array and a value x, the floor of x is the largest element in array smaller than or equal to x. Write efficient functions to find floor of x.
Examples: 
 

Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 5
Output : 2
2 is the largest element in 
arr[] smaller than 5.

Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 20
Output : 19
19 is the largest element in
arr[] smaller than 20.

Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 0
Output : -1
Since floor doesn't exist,
output is -1.
*/



#include<bits/stdc++.h>
using namespace std;

void binary_search(int* arr,int start,int end,int key,int n)
{
    int floor = -1;
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] == key){
            floor = arr[mid];
            break;
        }else if(arr[mid] < key){
            floor = arr[mid];
            start = mid+1;
        }else{
            end = mid-1;
        }
    }

    cout << "floor of element " << floor << endl;
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
