#include<bits/stdc++.h>
using namespace std;

int getMinVertex(int* dist,int n,bool* visited)
{
    int minVertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minVertex == -1 || dist[i] < dist[minVertex])){
            minVertex = i;
        } 
        
    }
    return minVertex;
}


//O(V*V)

void prims(int** arr,int n,int e,bool* visited)
{

    int* dist = new int[n];
    for(int i=0;i<n;i++){
        dist[i] = INT_MAX;
    }

    int* parent = new int[n]();
    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    dist[0] = 0;
    int count  = 0;
    while(count != n-1)
    {
        int minVertex = getMinVertex(dist,n,visited);
        visited[minVertex] = true;
        count++;
        for(int i=0;i<n;i++){
            if(!visited[i] && arr[minVertex][i] != 0 && minVertex != i){
                if(dist[i] > arr[minVertex][i]){
                    dist[i] = arr[minVertex][i];
                    parent[i] = minVertex;
                }
            }
        }
    }
    cout << "minimum spanning tree" << endl;
    for(int i=0;i<n;i++){
        if(parent[i] != i){
            cout << i << " " << parent[i] << " weight " << arr[i][parent[i]] << endl;
        }
    }
    return;
}



int main()
{
    int n,e;
    cin >> n >> e;
    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            arr[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int start,end,cost;
        cin >> start >> end >> cost;
        arr[start][end] = cost;
        arr[end][start] = cost;
    }
    bool* visited = new bool[n]();
    prims(arr,n,e,visited);
    return 0;
}
