/*
Largest Rectangle in Histogram
Hard

6023

110

Add to List

Share
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        int* left = new int[n]();
        int* right = new int[n]();
        stack<int> s;
        left[0] = 0;
        s.push(0);
        for(int i=1;i<n;i++){
            if(arr[s.top()] >= arr[i]){
                while(!s.empty() && arr[s.top()] >= arr[i]){
                    s.pop();
                }
                if(s.empty()){
                    left[i] = 0;
                }else{
                    left[i] = s.top() + 1;
                }
                
                s.push(i);
            }else{
                s.push(i);
                left[i] = i;
            }
            
        }
        
        stack<int> s1;
        right[n-1] = n-1;
        s1.push(n-1);
        for(int i=n-1;i>=0;i--){
            if(arr[s1.top()] >= arr[i]){
                while(!s1.empty() && arr[s1.top()] >= arr[i]){
                    s1.pop();
                }
                
                if(s1.empty()){
                    right[i] = n-1;
                }else{
                    right[i] = s1.top() - 1;
                }
                
                s1.push(i);
            }else{
                right[i] = i;
                s1.push(i);
            }
        }
        int area = INT_MIN;
//         for(int i=0;i<n;i++){
//             cout << left[i] << endl;
//         }
        
//         for(int i=0;i<n;i++){
//             cout << right[i] << endl;
//         }
        for(int i=0;i<n;i++){
            int curr = arr[i] * (right[i]- left[i] + 1);
            area = max(area,curr);
        }
        return area;
    }
};
