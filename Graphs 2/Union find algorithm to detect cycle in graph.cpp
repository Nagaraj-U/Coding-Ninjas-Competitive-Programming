//Time complexity O(N)
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
class Edge {
    public:
        int src;
        int dest;
};

int findParent(int* parent,int v){
    if(parent[v] == v){ //if parent = vertex (thats the original parent of all )
        return v;
    }
    return findParent(parent,parent[v]); 
}

void findCycle(Edge* arr,int e,int n,int* parent){
    int count = 0;
    while(e--){
        int s = arr[count].src;
        int d = arr[count].dest;
        int srcParent = findParent(parent,s);
        int destParent = findParent(parent,d);
        if(srcParent == destParent){
            cout << "graph contain cycle"<< endl;
            return;
        }
        parent[d] = srcParent;
        count++;
    }
    cout << "graph doen't contain cycle" << endl;
    return;
}


int main()
{
    printf("Hello World");
    int n;
    int e;
    cin >> n >> e;
    Edge* arr = new Edge[n]();
    for(int i=0;i<e;i++){
        int s,d;
        cin >> s >> d;
        arr[i].src = s;
        arr[i].dest = d;
    }
    
    int* parent = new int[n];
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    findCycle(arr,e,n,parent);
    return 0;
}
