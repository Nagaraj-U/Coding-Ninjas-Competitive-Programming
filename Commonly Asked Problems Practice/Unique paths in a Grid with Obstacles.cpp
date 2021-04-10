/*

Given a grid of size m * n, let us assume you are starting at (1, 1) and your goal is to reach (m, n).
At any instance, if you are on (x, y), you can either go to (x, y + 1) or (x + 1, y).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space are marked as 1 and 0 respectively in the grid.

Examples:  

Input: [[0, 0, 0],
        [0, 1, 0],
        [0, 0, 0]]
Output : 2
There is only one obstacle in the middle.

*/

int uniquePathsWithObstacles(vector<vector<int> > &A) {

    int m = A.size();
    int n = A[0].size();
    int** arr = new int*[m]();
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
      	for(int j=0;j<n;j++){
        	arr[i][j] = 0;
        }
    }
    if(A[0][0] == 0){
        arr[0][0] = 1;
    }else
    
    for(int i=1;i<n;i++){
        if(A[0][i] == 1){
            arr[0][i] = 0;
            continue;
        }
        arr[0][i] = arr[0][i-1];
    }
    
    for(int i=1;i<m;i++){
        if(A[i][0] == 1){
            arr[i][0] = 0;
            continue;
        }
        arr[i][0] = arr[i-1][0];
    }
    
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(A[i][j] == 1){
                arr[i][j] = 0;
                continue;
            }
            
            arr[i][j] = (arr[i-1][j] + arr[i][j-1]);
        }
    }
    
    return arr[m-1][n-1];
}


// Driver code
int main()
{
vector<vector<int>> A = { { 1, 0, 0 },
						            	{ 0, 1, 0 },
						            	{ 0, 0, 0 } };
  
							
cout << uniquePathsWithObstacles(A) << " \n";											
}
