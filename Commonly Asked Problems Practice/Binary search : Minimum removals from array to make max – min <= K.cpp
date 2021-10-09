/*
Given N integers and K, find the minimum number of elements that should be removed, such that Amax-Amin<=K. 
After the removal of elements, Amax and Amin is considered among the remaining elements


Input : a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20} 
          k = 4 
Output : 5 
Explanation: Remove 1, 3, 4 from beginning 
and 17, 20 from the end.

Input : a[] = {1, 5, 6, 2, 8}  K=2
Output : 3
Explanation: There are multiple ways to 
remove elements in this case.
One among them is to remove 5, 6, 8.
The other is to remove 1, 2, 5
*/


#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> &arr,int start,int end,int key,int k){
    int idx = end;
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid]-key <= k){
            idx = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return idx;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    //consider each element as minimum element find in the right half of array such that arr[i] - arr[index] <= k
    sort(arr.begin(),arr.end());
    vector<int> dp(n,0);
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        int index = helper(arr,i,n-1,arr[i],k);
        dp[i] = i + (n-index-1);//prev elements till ith index + all elements after "index"
        mini = min(mini,dp[i]);
    }
    cout << mini << endl;
    return 0;
}


