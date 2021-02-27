/*

Kruskal's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
1 2 1
0 1 3
0 3 5
*/


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//kruskal algorithm calculates minimum spanning tree of graph
//sort edges in axsending order
//take care of no cycle formation(union find algo)
//number of output edges = vertices - 1
//time complexity O()


struct Edge{
        int v1;
        int v2;
        int w;
};


bool compare(Edge e1,Edge e2){
    return e1.w < e2.w  //sort according to weight
}



int getParent(int* parent,int v){
    if(v == parent[v]){   //if parent of 2->1 ,1->0,0->0   call fun(arr,2) -> fun(arr,1) -> fun(arr,0) return  arr[v] = v
        return v;
    }
    
    return getParent(parent,parent[v]);
}



Edge* kruskal(Edge* edges,int n,int e){
    
    sort(edges,edges+e,compare);
    Edge* output = new Edge[n-1];
    int count = 0; //to count edges = n-1
    int i = 0;  //to treverse all edges in input graph
    int* parent = new int[n];
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    
    while(count < (n-1)){
        Edge currentEdge = edges[i];
        int srcParent = getParent(parent,currentEdge.v1);
        int dstParent = getParent(parent,currentEdge.v2);
        if(srcParent != dstParent){
          	output[count] = edges[i];
            parent[dstParent] = srcParent;
            count++;
        }
        i++;  
    }
    return output;  
}



int main()
{
   
    int n, e;
    cin >> n >> e;
  	Edge* edges = new Edge[e];
    for(int i=0;i<e;i++){
        int src,dst,W;
        cin >> src >> dst >> W;
        edges[i].v1 = src;
        edges[i].v2 = dst;
        edges[i].w = W;
    }
    
    Edge* output = kruskal(edges,n,e);
    
    for(int i=0;i<n-1;i++){
        if(output[i].v1 < output[i].v2){
            cout << output[i].v1 << " " << output[i].v2 << " " << output[i].w << endl;
        }else{
            cout << output[i].v2 << " " << output[i].v1 << " " << output[i].w << endl;
        }
    }

  return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int start;
    int end;
    int weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

Edge *kruskal(Edge *arr, int e, int n)
{
    Edge *output = new Edge[n - 1];
    int count = 0;
    int i = 0;
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    while (count < (n - 1))
    {
        int src = arr[i].start;
        int dest = arr[i].end;
        int srcParent = parent[src];
        int destParent = parent[dest];
        if (srcParent != destParent)
        {
            output[count] = arr[i];
            count++;
            parent[dest] = srcParent;
        }
        i++;
    }
    return output;
}

int main()
{
    int n, e;
    cin >> n >> e;
    Edge *arr = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        cin >> arr[i].start >> arr[i].end >> arr[i].weight;
    }
    sort(arr, arr + e, compare);
    Edge *output = kruskal(arr, e, n);
    for (int i = 0; i < n - 1; i++)
    {
        cout << output[i].start << " " << output[i].end << " " << output[i].weight << endl;
    }
    return 0;
}

*/
