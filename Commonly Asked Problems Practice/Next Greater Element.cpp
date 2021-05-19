
/*
For a given array/list of integers of size N, print the Next Greater Element(NGE) for every element. The Next Greater Element for an element X is the first element
on the right side of X in the array, which is greater than X. If no greater elements exist to the right of X, consider the next greater element as -1.
For Example:
For the given array [7, 12, 1, 20]

- The next greater element for 7 is 12.
- The next greater element for 12 is 20. 
- The next greater element for 1 is 20. 
- There is no greater element for 20 on the right side.

Output: [12, 20, 20, -1]
Input Format:
The first line of input contains an integer 'N' representing the size of the array/list.

The second line of input contains 'N' single space-separated integers representing the elements of the array/list.
Constraints :
1 <= N <= 10^5
1 <= ARR[i] <= 10^9

Time Limit: 1 sec
Output Format :
The only line of output contains 'N' single space-separated integers representing the Next Greater Element for each element. 

You do not need to print anything explicitly, it has already been taken care of.
Sample Input 1:
4
13 7 6 12
Sample Output 1:
-1 12 12 -1
Sample Input 2:
5
1 2 3 4 5
Sample Output 2:
2 3 4 5 -1

*/



/*
Push the first element to stack.
Pick rest of the elements one by one and follow the following steps in loop. 
Mark the current element as next.
If stack is not empty, compare top element of stack with next.
If next is greater than the top element, Pop element from stack. next is the next greater element for the popped element.
Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements.
Finally, push the next in the stack.
After the loop in step 2 is over, pop all the elements from the stack and print -1 as the next element for them.

*/






#include<bits/stdc++.h>
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
    // Write your code here
    vector<int> v;
    if(n==0 || n==1){
        v.push_back(-1);
        return v;
    }
    unordered_map<int,int> m;
    
    stack<int> s;
    s.push(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i] > s.top()){
            while(!s.empty() && s.top() < arr[i]){
                m[s.top()] = arr[i];
                s.pop();
            }
            s.push(arr[i]);
        }else{
            s.push(arr[i]);
        }
    }
    while(!s.empty()){
        m[s.top()] = -1;
        s.pop();
    }
    for(int i=0;i<n;i++){
        v.push_back(m[arr[i]]);
    }
    return v;
}
