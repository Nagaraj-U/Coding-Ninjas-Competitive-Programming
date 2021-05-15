/*
Fractional Knapsack

Send Feedback
You want to paint your house. The total area of your house is D units. There are a total of N workers. The ith worker is available after time Ti, has hiring cost Xi and 
speed Yi. This means he becomes available for hiring from time Ti and remains available after that. Once available, you can hire him with cost Xi, after which he will start
painting the house immediately, covering exactly Yi units of house with paint per time unit. You may or may not hire a worker and can also hire or fire him at any later point
of time. However, no more than 1 worker can be painting the house at a given time.
Since you want the work to be done as fast as possible, figure out a way to hire the workers, such that your house gets painted at the earliest possible time, with minimum cost
to spend for hiring workers.
Note: You can hire a previously hired worker without paying him again.
Input
The first line of input contains two integers "N D", the number of workers and the area of your house respectively. The ith of the next N lines denotes the ith worker,
and contains three integers "Ti Xi Yi", described in the statement.
Output
Output one integer, the minimum cost that you can spend in order to get your house painted at the earliest.
Constraints
1 ≤ N, T, X, Y ≤ 10^5
1 ≤ D ≤ 10^11
Sample Input
3 3
1 1 1
2 2 2
3 1 5
Sample Output
3
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class worker{
    public:
    	int time;
        int cost;
    	int speed;
};

bool compare(worker w1,worker w2)
{
    if(w1.time == w2.time){
        if(w1.speed == w2.speed){
            return w1.cost < w2.cost;
        }
        return w1.speed > w2.speed;
    }
    
    return w1.time < w2.time;
}

int getans(worker* arr,ll d,int n)
{
    
    int total_cost = arr[0].cost;
    worker curr_work = arr[0];
    ll total_area = curr_work.speed;
    for(int i=1;i<n;i++){
        if(total_area >= d){
            break;
        }
        if(curr_work.speed >= arr[i].speed){
            total_area += curr_work.speed;
        }else{
            curr_work = arr[i];
            total_area += curr_work.speed;
            total_cost += curr_work.cost;
        }
    }
    return total_cost;
}

int main()
{
    //Write your code here
    int n;
    ll d;
    cin >> n >> d;
    worker* arr = new worker[n];
    for(int i=0;i<n;i++){
        int t,x,y;
        cin >> t >> x >> y;
        arr[i].time = t;
        arr[i].cost = x;
        arr[i].speed = y;
    }
    sort(arr,arr+n,compare);
    cout << getans(arr,d,n);
    return 0;
}
