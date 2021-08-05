/*
Largest Piece
Send Feedback
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . 
A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , 
can you find the size of the biggest piece of '1's for Gary ?
Constraints :
1<=N<=50
Input Format :
Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake
Output Format :
Size of the biggest piece of '1's and no '0's
Sample Input :
2
11
01
Sample Output :
3
*/



#include<bits/stdc++.h>
using namespace std;

int offset[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int bfs(vector<vector<int>> &arr,vector<vector<bool>> &visited,int n,int i,int j){
    queue<pair<int,int>> q;
    q.push({i,j});

    int count = 1;
    visited[i][j] = true;

    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int row = curr.first + offset[k][0];
            int col = curr.second + offset[k][1];
            if(row < n and col < n and row >= 0 and col >= 0 and !visited[row][col] and arr[row][col] == 1){
                count++;
                q.push({row,col});
                visited[row][col] = true;
            } 
        }
    }
    return count;
}

int getBiggestPieceSize(vector<vector<int>> &cake,int n){
	
	vector<vector<bool>> visited(n,vector<bool>(n,false));
    int ans = INT_MIN;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cake[i][j] == 1 and !visited[i][j]){
                ans = max(ans,bfs(cake,visited,n,i,j));
            }
        }
    }
	return ans;
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> cake(n,vector<int>(n));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> cake[i][j];
		}
	}
	
	cout << getBiggestPieceSize(cake,n) << endl;

	return 0;
}



/*
#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55
char cake[NMAX][NMAX];

int getans(int** cake,int n,int i,int j,bool** visited){
    if(i >= n || j >= n || i < 0 || j < 0){
        return 0;
    }
    
    int count = 0;
    if(i-1 >= 0 && !visited[i-1][j] && cake[i-1][j] == 1){ //top
        visited[i-1][j] = true;
        count += 1 + getans(cake,n,i-1,j,visited);
        
        // visited[i-1][j] = false;
    }
    
    if(j-1 >= 0 && !visited[i][j-1] && cake[i][j-1] == 1){  //left
        visited[i][j-1] = true;
        count += 1 + getans(cake,n,i,j-1,visited);
        
        // visited[i][j-1] = true;
    }
    
    if(j+1 < n && !visited[i][j+1] && cake[i][j+1] == 1){ //right 
        visited[i][j+1] = true;
        count += 1 + getans(cake,n,i,j+1,visited);
        
        // visited[i][j+1] = false;
    }
    
    if(i+1 < n && !visited[i+1][j] && cake[i+1][j] == 1){  //bottom
        visited[i+1][j] = true;
        count += 1 + getans(cake,n,i+1,j,visited);
        
        // visited[i+1][j] = false;
    }
    
    return count;
}


int solve(int n,char arr[NMAX][NMAX])
{
	int maximum = 0;
    
    bool** visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[n];
        for(int j=0;j<n;j++){
            visited[i][j] = false;
        }
    }
    
    int** cake = new int*[n];
    for(int i=0;i<n;i++){
        cake[i] = new int[n];
        for(int j=0;j<n;j++){
            cake[i][j] = arr[i][j] - '0';
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cake[i][j] == 1){
                visited[i][j] = true;
                int ans = 1 + getans(cake,n,i,j,visited);
                maximum = max(maximum,ans);
                
                for(int p=0;p<n;p++){
                    for(int q=0;q<n;q++){
                        visited[p][q] = false;
                    }
                }
                
            }
        }
    }
    return maximum;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}
*/
