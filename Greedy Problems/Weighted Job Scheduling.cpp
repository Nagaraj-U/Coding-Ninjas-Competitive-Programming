/*
Weighted Job Scheduling
Send Feedback
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Job{
    int start;
    int finish;
    int profit;
};

bool compare(Job j1,Job j2){
    return j1.finish < j2.finish;
}

int binarysearch(Job* arr,int index){
    int low = 0;
    int high = index-1;
    while(low<=high){
        int mid = (low+high)/2;
        
        if(arr[mid].finish <= arr[index].start){
            if(arr[mid+1].finish <= arr[index].start){
                low = mid+1;
            }else{
                return mid;
            }
        }else{
            high = mid-1;
        }
    }
    return -1;
}


ll getprofit(Job* arr,int n){
    ll* dp = new ll[n]();
    dp[0] = arr[0].profit;
    ll profit ;
    for(int i=1;i<n;i++){
        ll include = arr[i].profit;
        ll exclude = dp[i-1];
        int betterindex = -1;
        betterindex = binarysearch(arr,i);  //return first index from last which for which finish time <= start time of current index
       if(betterindex != -1){
           include += dp[betterindex];
       }
        dp[i] = max(include,exclude);
    }
    return dp[n-1];
}


// ll getprofit(Job* arr,int n){
//     ll* dp = new ll[n]();
//     dp[0] = arr[0].profit;
//     ll profit ;
//     for(int i=1;i<n;i++){
//         ll include = arr[i].profit;
//         int betterindex = -1;
//         for(int j=i-1;j>=0;j--){
//             if(arr[j].finish <= arr[i].start){
//                 betterindex = j;
//                 break;
//             }
//         }
//        if(betterindex != -1){
//            include += dp[betterindex];
//        }
//         dp[i] = max(include,dp[i-1]);
//     }
//     return dp[n-1];
// }



int main()
{
    int n;
    cin >> n;
    Job* arr = new Job[n];
    for(int i=0;i<n;i++){
        cin >> arr[i].start;
        cin >> arr[i].finish;
        cin >> arr[i].profit;
    }
    sort(arr,arr+n,compare);
    cout << getprofit(arr,n);
    return 0;
}
