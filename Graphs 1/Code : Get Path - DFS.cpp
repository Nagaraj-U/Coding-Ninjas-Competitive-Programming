/*
Code : Get Path - DFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
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
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :

*/




#include <iostream>
#include<vector>
using namespace std;


vector<int> getpathDFS(int** edges,int n,int start,int end,bool* visited){
    vector<int> ans;
    if(start == end){  
        ans.push_back(start);
        return ans;
    }

    for(int i=0;i<n;i++){
        if(edges[start][i] == 1 && i != start && !visited[i]){
			visited[i] = true;
            ans = getpathDFS(edges,n,i,end,visited);
            if(ans.size() != 0){
                ans.push_back(start);
                return ans;
            }
        }
    }
    return ans;
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
    int start,end;
    cin >> start >> end;
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    visited[start] = true;
    
    vector<int> ans = getpathDFS(edges,n,start,end,visited);
    if(ans.size() != 0){
        for(int i=0;i<ans.size();i++){
           cout << ans[i] << " ";
    	}
    }else{
        return 0;
    }
	
  return 0;
}


