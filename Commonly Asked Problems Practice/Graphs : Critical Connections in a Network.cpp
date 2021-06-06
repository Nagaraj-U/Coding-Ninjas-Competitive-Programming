/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] 
represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

Example 1:



Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
 

Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/

//BRUTE FORCE
//try removing every edge and check they make connected graph , else current edge is critical edge

class Solution {
public:
    
    void bfs(int** arr,int n,bool* visited,int start)
    {
        queue<int> q;
        q.push(start);
        visited[start] = true;
          while(!q.empty()){
            int temp = q.front();
            q.pop();
            cout << temp << endl;
            for(int i=0;i<n;i++){
                if(!visited[i] && i != temp && arr[temp][i] == 1){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        return;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int** arr = new int*[n]();
        for(int i=0;i<n;i++){
            arr[i] = new int[n]();
        }
        for(int i=0;i<connections.size();i++){
            int start,end;
            start = connections[i][0];
            end = connections[i][1];
            arr[start][end] = 1;
            arr[end][start] = 1;
        }
        
        vector<vector<int>> ans;
        int e = connections.size();
        for(int i=0;i<e;i++){
            bool* visited = new bool[n]();
            int** temp = new int*[n];
            for(int j=0;j<n;j++){
                temp[j] = new int[n];
                for(int k=0;k<n;k++){
                    temp[j][k] = arr[j][k];
                }
            }
            int start = connections[i][0];
            int end = connections[i][1];
            temp[start][end] = 0;
            temp[end][start] = 0;
            for(int i=0;i<n;i++){
                if(i != start && i != end){
                     bfs(temp,n,visited,i);
                     break;
                }
           
            }
            for(int i=0;i<n;i++){
                if(visited[i] == false){
                    vector<int> curr;
                    curr.push_back(start);
                    curr.push_back(end);
                    ans.push_back(curr);
                    break;
                }
            }
            
        }
        
        return ans;
    }
};
