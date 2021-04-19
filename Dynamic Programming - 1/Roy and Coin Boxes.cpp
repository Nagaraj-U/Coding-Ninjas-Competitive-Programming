/*

Roy and Coin Boxes
Send Feedback
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.
Input
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a
Output
For each query output the result in a new line.
Constraints
1 ≤ N ≤ 1000000

1 ≤ M ≤ 1000000

1 ≤ L ≤ R ≤ N

1 ≤ Q ≤ 1000000

1 ≤ X ≤ N
Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4
*/



#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    int* box = new int[n+1](); //dp array
	int* start = new int[n+1]();
    int* end = new int[n+1]();
    int m;
    cin >> m;
    while(m--){
        int l,r;
        cin >> l >> r;
        start[l] += 1;
        end[r] += 1;
    }
    box[1] = (start[1] - end[1]);
    /*
    	for box 1 = (s1)
        for box 2 = (s1 + s2 -e1) = s2 - e1 - box1
        for box 3 = s1 + s2 + s3 - e1 - e2 = s3 - e2 - box2
    */
    for(int i=2;i<=n;i++){
        box[i] = box[i-1] + (start[i] - end[i-1]); //starting with that index and ending at prev inde
    }
    int* ans = new int[n+1]();
    for(int i=1;i<=n;i++){
        ans[box[i]] += 1;
    }
    // cout << "box " << endl;
    // for(int i=1;i<=n;i++){
    //     cout << box[i] << " " ;
    // }
    
    //suffix sum (atleast X)
    for(int i=n-1;i>0;i--){
        ans[i] = ans[i] + ans[i+1];
    }
    // cout << "ans" << endl;
    // for(int i=1;i<=n;i++){
    //     cout << ans[i] << " " ;
    // }
    int q;
    cin >> q;
    while(q--){
        int temp;
        cin >> temp;
        cout << ans[temp] << endl;
    }
    
    
    
    return 0;
}
