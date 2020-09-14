/*
Horrible Queries
Send Feedback
World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.

1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
Input
In the first line you'll be given T, number of test cases.

Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p, q <= N and 1 <= v <= 10^7.
Output
Print the answers of the queries.
Input:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8
Output:
80  
508
*/



#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void update(ll* tree,ll* lazy,ll start,ll end,ll treenode,ll left,ll right,ll val){
    if(start > end){
        return;
    }
    
    if(lazy[treenode] != 0){
        tree[treenode] += (end - start + 1) * lazy[treenode];  //multiplying coz adding element to each element of aray
        if(start != end){  //child exist
            lazy[2*treenode] += lazy[treenode];
            lazy[2*treenode+1] += lazy[treenode];
        }
        lazy[treenode] = 0; //after adding make lazy node to zero
    }
    
    if(start > right || end < left){ //outside
        return;
    }
    
    if(start >= left && end <= right){  //inside
        tree[treenode] += (end-start+1)*val;  
        if(start !=  end){
            lazy[2*treenode] += val;
            lazy[2*treenode+1] += val;
        }
        return;
    }
    
    ll mid = (start+end)/2;
    update(tree,lazy,start,mid,2*treenode,left,right,val);
    update(tree,lazy,mid+1,end,2*treenode+1,left,right,val);
    ll first = tree[2*treenode];
    ll second = tree[2*treenode+1];
    tree[treenode] = first+second;
    return;
}

ll query(ll *tree,ll* lazy,ll start,ll end,ll treenode,ll left,ll right){
    if(start > end){
        return 0;
    }
    
    if(lazy[treenode] != 0){
        tree[treenode] += (end-start+1)*lazy[treenode];
        if(start != end){
            lazy[2*treenode] += lazy[treenode];
            lazy[2*treenode+1] += lazy[treenode];
        }
        lazy[treenode] = 0;
    }
    
    if(start > right || end < left){
        return 0;
    }
    
    if(start >= left && end <= right){
        return tree[treenode];
    }
    
    ll mid = (start+end)/2;
    ll first = query(tree,lazy,start,mid,2*treenode,left,right);
    ll second = query(tree,lazy,mid+1,end,2*treenode+1,left,right);
    
    return first+second;
    
}

int main() {

	int t;
    cin >> t;
    while(t--){
        ll n,q;
        cin >> n >> q;
        ll* tree = new ll[4*n]();
        ll* lazy = new ll[4*n]();
        //not building tree coz intially array elements are all zeros hence tree nodes are intialized to zero
        while(q--){
            ll type;
            cin >> type;
            if(type == 0){
                ll left,right,val;
                cin >> left >> right >> val;
                update(tree,lazy,0,n-1,1,left-1,right-1,val);
            }else{
                ll left,right;
                cin >> left >> right;
                cout << query(tree,lazy,0,n-1,1,left-1,right-1) << endl;
            }
        }
    }
    return 0;
}

