/*
Problem Description

Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

Where:

A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done.



Problem Constraints
1 <= N <= 10

0 <= A[i][0] < A[i][1] <= 2 * 109



Input Format
The only argument given is the matrix A.



Output Format
Return the minimum number of conference rooms required so that all meetings can be done.



Example Input
Input 1:

 A = [      [0, 30]
            [5, 10]
            [15, 20]
     ]

Input 2:

 A =  [     [1, 18]
            [18, 23]
            [15, 29]
            [4, 15]
            [2, 11]
            [5, 13]
      ]


Example Output
Output 1:

 2
Output 2:

 4


Example Explanation
Explanation 1:

 Meeting one can be done in conference room 1 form 0 - 30.
 Meeting two can be done in conference room 2 form 5 - 10.
 Meeting one can be done in conference room 2 form 15 - 20 as it is free in this interval.
Explanation 2:

 Meeting one can be done in conference room 1 from 1 - 18.
 Meeting five can be done in conference room 2 from 2 - 11.
 Meeting four can be done in conference room 3 from 4 - 15.
 Meeting six can be done in conference room 4 from 5 - 13.
 Meeting three can be done in conference room 2 from 15 - 29 as it is free in this interval.
 Meeting two can be done in conference room 4 from 18 - 23 as it is free in this interval.

*/


//find the index in departure array such that departure[index] <= arrival[i]
int binary_search(int* departure,int key,int start,int end,int n){
    int index = -1;
    while(start <= end){
        int mid = (start+end)/2;
        if(departure[mid] <= key){
            index = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return index;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int* arrival = new int[n];
    int* departure = new int[n];
    for(int i=0;i<n;i++){
        arrival[i] = A[i][0];
        departure[i] = A[i][1];
    }
    if(n==1){
        return 1;
    }
    sort(arrival,arrival+n);
    sort(departure,departure+n);
    int max_rooms = 1;
    for(int i=1;i<n;i++){
        int index = binary_search(departure,arrival[i],0,i-1,n);

        if(index != -1){//there are some empty conference halls , during this arrival[i]
            max_rooms = max(max_rooms,i-index);
        }else{//all are fully occupied
            max_rooms = max(max_rooms,i+1);
        }
    }

    return max_rooms;
}
