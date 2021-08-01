/*
M-Coloring Problem 
Medium Accuracy: 47.46% Submissions: 16081 Points: 4
Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that
no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices.
Print 1 if it is possible to colour vertices and 0 otherwise.

Example 1:

Input:
N = 4
M = 3
E = 5
Edges[] = {(1,2),(2,3),(3,4),(4,1),(1,3)}
Output: 1
Explanation: It is possible to colour the
given graph using 3 colours.
Example 2:

Input:
N = 3
M = 2
E = 3
Edges[] = {(1,2),(2,3),(1,3)}
Output: 0
Your Task:
Your task is to complete the function graphColoring() which takes the 2d-array graph[], the number of colours and the number of nodes as inputs and
returns true if answer exists otherwise false. 1 is printed if the returned value is true, 0 otherwise. The printing is done by the driver's code.
Note: In the given 2d-array graph[], if there is an edge between vertex X and vertex Y graph[] will contain 1 at graph[X-1][Y-1], else 0. In 2d-array graph[ ], 
nodes are 0-based indexed, i.e. from 0 to N-1.

Expected Time Complexity: O(MN).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 20
1 <= E <= (N*(N-1))/2
1 <= M <= N

Note: The given inputs are 1-base indexed but you have to consider the graph given in the adjacency matrix/list as 0-base indexed.
*/



//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.




//NOTE : graph is a adjacency matrix (0 index based)
bool isSafe(bool graph[][101],vector<int> &color,int c,int start,int n){
    
    for(int i=0;i<n;i++){//check (current node) row and its neighbours in adjacency matrix
        if(i != start and graph[start][i] == 1){//there exist edge checking
            if(color[i] == c){//current color is already assigned
                return false;
            }
        }
    }
    
    return true;
}

bool helper(bool graph[101][101],int start,int n,int m,vector<int> &color){
    
    if(start == n){
        return true;
    }
    
    for(int i=0;i<m;i++){
        if(isSafe(graph,color,i,start,n)){//checking adjacent nodes to check wether they have same color asssigned
            int temp = color[start];
            color[start] = i;//assign color
            if(helper(graph,start+1,n,m,color)){
                return true;
            }
            color[start] = temp;//back track to prev color
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int v)
{
    // your code here
    vector<int> color(v,-1);//which stores color assigned to each node
    return helper(graph,0,v,m,color);
}
