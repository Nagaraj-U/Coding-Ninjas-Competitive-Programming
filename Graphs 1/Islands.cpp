/*
Islands
Send Feedback
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Output Return Format :
The count the number of connected groups of islands
Sample Input :
2 1
1
2
Sample Output :
1 
*/


#include<bits/stdc++.h>

void getcount(int** edges,int n,int start,bool* visited){
    queue<int> vertices;
    vertices.push(start);
    visited[start] = true;
    
    while(!vertices.empty()){
        int current = vertices.front();
        vertices.pop();
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[current][i] == 1 && i != current){
                visited[i] = true;
                vertices.push(i);
            }
        }
    }
    return;
}


int solve(int n,int m,vector<int>u,vector<int>v)
{
	int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i=0;i<m;i++){
        int start = u[i] - 1;
        int end = v[i] - 1;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }
    
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    
    int count = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            count++;    //everytime function is called we get one connected component
            getcount(edges,n,i,visited);
        }
    }
    
    return count;
}
