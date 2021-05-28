/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover
all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104


*/



bool compare(vector<int> v1,vector<int> v2)
{
    return v1[0] < v2[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),compare);
        stack<vector<int>> s;
        s.push(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            vector<int> temp = s.top();
            if(temp[1] >= intervals[i][0]){
                temp[1] = max(temp[1],intervals[i][1]); //update end time 
                s.pop();
                s.push(temp);
            }else{
                s.push(intervals[i]);
            }
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
         return ans;
    }
    
    
    
   
};
