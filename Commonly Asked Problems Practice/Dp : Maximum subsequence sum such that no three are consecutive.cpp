
/*
Given a sequence of positive numbers, find the maximum sum that can be formed which has no three consecutive elements present.
Examples : 

Input: arr[] = {1, 2, 3}
Output: 5
We can't take three of them, so answer is
2 + 3 = 5

Input: arr[] = {3000, 2000, 1000, 3, 10}
Output: 5013 
3000 + 2000 + 3 + 10 = 5013
*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<int> sum(n,0);
    sum[0] = arr[0];
    sum[1] = arr[0] + arr[1];
    sum[2] = max({arr[0] + arr[1] , arr[2] + arr[0] , arr[1] + arr[2]});
    for(int i=3;i<n;i++){//3 options : exclude last OR exclude second last OR exclude third last
        sum[i] = max({sum[i-1],sum[i-2] + arr[i] , sum[i-3] + arr[i-1] + arr[i]});
    }
    cout << sum[n-1] << endl;
    return 0;
}
