/*
Given array of size n and integer k where k : number of times array is copied(append) to original array.
we have to find max subarray sum by concatenating original array k times.

1<n<10^5, 1<k<10^5

we can't concat array k times and find max subarray sum as resutant array reaches size of 10^10 in extreme conditions.
(which exceeds time kimit of 1 sec since 10^8 operation = 1 sec)

*/



#include<iostream>
#include<math.h>
using namespace  std;
typedef long long ll;
#define MIN -99999;

ll kadane(int arr[],int n){
    ll best_sum = INT_MIN;
    ll current_sum = 0;
    for(int i=0;i<n;i++){
        current_sum += arr[i];
        if(best_sum < current_sum){
            best_sum = current_sum;
        }
        if(current_sum < 0){
            current_sum = 0;
        }
    }
    return best_sum;
}


ll maxsubarray(int arr[],int n,int k){
    ll kadanesum = kadane(arr,n);
    ll bestsuffix_sum = INT_MIN;
    ll bestprefix_sum=INT_MIN;
    ll total_sum=0;
    ll current_suffix_sum = 0;
    ll current_prefix_sum = 0;
    for(int i=0;i<n;i++){
        current_prefix_sum += arr[i];
        bestprefix_sum = max(current_prefix_sum, bestprefix_sum);
    }
    total_sum = current_prefix_sum;

    for(int i=n-1;i>=0;i--){
        current_suffix_sum  += arr[i];
        bestsuffix_sum = max(current_suffix_sum , bestsuffix_sum);
    }
    if(k == 1){
        return kadanesum;
    }else{
        if(total_sum < 0){
            return max(bestprefix_sum + bestsuffix_sum, kadanesum);
        }else{
            return max(bestprefix_sum+bestsuffix_sum+(k-2)*(total_sum),kadanesum);
        }
    } 
}


int main(){
    int n,k;
    cin >> n >> k;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    ll ans = maxsubarray(arr,n,k);
    cout << ans << endl;
    return 0;
}


