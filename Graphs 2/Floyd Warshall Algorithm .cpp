
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

//All pairs shortest path
//works for all types of graph directed,undirected
//idea is consider all passobility of edges between (i,j) and try to to add vertex " k" between them 
//if adding "k" reduces the shortest path update it 
//relaxing every edge "k" times

//Put some large values if no edge is present between two vertices in adjacency matrix  (i , i ) put infinity

void warshall(int** arr,int n)
{
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
                }
         }
    }
    return;
}

int main()
{

    int n;
    cin >> n;
    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
    }
    
    for(int  i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];        
        }
    }
    
    warshall(arr,n);
    
    for(int  i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";        
        }
        cout << endl;
    }
    
    
    return 0;
}
