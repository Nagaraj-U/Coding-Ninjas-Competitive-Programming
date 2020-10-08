/*
Number of APs
Send Feedback
Given an array of n positive integers. The task is to count the number of Arithmetic Progression subsequences in the array. As the answer could be very large, output it modulo 100001.
Note: Empty sequence or single element sequence is Arithmetic Progression.
Input Format:
First Line: N (the size of the array)
Second Line: Elements of the array separated by spaces.
Output:
 Print total number of subsequences
Input Constraints:
1 <= arr[i] <= 1000
1 <= sizeof(arr) <= 1000
Sample Input 1 :
3
1 2 3
Sample output:
8
Sample Output Explanation:
Total subsequence are: {}, { 1 }, { 2 }, { 3 }, { 1, 2 }, { 2, 3 }, { 1, 3 }, { 1, 2, 3 }
Sample Input 2:
7
1 2 3 4 5 9 10
Sample Output:
37
*/


#define mod 100001
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int numofAP(int *arr, int n){
    /*
    Return all possible AP subsequences formed from the given integer array. You donot need to take input or print anything.
    Just return the ans.
    */
    unordered_map<int,int>* m = new unordered_map<int,int>[n];//for each index calculating count of distict values
    int ans = 0;
    ans = n+1; //single numbers and empty string
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int diff = arr[j] - arr[i];
            m[i][diff] += 1;
            ans = (ans+1)%mod; //all two length strings
        }
    }
    
    for(int i=n-3;i>=0;i--){
        for(int j=i+1;j<n;j++){
            int diff = arr[j] - arr[i];//from jth index what all possible APs with difference = 'diff'
            m[i][diff] = (m[i][diff]%mod + m[j][diff]%mod)%mod;
            ans = (ans+m[j][diff])%mod;
        }    
    }
    return ans;
}
