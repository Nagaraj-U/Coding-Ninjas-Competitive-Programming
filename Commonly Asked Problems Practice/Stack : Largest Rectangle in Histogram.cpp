/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

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
    int largestRectangleArea(vector<int>& heights) {
        //find next next smaller element to right and left for each histogram
        int n = heights.size();
        int* left = new int[n];
        int* right = new int[n];
        
        stack<pair<int,int>> s;
        //right
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                right[i] = n;
                s.push({heights[i],i});
            }else if(s.top().first >= heights[i]){
                while(!s.empty() and s.top().first >= heights[i]){
                    s.pop();
                }
                
                if(s.empty()){
                    right[i] = n;
                    s.push({heights[i],i});
                }else{
                    right[i] = s.top().second;
                    s.push({heights[i],i});
                }
            }else if(s.top().first < heights[i]){
                right[i] = s.top().second;
                s.push({heights[i],i});
            }
        }
        
        
        //clear stack
        while(!s.empty()){
            s.pop();
        }
        
        //left
        for(int i=0;i<n;i++){
            if(s.empty()){
                left[i] = -1;
                s.push({heights[i],i});
            }else if(s.top().first >= heights[i]){
                while(!s.empty() and s.top().first >= heights[i]){
                    s.pop();
                }
                
                if(s.empty()){
                    left[i] = -1;
                    s.push({heights[i],i});
                }else{
                    left[i] = s.top().second;
                    s.push({heights[i],i});
                }
            }else if(s.top().first < heights[i]){
                left[i] = s.top().second;
                s.push({heights[i],i});
            }
        }
        
        int max_area = INT_MIN;
        for(int i=0;i<n;i++){
            int left_area = (i - left[i])*heights[i];
            int right_area = (right[i] - i)*heights[i];
            max_area = max(max_area , left_area + right_area - heights[i]);// minus heights[i] , since its contributing two times
        }
        return max_area;
    }
};
