/*

Problem
Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell. 
The player has total control over outcome of dice throw and wants to find out minimum number of throws required to reach last cell.

RULES :

Starting from square 1, land on square 100 with the exact roll of the die. If moving the number rolled would place the player beyond square 100, no move is made.

If a player lands at the base of a ladder, the player must climb the ladder. Ladders go up only.

If a player lands at the mouth of a snake, the player must go down the snake and come out through the tail. Snakes go down only.

 

Input Format

The first line contains the number of tests T.

For each test case: 
- The first line contains N, the number of ladders. 
- Each of the next N lines contains two space-separated integers, the start and end of a ladder. 
- The next line contains the integer M, the number of snakes. 
- Each of the next lines contains two space-separated integers, the start and end of a snake.

 

Constraints

 


The board is 10 x 10 always with squares numbered 1  to 100. 
Neither square 1 nor square 100 will be the starting point of a ladder or snake. 
A square will have at most one endpoint from either a snake or a ladder.

Output Format

For each of the t test cases, print the least number of rolls to move from start to finish on a separate line.

Sample Input
2
3
32 62
42 68
12 98
7
95 13
97 25
93 37
79 27
75 19
49 47
67 17
4
8 52
6 80
26 42
2 72
9
51 19
39 11
37 29
81 3
59 5
79 23
53 7
43 33
77 21 
Sample Output
3
5
Time Limit: 2
Memory Limit: 256
Source Limit:
Explanation
For the first test:

The player can roll a 5 and a 6  to land at square 12 . There is a ladder to square 98 . A roll of 2 ends the traverse in 3 rolls.

For the second test:

The player first rolls 5 and climbs the ladder to square 80. Three rolls 6 of get to square 98 . A final roll of 2  lands on the target square in 5 total rolls.
*/



/*
APPROACH


The idea is to consider the given snake and ladder board as a directed graph with number of vertices equal to the number of cells in the board. 
The problem reduces to finding the shortest path in a graph. Every vertex of the graph has an edge to next six vertices if next 6 vertices do not have a snake or ladder.
If any of the next six vertices has a snake or ladder, then the edge from current vertex goes to the top of the ladder or tail of the snake. Since all edges are of equal weight,
we can efficiently find shortest path using Breadth First Search of the graph.

Following is the implementation of the above idea. The input is represented by two things, first is ‘N’ which is number of cells in the given board, 
second is an array ‘move[0…N-1]’ of size N. An entry move[i] is -1 if there is no snake and no ladder from i, otherwise move[i] contains index of destination cell for the 
snake or the ladder at i.

image : https://media.geeksforgeeks.org/wp-content/uploads/snake-and-ladders.jpg

*/

#include<bits/stdc++.h>
using namespace std;

struct node{ //each node conatin min dist to reach and vertex itself
	int vertex;
	int dist;
};


//every node is connected to next 6 vertices
int getans(int* arr)
{
	bool* visited = new bool[101];
	for(int i=0;i<101;i++){
		visited[i] = false;
	}
	queue<node> q; //to apply BFS
	node temp;
	temp.vertex = 1;
	temp.dist = 0; //dist to reach 1 vertx is 0
	q.push(temp);
	while(!q.empty()){
		node curr = q.front();
		q.pop();
		if(curr.vertex == 100){
			return curr.dist;
		}
		for(int i=curr.vertex+1;i<=(curr.vertex+6)&& i<101 ;i++){
      
			if(!visited[i]){
				node insertVertex;
        
				if(arr[i] != -1){ //ladder or snake present move to respective position accordingly
					insertVertex.vertex = arr[i];
				}else{
					insertVertex.vertex = i;
				}
        
				insertVertex.dist = curr.dist + 1;
				q.push(insertVertex);
				visited[i] = true;
        
			}
		}
	}
	return 0;
}

int main()
{
	int t;
	cin >>t;
  
	while(t--){
		int n,m;
    
		cin >> n;
		int* arr = new int[101];
		for(int i=0;i<101;i++){
			arr[i] = -1;
		}
    
		while(n--){
			int idx,val;
			cin >> idx >> val;
			arr[idx] = val;
		}
    
    cin >> m;
		while(m--){
			int idx,val;
			cin >> idx >> val;
			arr[idx] = val;
		}
    
		cout << getans(arr) << endl;
	}
  
}
