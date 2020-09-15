/*

Code : Has Path
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false*/

#include <iostream>
#include<queue>
using namespace std;

bool getansBFS(int** edges,int n,int start,int end){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]  =false;
    }
    if(start == end){
        return true;
    }
    
    if(edges[start][end] == 1){
        return true;
    }
    
    queue<int> pendingVertices;
    pendingVertices.push(start);
    visited[start] = true;
    
    while(!pendingVertices.empty()){
        int current = pendingVertices.front();
        pendingVertices.pop();
        for(int i=0;i<n;i++){
            if(i == current){
                continue;
            }
            
            if(edges[current][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    
    if(visited[end]){
        return true;
    }
    
    return false; 
}


// bool getansDFS(int** edges,int n,int start,int end,bool* visited){
  
//     if(start == end){
//         return true;
//     }
    
//     for(int i=0;i<n;i++){
//         if(!visited[i] && i != start && edges[start][i] == 1){
//             visited[i] = true;
//             if(getansDFS(edges,n,i,end,visited)){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

int main() {
    int n, e;
    cin >> n >> e;
    int** edges = new int*[n];
    
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i=0;i<e;i++){
        int start,end;
        cin >> start >> end;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }
    
    int start,end;
    cin >> start >> end;
    
    
    //BFS IMPLEMENTATION
    bool ans = getansBFS(edges,n,start,end);
    
    //DFS IMPLEMENTATION
//     bool* visited = new bool[n];
//     for(int i=0;i<n;i++){
//         visited[i] = false;
//     }
//     visited[start] = true;
    
//     bool ans = getansDFS(edges,n,start,end,visited);
    if(ans){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

  return 0;
}
