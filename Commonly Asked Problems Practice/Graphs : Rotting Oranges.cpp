/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
Accepted
228K
Submissions
457.1K
*/
class Solution {
public:
    
    void bfs(vector<vector<int>> grid,int** time,int &row,int &col,int &rows,int &cols){
               
        int offset[5] = {0,1,0,-1,0}; //to trverse in all directions
        queue<pair<int,int>> q;
        q.push({row,col});
        int count = 0;//at each step it increase ,for first 4 neighbours time is 1 , then 2 for next neighbours
        while(!q.empty()){
            count++;
            int size = q.size();
            for(int i=0;i<size;i++){ //process one level at a time
                auto curr = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int r = curr.first + offset[j];
                    int c = curr.second + offset[j+1];
                    if(r < rows && c < cols && r >= 0 && c >= 0 && grid[r][c] == 1){
                        q.push({r,c}); 
                        grid[r][c] = 0; //instead of using visited , make changes in grid temporarily
                        if(time[r][c] > count){ //if time to reach the current cell is less tham prev calculated
                            time[r][c] = count;
                        }
                    }
                }
            }
        }
        
        return;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int** time = new int*[rows]; //store
        for(int i=0;i<rows;i++){
            time[i] = new int[cols];
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){ //except fresh oranges make
                    time[i][j] = INT_MAX;
                }else{
                    time[i][j] = 0;
                }
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 2){ //call whenever rotten orange present
                    bfs(grid,time,i,j,rows,cols);
                }
            }
        }
        
        int ans = -1;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(time[i][j] == INT_MAX){ //if any cell is not reachable
                    return -1;
                }
                ans = max(ans,time[i][j]);
            }
        }
        return ans;
    }
};


//USING VISITED MATRIX

/*
class Solution {
public:
    
    void bfs(vector<vector<int>>& grid,int** distance,int row,int col,int &rows,int &cols){
        bool** visited = new bool*[rows];
        for(int i=0;i<rows;i++){
            visited[i] = new bool[cols];
            for(int j=0;j<cols;j++){
                visited[i][j] = false;
            }
        }
        
        int offset[5] = {0,1,0,-1,0};
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col] = true;
        int count = 0;
        while(!q.empty()){
            count++;
            int size = q.size();
            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int r = curr.first + offset[j];
                    int c = curr.second + offset[j+1];
                    if(r < rows && c < cols && r >= 0 && c >= 0 && grid[r][c] == 1 && !visited[r][c]){
                        q.push({r,c});
                        visited[r][c] = true;
                        if(distance[r][c] > count){
                            distance[r][c] = count;
                        }
                    }
                }
            }
        }
        
        return;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int** distance = new int*[rows];
        for(int i=0;i<rows;i++){
            distance[i] = new int[cols];
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    distance[i][j] = INT_MAX;
                }else{
                    distance[i][j] = 0;
                }
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 2){
                    bfs(grid,distance,i,j,rows,cols);
                }
            }
        }
        
        int ans = -1;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(distance[i][j] == INT_MAX){
                    return -1;
                }
                ans = max(ans,distance[i][j]);
            }
        }
        return ans;
    }
};
*/
