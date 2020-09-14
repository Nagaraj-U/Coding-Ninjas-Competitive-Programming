/*
Code : BFS Traversal
Send Feedback
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note : 1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
BFS Traversal (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2

*/

#include<iostream>
#include<queue>
using namespace std;

// void printDFS(int** edges,int n,int sv,bool* visited){
//     cout << sv << endl;
//     visited[sv] = true;

//     for(int i=0;i<n;i++){
//         if(i == sv){
//             continue;
//         }

//         if(edges[sv][i] == 1){
//             if(visited[i]){
//                 continue;
//             }
//             printDFS(edges,n,i,visited);
//         }      
//     }
// }

void printBFS(int** edges,int n,int sv,bool* visited){
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;

    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front();
        cout << currentVertex << " ";
        pendingVertices.pop();

        for(int i=0;i<n;i++){
            if(currentVertex == i){
                continue;
            }
            if(edges[currentVertex][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }

    }
}

// void DFS(int** edges,int n){
//     bool* visited = new bool[n];
//     for(int i=0;i<n;i++){
//         visited[i] = false;
//     }

//     for(int i=0;i<n;i++){
//         if(!visited[i]){
//             printDFS(edges,n,i,visited);
//         }
//     }
//     return;
// }

void BFS(int** edges,int n){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            printBFS(edges,n,i,visited);
        }
    }
    return;
}

int main(){
    int n,e;
    // cout << "Enter number of vertices and edges" << endl;
    cin >> n >> e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }

    // cout << "Enter first and second vertex of all edges" << endl;
    for(int i=0;i<e;i++){
        int start,end;
        cin >> start >> end;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }
//     cout << "DFS traversal of Graph : " << endl;
//     DFS(edges,n);

//     cout << "BFS traversal of graph : " << endl;
    BFS(edges,n);
    return 0;
}
