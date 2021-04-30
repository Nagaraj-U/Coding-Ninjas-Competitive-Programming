
/*

Given an array of integers ‘ARR’ and an integer ‘X’, you are supposed to find the number of subarrays of ARR which have bitwise XOR of the elements equal to X.
Note:
An array ‘B’ is a subarray of an array ‘A’ if ‘B’ that can be obtained by deletion of, several elements(possibly none) from the start of ‘A’ and several elements(possibly none) from the end of ‘A’. 
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases. The test cases follow.

The first line of each test case contains two integers ‘N’ and ‘X’ separated by a single space, denoting the number of elements in the array and the required subarray XOR respectively.

The second line of each test case contains ‘N’ single space-separated integers denoting the elements of the array.
Output Format :
For each test case, print on a new line the number of subarrays of the given array that have bitwise XOR of the elements equal to ‘X’.
Note :
You don’t need to print anything; It has already been taken care of.
Constraints :
1 <= T <= 10
3 <= N <= 5*10^4
0 <= X <= 10^9
0 <= ARR[i] <= 10^9

Where ‘T’ denotes the number of test cases, ‘N’ denotes the number of elements in the array, ‘X’ denotes the required subarray XOR and ARR[i] denotes the i-th element of the given array.

Time Limit: 1 sec
Sample Input 1 :
2
5 8
5 3 8 3 10
3 7
5 2 9
Sample Output 1 :
2
1
Explanation Of Sample Input 1 :
In the first test case, the subarray from index 1 to index 3 i.e. {3,8,3} and the subarray from index 2 to index 2 i.e. {8} have bitwise XOR equal to 8.

In the second test case, the subarray from index 0 to index 1 i.e. {5,2} has bitwise XOR equal to 7.
Sample Input 2 :
2
6 11
10 1 0 3 4 7
5 4
4 3 1 2 4
Sample Output 2 :
3
4

*/






//number of subarrays with xor value 'x' ending at index 'i'

#include<unordered_map>
int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    int* prefix_xor = new int[n];
    prefix_xor[0] = arr[0];
    for(int i=1;i<n;i++){
        prefix_xor[i] = arr[i] ^ prefix_xor[i-1]; 
    }
    int ans = 0;
    unordered_map<int,int> m;

    for(int i=0;i<n;i++){
        
        //req_xor gives 
        int req_xor = prefix_xor[i] ^ x;
        ans += m[req_xor];
        
        if(prefix_xor[i] == x){
            ans++;
        }
        
        //storing count of current prefix xor
        m[prefix_xor[i]]++;
    }
    return ans;
}

/*
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n = arr.size();
    int count = 0;
    for(int i=0;i<n;i++){
        int temp = 0;
        for(int j=i;j<n;j++){
            temp = temp ^ arr[j];
            if(temp == x){
                count++;
            }
        }
    }
    return count;
}
*/
