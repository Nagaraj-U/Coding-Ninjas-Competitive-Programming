/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi),
where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal,
return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/

//basically apply dijkstras algo and return the time taken to reach to farthest node


#define INF 600001
class Solution {
public:
    
    int getMinVertex(int* distance,bool* visited,int n)
    {
        int minVertex = -1;
        for(int i=0;i<n;i++){
            if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])){
                minVertex = i;
            }
        }
        
        return minVertex;
    }
    
    int helper(int** arr,int n,int start,bool* visited,int* distance)
    {
        for(int i=0;i<n-1;i++){
            int minVertex = getMinVertex(distance,visited,n);
            visited[minVertex] = true;
            for(int i=0;i<n;i++){
                if(!visited[i] && arr[minVertex][i] != -1 && i != minVertex){
                    if(distance[i] > distance[minVertex] + arr[minVertex][i]){
                        distance[i] = distance[minVertex] + arr[minVertex][i];
                    }
                }
            }
        }
        int ans = -1;
        for(int i=0;i<n;i++){
            ans = max(ans,distance[i]);
        }
        return ans;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int** arr = new int*[n];
        for(int i=0;i<n;i++){
            arr[i] = new int[n];
            for(int j=0;j<n;j++){
                arr[i][j] = -1;
            }
        }
        
        for(int i=0;i<times.size();i++){
            int start,end,time;
            start = times[i][0]-1;
            end = times[i][1]-1;
            time = times[i][2];
            arr[start][end] = time;
        }
        
        bool* visited = new bool[n]();
        int* distance = new int[n]();
        for(int i=0;i<n;i++){
            distance[i] = INF;
        }
        distance[k-1] = 0;
        int ans = helper(arr,n,k-1,visited,distance);
        if(ans == INF){
            return -1;
        }else{
            return ans;
        }
    }
};
