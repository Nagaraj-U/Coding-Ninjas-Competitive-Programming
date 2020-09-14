#include<iostream>
#include<queue>
using namespace std;

void printDFS(int** edges,int n,int sv,bool* visited){
    cout << sv << endl;
    visited[sv] = true;

    for(int i=0;i<n;i++){
        if(i == sv){
            continue;
        }

        if(edges[sv][i] == 1){
            if(visited[i]){
                continue;
            }
            printDFS(edges,n,i,visited);
        }      
    }
}

void printBFS(int** edges,int n,int sv,bool* visited){
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;

    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front();
        cout << currentVertex << endl;
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

void DFS(int** edges,int n){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            printDFS(edges,n,i,visited);
        }
    }
    return;
}

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
    cout << "Enter number of vertices and edges" << endl;
    cin >> n >> e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }

    cout << "Enter first and second vertex of all edges" << endl;
    for(int i=0;i<e;i++){
        int start,end;
        cin >> start >> end;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }
    cout << "DFS traversal of Graph : " << endl;
    DFS(edges,n);

    cout << "BFS traversal of graph : " << endl;
    BFS(edges,n);
    return 0;
}
