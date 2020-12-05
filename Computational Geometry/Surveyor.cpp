/*
Surveyor
Send Feedback
A plot has been surveyed. Its boundary consists of segments that form a polygon. Each segment runs either North-South or East-West. Calculate the enclosed area.
The i-th character of direction and the i-th element of length describe the direction and length of the i-th segment of the polygon's boundary as the surveyor walked it. If you start at the surveyor's starting point and walk according to the sequence of directions and lengths reported by the surveyor, you will traverse the boundary of the polygon, ending up back at the starting point. This traversal described by the given segments may be either clockwise or counterclockwise.
Input Format
String s
Array of length of string
Output Format
Area
Constraints
direction will have between 4 and 50 characters inclusive.
length will have the same number of elements as the number of characters in direction.
Each element of direction will be an uppercase letter 'N', 'E', 'S', or 'W'.
Each element of length will be between 1 and 1000 inclusive.
The segments will represent a simple polygon. No two segments will touch or intersect (except that the last point of a segment is the first point of the next segment, and the last point of the final segment is the first point of the first segment).
Sample Test Case
"NWWSE"
{10,3,7,10,10}
Returns: 100


"NESWNWSW"
{20,200,30,100,20,30,10,70}
Returns: 4700
*/

#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

double farea(int n,int* arr_x,int* arr_y)
{
    double area = 0;
    for(int i=1;i<n-1;i++){
        double x1 = arr_x[i] - arr_x[0];
        double y1 = arr_y[i] - arr_y[0];
        double x2 = arr_x[i+1] - arr_x[0];
        double y2 = arr_y[i+1] - arr_y[0];
        double cp = x1*y2 - x2*y1;
        area += cp;
    }
    return abs(area/2);
}

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    int* arr = new int[len];
    for(int i=0;i<len;i++){
        cin >> arr[i];
    }
    int* x_arr = new int[len+1];
    int* y_arr = new int[len+1];
    x_arr[0] = 0;
    y_arr[0] = 0;
    for(int i=0;i<len;i++){
        if(s[i] == 'N'){
            x_arr[i+1] = x_arr[i];
            y_arr[i+1] = y_arr[i] + arr[i];
        }
        else if(s[i] == 'S'){
            x_arr[i+1] = x_arr[i];
            y_arr[i+1] = y_arr[i] - arr[i];
        }
        else if(s[i] == 'W'){
            x_arr[i+1] = x_arr[i] - arr[i];
            y_arr[i+1] = y_arr[i];
        }
        else if(s[i] == 'E'){
            x_arr[i+1] = x_arr[i] + arr[i];
            y_arr[i+1] = y_arr[i];
        }
    }
    double ans = farea(len+1,x_arr,y_arr);
    cout << (int)ans << endl;
    return 0;
}

