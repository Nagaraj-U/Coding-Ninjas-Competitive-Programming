/*


Convex Hull
Send Feedback
Given a set of points in the plane. the convex hull of the set is the smallest convex polygon that contains all the points of it.
Find out the convex hull for the given set of points.
Input Format
Integer N(Number Of points)
Array of X coordinates
Array of Y coordinates
Output Format
X coordinate and Y coordinate of all the points seperated by space. Order doesn't matter.
Sample Testcase
Input
7
2 1 6 5 3 7 9
2 5 1 5 7 6 4
Output
1 5
2 2
6 1
9 4
7 6
3 7
*/


#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
};

bool toChange(Point p,Point q,Point r){
    int x1 = q.x - p.x;
    int y1 = q.y - p.y;
    int x2 = r.x - q.x;
    int y2 = r.y - q.y;
    int ans = 0;
    ans = x1*y2 - x2*y1;
    return ans > 0; //return ans < 0
}

void convexHull(Point* arr,int n){
    vector<Point> hull;
    int left = 0;
    for(int i=1;i<n;i++){
        if(arr[i].x < arr[left].x){
            left = i;
        }
    }
    int p = left;
    
    do{
        hull.push_back(arr[p]);
        int q = (p+1)%n;
        for(int i=0;i<n;i++){
            if(toChange(arr[p],arr[q],arr[i])){
                q = i;
            }
        }
        p = q;
    }while(p != left);
        
    for(int i=0;i<hull.size();i++){
        cout << hull[i].x << " " << hull[i].y << endl;
    }
    return;
    
}

int main() {

	// Write your code here
    int n;
    cin >> n;
    int* arr_x = new int[n];
    int* arr_y = new int[n];
    Point* points = new Point[n];
    for(int i=0;i<n;i++){
        cin >> arr_x[i];
    }
    for(int i=0;i<n;i++){
        cin >> arr_y[i];
    }
    for(int i=0;i<n;i++){
        points[i].x = arr_x[i];
        points[i].y = arr_y[i];
    }
    convexHull(points,n);
    return 0;
}


