#include<bits/stdc++.h>
using namespace std;



/*

NOTE : number of SCC's in undirected graph  = number on connected components

A directed graph is strongly connected if there is a path between all pairs of vertices.
A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph.

 Note : Reversing all edges in SCC , still it remains SCC

 step 1 : apply dfs push all the vertices into stack
 step 2 : reverse all the edges in the given graph
 step 3 : pop each element from stack and apply bfs on them


scc1  --->  scc2 ----> scc3 (original)
scc1  <---  scc2 <---- scc3 (reversed)

*/


//on original edges
void dfs1(vector<vector<int>> &adj,int start,vector<bool> &visited,stack<int> &st){
    visited[start] = true;
    for(int i=0;i<adj[start].size();i++){
        if(!visited[adj[start][i]]){
            dfs1(adj,adj[start][i],visited,st);
        }
    }
    st.push(start);
    return;
}

//on reversed edges
void dfs2(vector<vector<int>> &rev,int start,vector<bool> &visited){
    cout << start << " ";
    visited[start] = true;
    for(int i=0;i<rev[start].size();i++){
        if(!visited[rev[start][i]]){
            dfs2(rev,rev[start][i],visited);
        }
    }
    return;
}


//reversing
void reverseEdges(vector<vector<int>> &adj,vector<vector<int>> &rev,int n){
    for(int i=0;i<n;i++){
        if(adj[i].size() > 0){
            for(int j=0;j<adj[i].size();j++){
                rev[adj[i][j]].push_back(i);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int e;
    cin >> e;
    vector<vector<int>> adj(n);
    vector<vector<int>> rev(n);

    for(int i=0;i<e;i++){
        int src,dest;
        cin >> src >> dest;
        adj[src].push_back(dest);
    }

    vector<bool> visited(n,false);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs1(adj,i,visited,st);
        }
    }

    reverseEdges(adj,rev,n);
    for(int i=0;i<n;i++){
        visited[i] = false;
    }


    //couting all SCC's
    int count = 1;
    while(!st.empty()){
        auto curr = st.top();
        st.pop();
        if(!visited[curr]){
            cout << " SCC " << count << endl;
            count++;
            dfs2(rev,curr,visited);
        }
    }
    return 0;

}



/*
    adj[0].pb(1);
    adj[1].pb(2);
    adj[2].pb(0);
    adj[2].pb(3);
    adj[3].pb(4);
    adj[4].pb(5);
    adj[4].pb(7);
    adj[5].pb(6);
    adj[6].pb(4);
    adj[6].pb(7);

    output : 
     0 2 1
     3
     4 6 5
     7
*/
