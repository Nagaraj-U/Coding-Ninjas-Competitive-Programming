/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] 
indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, 
return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you
finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.

*/

//USING TOPOLOGICAL SORTING


class Solution {
public:
    
    
    bool detectCycle(vector<vector<int>> arr,int start,int n,int* visited){
        if(visited[start] == 2){
            return true;
        }
        visited[start] = 2;
        for(int i=0;i<arr[start].size();i++){
            if(visited[arr[start][i]] != 1){
                if(detectCycle(arr,arr[start][i],n,visited)){
                    return true;
                }
            }
        }
        visited[start] = 1;
        return false;
    }
    
    bool isCycle(vector<vector<int>> arr,int n){
        int* visited = new int[n]();
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                if(detectCycle(arr,i,n,visited)){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    void dfs(vector<vector<int>> & arr,int start,bool* visited,stack<int> &s,int n)
    {
        visited[start] = true;
        for(int i=0;i<arr[start].size();i++){
            if(!visited[arr[start][i]]){
                dfs(arr,arr[start][i],visited,s,n);
            }
        }
        s.push(start); //this vertex han no outdegree , hance printed last
        return;
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> arr(numCourses);
        
        for(int i=0;i<prerequisites.size();i++){
            arr[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        
        //if cycle exist return empty string
        vector<int> ans;
        if(isCycle(arr,numCourses)){
            return ans;
        }
        
        //applying topological sort
        bool* visited = new bool[numCourses]();
        stack<int> s;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                dfs(arr,i,visited,s,numCourses);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};
