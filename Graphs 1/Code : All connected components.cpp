/*
Code : All connected components
Send Feedback
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Different components in new line
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/

#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> getConnectedComponents(int** edges,int n,int start,bool* visited){
    queue<int> vertices;
    vector<int> ans;
    vertices.push(start);
    visited[start] = true;
    // ans.push_back(start);
    
    while(!vertices.empty()){
        int current = vertices.front();
        ans.push_back(current);
        vertices.pop();
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[current][i] == 1 && i != current){
            visited[i] = true;
            vertices.push(i);
            // ans.push_back(i);
            }
        }     
    }
    return ans;
}


vector<vector<int>> getans(int**edges,int n){
    bool* visited = new bool[n];
    vector<vector<int>> components;
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int> ans = getConnectedComponents(edges,n,i,visited);
            components.push_back(ans);
        }
    }
    return components;
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
        int start,end;
        cin >> start >> end;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }
    
    vector<vector<int>> components = getans(edges,n);
    for(int i=0;i<components.size();i++){
        sort(components[i].begin(),components[i].end()); //sorting individual vectors
        for(int j=0;j<components[i].size();j++){
            cout << components[i][j] << " ";
        }
        cout << endl;
    }
  return 0;
}


/*

#include <bits/stdc++.h>
using namespace std;
#include <vector>

vector<int> getComponent(int **edges, bool *visited, int n, int start)
{
    vector<int> ans;
    queue<int> pending;
    pending.push(start);
    visited[start] = true;
    while (!pending.empty())
    {
        int current = pending.front();
        pending.pop();
        ans.push_back(current);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && i != start && edges[current][i] == 1)
            {
                pending.push(i);
                visited[i] = true;
            }
        }
    }
    return ans;
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int start, end;
        cin >> start >> end;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }

    vector<vector<int>> components;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> component = getComponent(edges, visited, n, i);
            components.push_back(component);
        }
    }
    if (components.size() != 0)
    {
        for (int i = 0; i < components.size(); i++)
        {
            sort(components[i].begin(), components[i].end());
            for (int j = 0; j < components[i].size(); j++)
            {
                cout << components[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No components returned" << endl;
    }
    return 0;
}
*/
