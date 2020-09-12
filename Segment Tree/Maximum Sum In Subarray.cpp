/*
Maximum Sum In Subarray
Send Feedback
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one 
query per line.
Sample Input:
3 
-1 2 3 
1
1 2
Sample Output:
2
*/


#include<bits/stdc++.h>
using namespace std;


struct node{
    int sum;//total sum of interval
    int maxsum;//max subarray sum in left or right
    int BSsum;//best prefix sum
    int BPsum;//best suffix sum
};

void buildtree(int*arr,node*tree,int start,int end,int treenode){
    if(start == end){
        tree[treenode].sum = arr[start];
        tree[treenode].maxsum = arr[start];
        tree[treenode].BPsum = arr[start];
        tree[treenode].BSsum = arr[start];
        return;
    }
    
    int mid = (start+end)/2;
    buildtree(arr,tree,start,mid,2*treenode);
    buildtree(arr,tree,mid+1,end,2*treenode+1);

    
    tree[treenode].BPsum = max(tree[2*treenode].BPsum , tree[2*treenode].sum+tree[2*treenode+1].BPsum);
    tree[treenode].BSsum = max(tree[2*treenode+1].BSsum, tree[2*treenode+1].sum + tree[2*treenode].BSsum);
    tree[treenode].sum = tree[2*treenode].sum + tree[2*treenode+1].sum;
    tree[treenode].maxsum = max(tree[2*treenode].maxsum, 
                               max(tree[2*treenode+1].maxsum, 
                                  max(tree[2*treenode].sum + tree[2*treenode+1].BPsum, 
                                     max(tree[2*treenode+1].sum + tree[2*treenode].BSsum, 
                                         tree[2*treenode].BSsum + tree[2*treenode+1].BPsum))));
    
    return;
}

node query(node* tree,int start,int end,int treenode,int left,int right){
    
    //completely outside
    if(start > right || end < left){
        node temp;
        temp.sum = -100000;
        temp.maxsum = -100000;
        temp.BSsum = -100000;
        temp.BPsum = -100000;
        return temp;
    }
    
    //completely inside
    if(start >= left && end <= right){
        return tree[treenode];
    }
    
    //partially inside or partially outside
    int mid = (start+end)/2;
    node first = query(tree,start,mid,2*treenode,left,right);
    node second = query(tree,mid+1,end,2*treenode+1,left,right);
    node result;
    
    result.sum = first.sum + second.sum;
    result.BPsum = max(first.BPsum, first.sum + second.BPsum);
    result.BSsum = max(second.BSsum, second.sum + first.BSsum);
    result.maxsum = max(first.maxsum, 
                       max(second.maxsum, 
                          max(first.sum + second.BPsum, 
                            max(second.sum + first.BSsum, first.BSsum + second.BPsum))));
    return result;
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
        int left,right;
        cin >> left >> right;
        node ans = query(tree,0,n-1,1,left-1,right-1);
        cout << ans.maxsum << endl;
    }
    return 0;
}
