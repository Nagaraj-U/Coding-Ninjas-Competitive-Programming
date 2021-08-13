/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight 
from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation: The graph is shown.
The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation: The graph is shown.
The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 

Constraints:

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst

*/



class Solution {
public:
    
    void helper(int** arr,bool* visited,int src,int dest,int k,int &fare,int n,int tempFare)
    {
        if(k==0){
            return;
        }
        if(src == dest){
            fare = min(fare,tempFare);
            return;
        }
        
        visited[src] = true;
        for(int i=0;i<n;i++){
            if(!visited[i] && arr[src][i] != 0 && arr[src][i]+tempFare < fare){ //make call if better fare exist
                helper(arr,visited,i,dest,k-1,fare,n,tempFare+arr[src][i]);
            }
        }
        visited[src] = false;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int fare = INT_MAX;
        int** arr = new int*[n]();
        for(int i=0;i<n;i++){
            arr[i] = new int[n];
            for(int j=0;j<n;j++){
                arr[i][j] =  0;
            }
        }
        for(int i=0;i<flights.size();i++){
            int src = flights[i][0];
            int dest = flights[i][1];
            int cost = flights[i][2];
            arr[src][dest] = cost;
        }
        bool* visited = new bool[n]();
        int temp = 0;
        helper(arr,visited,src,dst,k+2,fare,n,temp); //k+2 , we making k-1 for source and destination (actual K : intermidiate nodes excluding src and dest )
        if(fare == INT_MAX){
            return -1;
        }
        return fare;
    }
};
