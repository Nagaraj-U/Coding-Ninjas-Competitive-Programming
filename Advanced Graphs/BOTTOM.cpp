/*


BOTTOM
Send Feedback
We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.

Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).

Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
Input Specification
The input contains several test cases, each of which corresponds to a directed graph G. Each test case starts with an integer number v, denoting the number of vertices of G=(V,E) where the vertices will be identified by the integer numbers in the set V={1,…,v}. You may assume that 1≤v≤5000. That is followed by a non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,…,ve,we with the meaning that (vi,wi)∈E. There are no edges other than specified by these pairs. The last test case is followed by a zero.
Output Specification
For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line.
Sample Input
3 3
1 3 2 3 3 1
2 1
1 2
0
Sample Output
1 3
2
*/

#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;

stack<int> st;  
vector<int> adjList[100010];
bool visited[100010];


void dfs2(int index){
	visited[index]=true;
	for(unsigned int j=0;j<adjList[index].size();j++){
		if(!visited[adjList[index][j]]){
			dfs2(adjList[index][j]);
		}
	}
}

void dfs(int index){
	visited[index]=true;
	for(unsigned int j=0;j<adjList[index].size();j++){
		if(!visited[adjList[index][j]]){
			dfs(adjList[index][j]);
		}
	}
	st.push(index);
}
	

int main(){
	int tc;
	scanf("%d",&tc);
	while (tc--){
		memset(visited,false,sizeof(visited));
		
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			adjList[a].push_back(b);
		}
		
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				dfs(i);
			}
		}
		memset(visited,false,sizeof(visited));
		int count=0;
		while(!st.empty()){
			int index=st.top();
			st.pop();
			if(!visited[index]){
				count++;
				dfs2(index);
			}
		}
		printf("%d\n",count);
		for(int i=1;i<=n;i++){
			adjList[i].clear();
		}
	}
	return 0;
}
