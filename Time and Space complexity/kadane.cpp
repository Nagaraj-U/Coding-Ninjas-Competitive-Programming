#include<iostream>
using namespace std;
#define MIN -9999;

int kadane(int arr[],int n){
    int current_sum = 0;
    int best_sum = MIN;
    for(int i=0;i<n;i++){
        current_sum = current_sum + arr[i];
        if(best_sum < current_sum){
            best_sum = current_sum;
        }
        if(current_sum < 0){
            current_sum = 0;
        }
    }
    return best_sum;
}

int main(){
    int n;
    cout << "enter Number" << endl;
    cin >> n;
    int* arr =new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int ans = kadane(arr,n);
    cout << ans;
    return 0;
}
