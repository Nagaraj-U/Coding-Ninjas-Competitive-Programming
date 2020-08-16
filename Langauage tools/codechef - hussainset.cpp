#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int arr[n];
     for(int i=0;i<n;i++){
         cin >> arr[i];
     }
     sort(arr,arr+n);
     int count_m = 0;
     int end_p = n-1;
     queue<ll> q;
     while(m--){
         int curr_m;
         int ans;
         cin >> curr_m;
         for(;count_m < curr_m;count_m++){
            
             if(end_p >= 0 && ( q.empty() || arr[end_p] >= q.front())){
                 ans = arr[end_p];
                 end_p--;
             }else{
                 ans = q.front();
                 q.pop();
             }
             q.push(ans/2);
         }
         cout << ans << endl;
     }
     
    return 0;
}
