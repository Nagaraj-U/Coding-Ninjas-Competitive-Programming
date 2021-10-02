/*
Given a Directed Acyclic Graph having V vertices and E edges, where each edge {U, V} represents the Jobs U and V such that Job V can only be started 
only after completion of Job U. The task is to determine the minimum time taken by each job to be completed where each Job takes unit time to get completed.

Examples:

Input: N = 10, E = 13, Below is the given graph:

https://media.geeksforgeeks.org/wp-content/uploads/20200804212533/Semester1.png


Output: 1 1 2 2 2 3 4 5 2 6  
Explanation:
Start the jobs 1 and 2 at the beginning and complete them at 1 unit of time. 
Since, jobs 3, 4, 5, and 9 have the only dependency on one job (i.e 1st job for jobs 3, 4, and 5 and 2nd job for job 9). 
So, we can start these jobs at 1st unit of time and complete these at 2nd unit of time after the completion of the dependent Job.
Similarly, 
Job 6 can only be done after 3rd and 4th jobs are done. So, start it at 2nd unit of time and complete it at 3rd unit of time.
Job 7 can only be done after job 6 is done. So, you can start it at 3rd unit of time and complete it at 4th unit of time.
Job 8 can only be done after 4th, 5th, and 7th jobs are done. So, start it at 4th unit of time and complete it at 5th unit of time.
Job 10 can only be done after the 8th job is done. So, start it at 5th unit of time and complete it at 6th unit of time.




Input: N = 7, E = 7, Below is the given graph:



Output: 1 2 3 3 3 4 4  
Explanation:
Start the Job 1 at the beginning and complete it at 1st unit of time.
The job 2 can only be done after 1st Job is done. So, start it at 1st unit of time and complete it at 2nd unit of time.
Since, Job 3, 4, and 5 have the only dependency on 2nd Job. So, start these jobs at 2nd unit of time and complete these at 3rd unit of time.
The Job 6 can only be done after the 3rd and 4th Job is done. So, start it at 3rd unit of time and complete it at 4th unit of time.
The Job 7 can only be done after the 5th Job is done. So, start it at 3rd hour and complete it at 4th unit of time.
*/

//maintain indegree array which stores count of incoming edges
//only when indegree[i] becomes 0 , then only push node to queue (which means all of its parent tasks are done)
//do level order traversal

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int e;
    cin >> e;
    vector<vector<int>> adj(n);
    vector<int> indegree(n,0);
    for(int i=0;i<e;i++){
        int start,end;
        cin >> start >> end;
        adj[start].push_back(end);
        indegree[end]++;
    }
    int timer = 0;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<pair<int,int>> pp;
    while(!q.empty()){
        timer++;
        int size = q.size();
        for(int j=0;j<size;j++){
            auto curr = q.front();
            q.pop();
            pp.push_back({curr,timer});
            for(int i=0;i<adj[curr].size();i++){
                indegree[adj[curr][i]]--;
                if(indegree[adj[curr][i]] == 0){
                    q.push(adj[curr][i]);
                }
            }
        }
    }
    for(int i=0;i<pp.size();i++){
        cout << " job " << pp[i].first << " time " << pp[i].second << endl;
    }
    //cout << timer << endl;

}

/*
10
13
0 2
0 3
0 4
1 3
1 8
2 5
3 5
3 7
4 7
1 7
5 6
6 7
7 9
 job 0 time 1
 job 1 time 1
 job 2 time 2
 job 4 time 2
 job 3 time 2
 job 8 time 2
 job 5 time 3
 job 6 time 4
 job 7 time 5
 job 9 time 6
*/
