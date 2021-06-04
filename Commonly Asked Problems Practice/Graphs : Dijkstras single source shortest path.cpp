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



// O(V*V)

void dijkstras(int** arr,int n,int start,bool* visited)
{
    int* distance = new int[n];
    for(int i=0;i<n;i++){
        distance[i] = INT_MAX;
    }

    int* parent = new int[n]();
    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    distance[start] = 0;
    for(int i=0;i<n-1;i++){
        int minVertex = getMinVertex(distance,n,visited);
        visited[minVertex] = true;
        for(int i=0;i<n;i++){
            if(!visited[i] && arr[minVertex][i] != 0 && i != minVertex){
                if(distance[i] > arr[minVertex][i] + distance[minVertex]){
                    distance[i] = distance[minVertex] + arr[minVertex][i];
                    parent[i] = minVertex;
                }
            }
        }
    }


    for(int i=0;i<n;i++){
        cout << start << " " << i << " distance : " << distance[i] << " via " << parent[i] << " node" << endl;
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
    dijkstras(arr,n,0,visited);
    return 0;
}
