/*
finding product of given array except at A[i]
contraints : dont use division by A[i] to product
constant space requirement(no additional creation of array)

*/



#include<iostream>
using namespace std;


int main(){

    int n;
    cin >> n;
    long arr[n];
    long product[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    //SOLUTION 1  : IN ONE ARRAY WE ARE MAINTAINING BOTH LEFT AND RIGHT PRODUCT ARRAY

    long rp = 1;
    long lp = 1;
    for(int i=0;i<n;i++){
        product[i] = lp;
        lp = lp * arr[i];
    }
    for(int i=n-1;i>=0;i--){
        product[i] = product[i] * rp;
        rp = rp * arr[i];
    }
    for(int i=0;i<n;i++){
        cout << product[i] << " ";
    }




    //SOLUTION 2 : TAKING PRODUCT OF ALL ARRAY AND DIVIDING BY ARR[I]
    // long pro;
    // for(int i=0;i<n;i++){
    //     pro = pro*arr[i];
    // }
    // for(int i=0;i<n;i++){
    //     cout << (int)(pro / arr[i]) << " ";
    // }




    //SOLUTION 3  : CREATING TWO ARRAY(LEFT AND RIGHT AND COPYING TO THIRD ARRAY)  
    // long left[n];
    // long right[n];
    
    // long lp=1;
    // long rp=1;
    // for(int i=0;i<n;i++){
    //     left[i] = lp;
    //     lp = lp*arr[i];
    // }
    // for(int i=n-1;i>=0;i--){
    //     right[i] = rp;
    //     rp = rp*arr[i];
    // }
    // int i=0;
    // int j=0;
    // while(i<n && j <n){
    //     product[i] = left[i] * right[i];
    //     i++;
    //     j++;
    // }
    // for(int i=0;i<n;i++){
    //     cout << product[i] << " ";
    // }




    return 0;
}

