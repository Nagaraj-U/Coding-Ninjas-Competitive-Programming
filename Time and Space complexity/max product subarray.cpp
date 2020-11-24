#include<iostream>
using namespace std;
typedef long long ll;


ll maxproduct(int arr[],int n){
    ll max_ending_here = 1;
    ll min_ending_here = 1;
    ll max_so_far = 0;
    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            max_ending_here = max_ending_here*arr[i];
            min_ending_here = min(min_ending_here,min_ending_here*arr[i]);
        }else if(arr[i] == 0){
            max_ending_here = 1;
            min_ending_here = 1;
        }else{
            int temp = max_ending_here;
            max_ending_here = max(max_ending_here,min_ending_here*arr[i]);
            min_ending_here = temp*arr[i];
        }

        max_so_far = max(max_ending_here,max_so_far);
    }
    return max_so_far;

}

int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    ll ans = maxproduct(arr,n);
    cout << ans << endl;
    return 0;
}
