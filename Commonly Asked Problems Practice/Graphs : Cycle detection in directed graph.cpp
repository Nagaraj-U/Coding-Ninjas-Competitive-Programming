#include<bits/stdc++.h>
using namespace std;


bool isCycle(int** arr,int n,int start,bool* visited,bool* recursive_stack)
{
	visited[start] = true;
	recursive_stack[start] = true;
	for(int i=0;i<n;i++){
		if(!visited[i] && arr[start][i] == 1 && isCycle(arr,n,i,visited,recursice_stack)){ 
			return true;
		}else if(arr[start][i] == 1 && recursive_stack[i]){ //there exist edge but , vertex is already present in stack
			return true; //cycle present
		}
	}
	recursive_stack[start] = false; //vertex pop off from recursive call , no more adjacent vertex present
	return false;
}

int main()
{
	int n,e;
	cin >> n >> e;
	int** arr = new int*[n]();
	for(int i=0;i<n;i++){
		arr[i] = new int[n];
	}
	for(int i=0;i<e;i++){
		int start,end;
		cin >> start >> end;
		arr[start][end] = 1;
	}
	bool* visited = new bool[n]();
	bool* recursive_stack = new bool[n]();
	for(int i=0;i<n;i++){
		if(!visited[i]){
			if(isCycle(arr,n,i,visited,recursive_stack)){
				cout << " cycle detected" << endl;
				return 0;
			}
		}
	}

	cout << "no cycle " << endl;

	return 0;
}

/*
6 7
0 1
1 2
2 3
0 3
2 4
4 5
5 2
 cycle detected
 
 
 
 6 7
0 1
1 2
2 3
0 3
2 4
4 5
2 5
no cycle

*/
