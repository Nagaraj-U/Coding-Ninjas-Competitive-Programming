#include<bits/stdc++.h>
using namespace std;

//union find algorithm


int getparent(int v,int* parent)
{
	if(v == parent[v]){
		return v;
	}
	return getparent(parent[v],parent);
}

int main()
{
	int n,e;
	cin >> n >> e;
	int** arr = new int*[n]();
	for(int i=0;i<n;i++){
		arr[i] = new int[n];
	}

	int* parent = new int[n];
	for(int i=0;i<n;i++){
		parent[i] = i;
	}

	for(int i=0;i<e;i++){
		int start,end;
		cin >> start >> end;
		int startParent = getparent(start,parent);
		int endParent = getparent(end,parent);
		if(startParent == endParent){
			cout << "cycle detected" << endl;
			return 0;
		}else{
			parent[endParent] = startParent;  //make common parent
		}
		arr[start][end] = 1;
		arr[end][start] = 1;
	}

	cout << "No cycle detected" << endl;
	return 0;
}
