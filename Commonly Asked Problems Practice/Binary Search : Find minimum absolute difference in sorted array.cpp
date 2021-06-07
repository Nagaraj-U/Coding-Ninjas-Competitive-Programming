#include<bits/stdc++.h>
using namespace std;


/*
Find minimum absolute difference element in given array

given array [1,3,5,8,9] and key = 7
answer = 8 - 7 = 1

if key = 8 then ans = 8 - 8 = 0

*/


//find two elements between which key lies and take one one with less diff in neighbours
//in binary search at last after loops breaks ,start and end are pointing to neighbours of key (end < key and start > key)


void binary_search(int* arr,int start,int end,int key,int n)
{
    int ans = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid] == key){
            ans = 0;
            break;
        }else if(arr[mid] > key){
            end = mid - 1;
        }else{
            start = mid+1;
        }
    }
    if(ans == -1){
        cout << min(abs(arr[start] - key) , abs(arr[end] - key)) << endl;
    }else{
        cout << 0 << endl;
    }
    return;
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

