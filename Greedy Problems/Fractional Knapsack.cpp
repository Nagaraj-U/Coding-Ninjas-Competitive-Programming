/*
Fractional Knapsack
Send Feedback
You want to paint your house. The total area of your house is D units. There are a total of N workers. The ith worker is available after time Ti, has hiring cost Xi and speed Yi. This means he becomes available for hiring from time Ti and remains available after that. Once available, you can hire him with cost Xi, after which he will start painting the house immediately, covering exactly Yi units of house with paint per time unit. You may or may not hire a worker and can also hire or fire him at any later point of time. However, no more than 1 worker can be painting the house at a given time.
Since you want the work to be done as fast as possible, figure out a way to hire the workers, such that your house gets painted at the earliest possible time, with minimum cost to spend for hiring workers.
Note: You can hire a previously hired worker without paying him again.
Input
The first line of input contains two integers "N D", the number of workers and the area of your house respectively. The ith of the next N lines denotes the ith worker, and contains three integers "Ti Xi Yi", described in the statement.
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
struct Worker{
    int t;
    int x;
    int y;
    
};

bool compare(Worker w1,Worker w2){
    if(w1.t == w2.t){
        if(w1.y == w2.y){
            return w1.x<w2.x;
        }
        return w1.y>w2.y;
    }
    return w1.t<w2.t;
}

ll mincost(Worker* arr,int n,ll d){
    int cur_index = 0;
	ll area_covered = 0;
    ll cost = arr[0].x;
    for(int i=1; i<n  ;i++){
        area_covered += (arr[i].t - arr[i-1].t)*(arr[cur_index].y);
        if(area_covered >= d){
            return cost;
        }
        if(arr[cur_index].y < arr[i].y){
            cur_index = i;
            cost += arr[cur_index].x;
        }
    }
    return cost;
}

int main()
{
    int n;
    ll d;
    cin >> n >> d;
    Worker* arr = new Worker[n];
    for(int i=0;i<n;i++){
        cin >> arr[i].t;
        cin >> arr[i].x;
        cin >> arr[i].y;
    }
    sort(arr,arr+n,compare);
    cout << mincost(arr,n,d);
    return 0;
}
