/*
Prim's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5
*/


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int getMinVertex(int* weight,int n,bool* visited){//getting min vertex from remaining
    int minVertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}


void prims(int** edges,int n){
    bool* visited = new bool[n]();
    int* weight = new int[n];
    for(int i=0;i<n;i++){
        weight[i] = INT_MAX;
    }
    weight[0] = 0;
    
    int* parent = new int[n];
    parent[0] = -1;
    
    for(int i=0;i<n-1;i++){
        int minVertex = getMinVertex(weight,n,visited);
        visited[minVertex] = true;
        
        //explore adjacent of minVertex
        for(int j=0;j<n;j++){
            if(!visited[j] && edges[minVertex][j] != 0){
                if(weight[j] > edges[minVertex][j]){
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    
    for(int i=1;i<n;i++){
        if(parent[i] < i){
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }else{
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
    }
    
    return ;
}

int main()
{
  	
    int n,e;
    cin >> n >> e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i=0;i<e;i++){
        int start,end,w;
        cin >> start >> end >> w;
        edges[start][end] = w;
        edges[end][start] = w;
    }
    
    prims(edges,n);

  return 0;
}
