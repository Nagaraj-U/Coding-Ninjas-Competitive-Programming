/*
Activity Selection
Send Feedback
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4
*/


#include<bits/stdc++.h>
using namespace std;

struct Interval{
    int start;
    int end;
};

bool compare(Interval i1,Interval i2){
    return i1.end < i2.end;  //sort array of structures based on second element in array in increasing order
}

int main()
{
    int n;
    cin >> n;
    Interval* arr = new Interval[n];  
    for(int i=0;i<n;i++){
       cin >> arr[i].start;
       cin >> arr[i].end;
    }
    sort(arr,arr+n,compare);
    int count = 1;  
    int cur_end = arr[0].end;
    for(int i=1;i<n;i++){
        if(arr[i].start >= cur_end){
            count += 1;
            cur_end = arr[i].end;
        }
    }
    cout << count;
    return 0;
}
