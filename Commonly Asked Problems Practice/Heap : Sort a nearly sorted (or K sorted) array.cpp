/*
Given an array of n elements, where each element is at most k away from its target position,
 devise an algorithm that sorts in O(n log k) time. For example, let us consider k is 2, an element at index 7 in the sorted array,
 can be at indexes 5, 6, 7, 8, 9 in the given array.

Examples: 

Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
            k = 3 
Output : arr[] = {2, 3, 5, 6, 8, 9, 10}

Input : arr[] = {10, 9, 8, 7, 4, 70, 60, 50}
         k = 4
Output : arr[] = {4, 7, 8, 9, 10, 50, 60, 70}

*/



//arr[0] can present atmost k dist away fron it , start filling each index one by one whenever pq.size() == k+1

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int index = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size() == k+1){
            arr[index++] = pq.top();
            pq.pop();
        }
    }
    while(!pq.empty()){
        arr[index++] = pq.top();
        pq.pop();
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << endl;
    }
    return 0;
}
