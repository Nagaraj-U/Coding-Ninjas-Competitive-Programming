/*
//to store sum of array elements in given range

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void update(int index,int val,int* BIT,int n){
    while(index <= n){
        BIT[index] += val;
        index += index&(-index);
    }
    return;
}

int query(int index,int* BIT){
    int sum = 0;
    while(index > 0){
        sum += BIT[index];
        index -= (index)&(-index);
    }
    return sum;
}

int main(){
    int n;
    cout << "Enter number of array elements " << endl;
    cin >> n;
    int* arr = new int[n+1]();
    int* BIT = new int[n+1]();
    cout << "Enter array elements " << endl;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        update(i,arr[i],BIT,n);
    }

    cout << "Enter Range for which sum is required " << endl; //indexing start from 1
    int left,right;
    cin >> left >> right;
    int ans = (query(right,BIT) - query(left-1,BIT));
    cout << "Sum from " << left << " to " << right << " is  : " << ans << endl;
    return 0;
}
*/
