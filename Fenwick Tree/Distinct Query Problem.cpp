/*
Distinct Query Problem
Send Feedback
Given a sequence of n numbers a1, a2, ..., an and a number of d-queries. A d-query is a pair (i, j) (1 ≤ i ≤ j ≤ n). For each d-query (i, j), you have to return the number of distinct elements in the subsequence ai, ai+1, ..., aj.
Input
Line 1: n (1 ≤ n ≤ 30000).
Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^6).
Line 3: q (1 ≤ q ≤ 200000), the number of d-queries.
In the next q lines, each line contains 2 numbers i, j representing a d-query (1 ≤ i ≤ j ≤ n).
Output
For each d-query (i, j), print the number of distinct elements in the subsequence ai, ai+1, ..., aj in a single line.
Sample Input
5
1 1 2 1 3
3
1 5
2 4
3 5
Sample Output
3
2
3 
*/
#include <bits/stdc++.h>
using namespace std;

struct node{
    int first;
    int second;
    int index; //since we sorting order changes hence maintain index
};

bool compare(node a,node b){
    return a.second < b.second; //sorting on basis of end index
}

void update(int index,int val,int n,int* BIT){
    for(;index<=n;index+=(index&(-index))){
        BIT[index] += val;  //updating value with  1 if value is distinct -1 if value already present
    }
}

int query(int index,int* BIT){
    int count = 0;
    for(;index>0;index-=(index&(-index))){
        count += BIT[index];
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n+1];
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    int q;
    cin >> q;
    node* event = new node[q];
    
    int* BIT = new int[30001]; //each node represents number of distinct elements from 0 to that node
    int* ans = new int[q];  //storing answers first later answering(offline programming)
    
    int* last = new int[1000001];//each index represents what is the last index that arr[i] has occured before 
    for(int i=0;i<1000001;i++){
        last[i] = -1;
    }
    
    for(int i=0;i<q;i++){
        cin >> event[i].first >> event[i].second;
        event[i].index = i;
    }
    sort(event,event+q,compare);
    
    int total = 0;//total counts all distinct elements from start
    int k = 0;
    for(int i=1;i<=n;i++){
        if(last[arr[i]] != -1){ //element already present
            update(last[arr[i]],-1,n,BIT); //In BIT we decreasing count by -1 to index which arr[i] has present before
        }else{
            total++;//if its distinct
        }
        
        update(i,1,n,BIT); //updating index by 1
        last[arr[i]] = i; //marking last[arr[i]] for next use
        
        while(k<q && event[k].second == i){ //checking for all queries which have same last index and storing results
            ans[event[k].index] = total - query(event[k].first-1,BIT); //if (2,5)  = total - (0,1)
            k++;
        }   
    }
    
    for(int i=0;i<q;i++){
        cout << ans[i] << endl;
    }
    return 0;
}


