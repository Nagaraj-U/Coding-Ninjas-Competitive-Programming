#include<iostream>
using namespace std;
/*
        cost
person   9 8 7 
         3 2 5 
         1 10 3
mincost = 7+2+1 = 10

*/



//RECURSIVE
// int mincost(int** cost,int n,int p,int mask,int* dp){

//     if(p>=n){
//         return 0;
//     }

//     if(dp[mask] != INT_MAX){
//         return dp[mask];
//     }
//     int minimum = INT_MAX;
//     for(int j=0;j<n;j++){
//         if(!(mask&(1<<j))){ //searching for unset bit
//             int ans = cost[p][j] + mincost(cost,n,p+1,mask|(1<<j),dp); //setting unset bit
//             minimum = min(minimum,ans);
//         }
//     }

//     dp[mask] = minimum;
//     return minimum;
// }


//ITERATIVE
int mincost1(int** cost,int n){
    int* dp = new int[1<<n];
    for(int i=0;i<(1<<n);i++){
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for(int mask=0;mask<((1<<n)-1);mask++){
        int temp = mask;
        int count = 0;
        while(temp > 0){
            count += (temp & 1); //count number of set bits
            temp = (temp>>1); //right shift temp by 1 for every iteration
        }

        for(int j=0;j<n;j++){
            if(!(mask&(1<<j))){
                dp[mask|(1<<j)] = min(dp[mask|(1<<j)], dp[mask]+cost[count][j]);
            }
        }
    }
    return dp[(1<<n) - 1];
}


int main(){
    int n;
    cout << "enter number of persons "<< endl;
    cin >> n;  //n = number of jobs = number of persons
    int** cost = new int*[n];
    for(int i=0;i<n;i++){
        cost[i] = new int[n];
    }
    cout << "Enter cost matrix" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> cost[i][j];
        }
    }

    int* dp = new int[1<<n]; //creating dp array for all possible 2^n masks
    for(int i=0;i<(1<<n);i++){
        dp[i] = INT_MAX;
    }
    // cout << mincost(cost,n,0,0,dp) << endl; //intial mask 0000 for n =4
    cout << mincost1(cost,n) << endl;  //iterative
    return 0;
}
