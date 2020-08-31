#include<iostream>
using namespace std;

int LIS(int* arr,int n){
    int* output = new int[n];
    for(int i=0;i<n;i++){
        output[i]  = 1;
        for(int j=i-1 ; j>= 0 ;j--){
            if(arr[j] > arr[i]){
                continue;
            }
            int possibleAns = output[j] + 1;
            if(possibleAns > output[i]){
                output[i] = possibleAns;
            }
        }
    }
    int best = 0;
    for(int i=0;i<n;i++){
        if(best < output[i]){
            best = output[i];
        }
    }
    return best;
}

int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int ans = LIS(arr,n);;
    cout << ans << endl;
    return 0;
}
