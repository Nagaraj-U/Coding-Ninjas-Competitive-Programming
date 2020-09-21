/*

Dijkstra's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int getMinVertex(int* distance,bool* visited,int n){
    int minVertex = -1;
    for(int i=0;i<n;i++){  //getting min vertex from remaining unvisited nodes which has less distance value
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])){
            minVertex = i;
        }
    }
    
    return minVertex;
}

void dijkstras(int** edges,int n){
    bool* visited = new bool[n];
    int* distance = new int[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    
    for(int i=0;i<n-1;i++){
        int minVertex = getMinVertex(distance,visited,n);
        visited[minVertex] = true;
        
        for(int j=0;j<n;j++){
            if(!visited[j] && edges[minVertex][j] != 0){
                if(distance[j] > (distance[minVertex] + edges[minVertex][j])){ //better way exist to reach 'j' node from minVertex
                    distance[j] = (distance[minVertex] + edges[minVertex][j]);
                }
            }
        }
    }
    
    //distance array contains distance of each node from source i.e '0th vertex'
    for(int i=0;i<n;i++){
        cout << i <<  " " << distance[i] << endl;
    }
    
    return;
}

int main()
{
  
    int n,e;
    cin >> n >> e;
    int** edges = new int*[n]();
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
    }
    
    for(int i=0;i<e;i++){
        int start,end,w;
        cin >> start >> end >> w;
        edges[start][end] = w;
        edges[end][start] = w;
    }
    
    dijkstras(edges,n);
  return 0;
}
