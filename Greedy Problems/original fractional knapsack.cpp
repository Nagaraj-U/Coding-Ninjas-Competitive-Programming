#include<bits/stdc++.h>
using namespace std;

struct Item{
    int weight;
    int value;
};

bool compare(Item a , Item b){
    double ans1 = ((double)(a.value)/a.weight);
    double ans2 = ((double)(b.value)/b.weight);
    return ans1 > ans2;
}

double fknapsack(Item* arr,int n,int W){
    double cur_weight = 0;
    double cur_value = 0;
    for(int i=0;i<n;i++){
        if(cur_weight + arr[i].weight <= W){
            cur_weight += arr[i].weight;
            cur_value += arr[i].value;
        }else{
            double rem_weight = W - cur_weight;
            // cur_weight += arr[i].value*(rem_weight/arr[i].weight);
            cur_value += arr[i].value*(rem_weight/arr[i].weight);
        }
    }
    return cur_value;
}

int main(){
    
    int n;
    int W;
    cin >> n >> W;
    Item* arr = new Item[n];
    for(int i=0;i<n;i++){
        cin >> arr[i].value;
        cin >> arr[i].weight;
    }
    cout << fknapsack(arr,n,W) << endl;
    return 0;
}
