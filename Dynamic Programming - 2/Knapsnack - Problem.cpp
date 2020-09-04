/*
Knapsnack - Problem
Send Feedback
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V,
that thief can take ?
Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/

#include<bits/stdc++.h>

//RECURSIVE SOLUTION (space : O(n*W))


#include<bits/stdc++.h>
typedef long long ll;

int helper(int* w,int* v,int n,int W,int** dp){
    if(n == 0){
        return 0;
    }
    
   if(n < 0){
        return 0;
    }
   if( W == 0){
       return 0;
   }
    if(W < 0){
        return 0;
    }
    if(dp[n][W] > -1){
        return dp[n][W];
    }
    int ans = 0;
    if(W - w[n-1] >= 0){
        ll option1 = v[n-1]+helper(w,v,n-1,W-w[n-1],dp);  //w[n-1] SINCE LAST ELEMENT INDEX IS n-1
        ll option2 = helper(w,v,n-1,W,dp);
        ans = max(option1,option2);
    }else{
        ans = helper(w,v,n-1,W,dp);
    }
    dp[n][W] = ans;
    return ans;    
}


int knapsack(int* weights, int* values, int n, int maxWeight){


    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[maxWeight+1];
        for(int j=0;j<=maxWeight;j++){
            dp[i][j] = -1;
        }
    }
    return helper(weights,values,n,maxWeight,dp);
    

}








//CORRECT SOLUTION WITH SPACE : O(w)

// int knapsack(int* wt, int* val, int n, int W){

//   /* Don't write main().
//    *  Don't read input, it is passed as function argument.
//    *  Return output and don't print it.
//    *  Taking input and printing output is handled automatically.
//   */
//   int dp[W+1]; 
      
//     //initially profit with 0 to W KnapSack capacity is 0 
//     memset(dp, 0, sizeof(dp)); 
  
//     // iterate through all items 
//     for(int i=0; i < n; i++)  
//         //traverse dp array from right to left 
//         for(int j=W; j>=wt[i]; j--) 
//             dp[j] = max(dp[j] , val[i] + dp[j-wt[i]]); 
//     /*above line finds out maximum of  dp[j](excluding ith element value) 
//       and val[i] + dp[j-wt[i]] (including ith element value and the 
//       profit with "KnapSack capacity - ith element weight") */    
//     return dp[W]; 
// 	// return ans;
// }









//space comp : O(n*W) 
// int knapSack(int W, int wt[], int val[], int n) 
// { 
//    int i, w; 
//    int K[n+1][W+1]; 
  
//    // Build table K[][] in bottom up manner 
//    for (i = 0; i <= n; i++) 
//    { 
//        for (w = 0; w <= W; w++) 
//        { 
//            if (i==0 || w==0) 
//                K[i][w] = 0; 
//            else if (wt[i-1] <= w) 
//                  K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
//            else
//                  K[i][w] = K[i-1][w]; 
//        } 
//    } 
  
//    return K[n][W]; 
// } 

// int knapsack(int* weights, int* values, int n, int maxWeight){

//   return knapSack(maxWeight, weights, values, n);


// }

//CORRECT SOLUTION WITH SPACE : O(w)

// int knapsack(int* wt, int* val, int n, int W){

//   /* Don't write main().
//    *  Don't read input, it is passed as function argument.
//    *  Return output and don't print it.
//    *  Taking input and printing output is handled automatically.
//   */
//   int dp[W+1]; 
      
//     //initially profit with 0 to W KnapSack capacity is 0 
//     memset(dp, 0, sizeof(dp)); 
  
//     // iterate through all items 
//     for(int i=0; i < n; i++)  
//         //traverse dp array from right to left 
//         for(int j=W; j>=wt[i]; j--) 
//             dp[j] = max(dp[j] , val[i] + dp[j-wt[i]]); 
//     /*above line finds out maximum of  dp[j](excluding ith element value) 
//       and val[i] + dp[j-wt[i]] (including ith element value and the 
//       profit with "KnapSack capacity - ith element weight") */    
//     return dp[W]; 
// 	// return ans;
// }

