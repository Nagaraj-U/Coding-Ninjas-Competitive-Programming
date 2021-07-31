/*
Job Sequencing Problem 
Medium Accuracy: 48.94% Submissions: 35056 Points: 4
Given a set of N jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to complete and
only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. 
The task is to find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which 
takes an integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)


Constraints:
1 <= N <= 105
1 <= Deadline <= 100
1 <= Profit <= 500
*/

bool compare(Job j1,Job j2){
    if(j1.profit == j2.profit){
        return j1.dead < j2.dead;
    }
    return j1.profit > j2.profit;
}


class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int> ans;
        
        int count = 0;
        int profit = 0;
        int max_dead = INT_MIN;
        sort(arr,arr+n,compare);
        
        for(int i=0;i<n;i++){
            max_dead = max(max_dead,arr[i].dead);
        }
        vector<int> visited(max_dead + 1 , -1);
        
        
        //allocate the current job to larget possible time near time to deadline so other jobs can be included 
        for(int i=0;i<n;i++){
            
            if(visited[arr[i].dead] == -1){
                count++;
                profit += arr[i].profit;
                visited[arr[i].dead] = arr[i].id;
            }else{
                int j = arr[i].dead;//check for nearest maximim slot
                while(j>=1){
                    if(visited[j] == -1){
                        visited[j] = arr[i].id;
                        count++;
                        profit += arr[i].profit;
                        break;
                    }
                    j--;
                }
            }
            
        }
        ans.push_back(count);
        ans.push_back(profit);
        return ans;
        
    } 
};
