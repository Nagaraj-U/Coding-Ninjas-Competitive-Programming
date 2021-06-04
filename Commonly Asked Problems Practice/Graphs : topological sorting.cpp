/*
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering. 
Topological Sorting for a graph is not possible if the graph is not a DAG.


For example, a topological sorting of the following graph is “5 4 2 3 1 0”. There can be more than one topological sorting for a graph. For example, 
nother topological sorting of the following graph is “4 5 2 3 1 0”. 
The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges).





6 6
5 0
4 0
5 2
4 1
2 3
3 1
topological sort
5 4 2 3 1 0
C:\Users\Nagaraj U\Desktop\lab_progs>.\a
4 4
2 0
0 1
3 1
3 2
topological sort
3 2 0 1



*/

#include<bits/stdc++.h>
using namespace std;


//visited array : 1 : visited (pop off from recursive stack)  2 : processing (still in recursive stack) ,  0 : unvisited
bool isCycle(vector<vector<int>> list,int start,int n,int* visited)
{
    if(visited[start] == 2){
        return true;
    }

    visited[start] = 2;
    for(int i=0;i<list[start].size();i++){
        if(visited[list[start][i]] != 1){ // 0 or 2  
            if(isCycle(list,list[start][i],n,visited)){
                return true;
            }
        }
    }

    visited[start] = 1;
    return false;
}

void dfs(vector<vector<int>> arr,bool* visited,int start,int n,stack<int> &s)
{
    visited[start] = true;
    for(int i=0;i<arr[start].size();i++){
        if(!visited[arr[start][i]]){
            dfs(arr,visited,arr[start][i],n,s);
        }
    }
    s.push(start);
}

int main()
{
    int n,e;
    cin >> n >> e;
    vector<vector<int>> list(n);
    for(int i=0;i<e;i++){
        int start , end;
        cin >> start >> end;
        list[start].push_back(end);
    }

    int* visited = new int[n]();
    for(int i=0;i<n;i++){
        if(visited[i] == 0){
                if(isCycle(list,i,n,visited)){
                cout << "cycle detected , no topological sorting" << endl;
                return 0;
            }
        }
    }

    vector<int> v;
    stack<int > s;
    bool* visited1 = new bool[n]();
    for(int i=0;i<n;i++){
        if(!visited1[i]){
            dfs(list,visited1,i,n,s);
        }
    }

    cout << "topological sort" << endl;
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    
    return 0;
}
