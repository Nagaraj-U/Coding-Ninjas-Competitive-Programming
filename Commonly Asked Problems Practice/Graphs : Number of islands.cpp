/*

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/


// Solutiomn using DFS


class Solution {
    
    void dfs(vector<vector<char>>& grid,bool** &visited,int x,int y,int m,int n)
    {
        if(x>=m || x < 0 || y >= n || y < 0 || grid[x][y] == '0' || visited[x][y]){
            return;
        }
        visited[x][y] = true;
        dfs(grid,visited,x+1,y,m,n);
        dfs(grid,visited,x-1,y,m,n);
        dfs(grid,visited,x,y+1,m,n);
        dfs(grid,visited,x,y-1,m,n);
        
        return;
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool** visited = new bool*[m];
        for(int i=0;i<m;i++){
            visited[i] = new bool[n];
            for(int j=0;j<n;j++){
                visited[i][j] = false;
            }
        }
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid,visited,i,j,m,n);
                    count += 1;
                    
                }
            }
        }
        
        return count;
    }
};



// solution using BFS


/*

offsets = (0,1),(0,-1),(1,0),(1,-1),(1,1),(-1,0),(-1,1),(-1,-1)  if all 8 directions are allowed ,  but this question allows only 4 directions

*/

class Solution {
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool** visited = new bool*[m];
        for(int i=0;i<m;i++){
            visited[i] = new bool[n];
            for(int j=0;j<n;j++){
                visited[i][j] = false;
            }
        }
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    count++;
                    queue<pair<int,int>> q;  // make pair of {i,j} explore its all neighbours
                    q.push({i,j});
                    int offsets[5][2] = {{0,1},{1,0},{-1,0},{0,-1}}; //directions : right , top , down , left
                    while(!q.empty()){
                        pair<int,int> p = q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int first = p.first + offsets[k][0];
                            int second = p.second +  offsets[k][1];
                            if(first >= 0 && second>=0 && first<m && second<n && grid[first][second]=='1'){
                                grid[first][second] = '0'; //makrking all beighbours 0 , hence they are not considered again
                                q.push({first,second}); //push cell to queue , to explore its neighbours again
                            }
                        }
                    }
                    
                }
            }
        }
        
        return count;
    }
};
