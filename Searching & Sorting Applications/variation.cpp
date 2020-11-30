/*

We say that two integers x and y have a variation of at least K, if |x − y| ≥ K (the absolute value of their difference is at least K).
 Given a sequence of N integers a1,a2,...,aN and K, the total variation count is the number of pairs of elements in the sequence with variation 
 at least K, i.e. it is the size of the set of pairs


{(i,j)|1≤i<j≤N and|ai−aj|≥K}


For example if K = 1 and the sequence is 3,2,4 the answer is 3. If K = 1 and the sequence is 3, 1, 3 then the answer is 2.


Your task is to write a program that takes a sequence and the value K as input and computes the total variation count.


Input format
The first line contains two positive integers N and K, separated by a space.


This is followed by a line containing N integers separated by space giving the values of the sequence.


Output format
A single integer in a single line giving the total variation count.


Test data
You may assume that all integers in the input are in the range 0 to 10^8 inclusive.


Subtask 1 (40 marks) : 1 ≤ N ≤ 4000, 1 ≤ K ≤ 10^8

Subtask 2 (60 marks) : 1 ≤ N ≤ 65000, 1 ≤ K ≤ 10^8


Sample Input
3 1 
3 1 3

Sample Output
2

*/


#include<algorithm>
using namespace std;

// int getcount(int* arr,int current,int start,int end,int k){
//     int ans = -1;
//     while(start <= end){
//         int mid = (start+end)/2;
//         if((arr[mid] - current) >= k){
//             ans = mid;
//             start = mid+1;
//         }else{
//             end = mid-1;
//         }
//     }
//     return ans;
// }

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int count = 0;
    for(int i=0;i<n;i++){
        int index = lower_bound(arr,arr+n,arr[i]+k) - arr;
        if(index < n){
            count += (n-index);
        }
    }
    cout << count << endl;
    return 0;

}
