/*

Given a n*m grid and the position of some poles to be painted in the grid, the task is to find the minimum cost to paint all the poles. 
There is no cost involved in moving from the one row to the other, whereas moving to an adjacent column has 1 rupee cost associated with it.

Examples:

Input: n = 2, m = 2, noOfPos = 2
pos[0] = 0, 0
pos[1] = 0, 1

Output: 1
The grid is of 2*2 size and there are two poles at {0, 0} and {0, 1}. 
So we will start at {0, 0} and paint the pole and then go to
the next column to paint the pole at {0, 1} position which will
cost 1 rupee to move one column. 

Input: n = 2, m = 2, noOfPos = 2
pos[0] = {0, 0}
pos[1] = {1, 0}
Output: 0
Both poles are in the same column. So, no need to move to another column






Approach: As there is the only cost of moving in columns therefore if we go to any column we will paint all the poles in that column and then move forward.
So basically the answer will be the difference between the two farthest columns
*/



#include<bits/stdc++.h>
using namespace std;

void find(int n,int m,int p,int q[][2])
{
  	int maxCol = -1;
  	int minCol = 10000;
	for(int i=0;i<n;i++){
    	maxCol = max(maxCol,q[i][1]);
      	minCol = min(minCol,q[i][1]);
    }
  	cout << maxCol - minCol << endl;
  
}

int main()
{
  int n = 2;
  int m = 2;
  int p = 2;

  int q[2][2] = {{0,0},{0,1}} ;

  find(n, m, p, q);

  return 0;

}
