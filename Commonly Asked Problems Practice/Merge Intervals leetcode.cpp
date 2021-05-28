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
