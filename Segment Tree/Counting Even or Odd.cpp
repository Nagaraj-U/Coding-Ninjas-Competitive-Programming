/*
Counting Even/Odd
Send Feedback
Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
Input:
First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9
Note:-
indexing starts from 1.
Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output
2
2
4
*/






#include<bits/stdc++.h>
using namespace std;

struct node{
    int even;
    int odd;
};

void buildtree(int* arr,node* tree,int start,int end,int treenode){
    if(start == end){
        if(arr[start] % 2 == 0){
            tree[treenode].even = 1;
            tree[treenode].odd = 0;
        }else{
            tree[treenode].odd = 1;
            tree[treenode].even = 0;
        }
        return;
    }
    
    int mid = (start+end)/2;
    buildtree(arr,tree,start,mid,2*treenode);
    buildtree(arr,tree,mid+1,end,2*treenode+1);
    
    tree[treenode].even = tree[2*treenode].even + tree[2*treenode+1].even;
    tree[treenode].odd = tree[2*treenode].odd + tree[2*treenode+1].odd;
    return;
}

void update(int* arr,node* tree,int start,int end,int treenode,int idx,int val){
    if(start == end){
        arr[start] = val;
        if(val % 2 == 0){
            tree[treenode].even = 1;
            tree[treenode].odd = 0;
        }else{
            tree[treenode].odd = 1;
            tree[treenode].even = 0;
        }
        
        return;
    }
    int mid = (start+end)/2;
    if(idx > mid){
        update(arr,tree,mid+1,end,2*treenode+1,idx,val);
    }else{
        update(arr,tree,start,mid,2*treenode,idx,val);
    }
    
    tree[treenode].even = tree[2*treenode].even + tree[2*treenode+1].even;
    tree[treenode].odd = tree[2*treenode].odd + tree[2*treenode+1].odd;
    return;
    
}


node query(node* tree,int start,int end,int treenode,int left,int right){
    
    if(start > right || end < left){
        return {0,0};
    }
    
    if(start >= left && end <= right){
        return tree[treenode];
    }
    
    int mid = (start+end)/2;
    node first = query(tree,start,mid,2*treenode,left,right);
    node second = query(tree,mid+1,end,2*treenode+1,left,right);
    node res;
    res.even = first.even + second.even;
    res.odd = first.odd + second.odd;
    
    return res;
}

int main() {

	int n;
    cin >> n;
    int* arr = new int[n];
    node* tree = new node[4*n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    buildtree(arr,tree,0,n-1,1);
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int left,right;
            cin >> left >> right;
            node ans = query(tree,0,n-1,1,left-1,right-1);
            cout << ans.even << endl;
        }else if(type == 2){
            int left,right;
            cin >> left >> right;
            node ans = query(tree,0,n-1,1,left-1,right-1);
            cout << ans.odd << endl;
        }else{
            int idx,val;
            cin >> idx >> val;
            update(arr,tree,0,n-1,1,idx-1,val);
        }
    }
    return 0;
}
