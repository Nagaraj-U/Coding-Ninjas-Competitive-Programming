/*
You are given a 2-D plane, and some N integer coordinates in the form of (X,Y), where X is the x-coordinate and Y is the y-coordinate, all of which lie on that plane.
You need to find the maximum number of coordinates among these which can form a straight line.
Note:
1. All the coordinates are integer coordinates.
2. There can be two identical coordinates.
Input Format:
The first line of the input contains an integer T, denoting the number of test cases.
The first line of each test case contains the integer N, denoting the number of points.
The next N lines of each test case contain 2 space-separated integers which represent the coordinates of a given point.
Output Format:
For each test case, every line of output prints the maximum number of points which lie on a straight line.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <=  50
1 <= N <= 10^3
-10^4 <= X, Y <= 10^4
Time Limit: 1 sec
Sample Input 1:
2
2
1 1
5 5
6
-1 -1
0 0
1 1
2 2
3 3
3 4
Sample Output 1:
2
5 

*/







#include<bits/stdc++.h>
/*
	points having same slope lie in same line

*/
int maxPointsOnLine(vector<vector<int>> &points, int n) {
    
    int overall = -1;
    for(int i=0;i<n;i++){ //finding slope of point with every other point ans storing count of how may have same slope
        int same = 0; //same X and Y points
        int sameX = 0; //same X coordinates
        int sameY = 0;
        map<double , int> m; //to store count of points having same slope
        int ans = -1; 
        for(int j=0;j<n;j++){
            if(i == j){
                continue;
            }
            if(points[i][0] == points[j][0] && points[i][1] == points[j][1]){ //adding to final answer
                same += 1;
                continue;
            }
            if(points[i][0] == points[j][0]){ //to avoid division by 0
                sameX += 1;
                continue;
            }
            if(points[i][1] == points[j][1]){
                sameY += 1;
                continue;
            }
            double long slope;
            slope = (double long)(points[i][1] - points[j][1])/(double long)(points[i][0] - points[j][0]);
            if(m.count(slope) == 0){ //not exist (2 : i,j)
                m[slope] += 2;
            }else{
                m[slope] += 1; //already exist
            }
        }
        
        for(auto i : m){
            ans = max({ans,i.second+same,sameX,sameY});
        }
        overall = max(overall,ans); //overall for outer loop
    }
    return overall;
}
