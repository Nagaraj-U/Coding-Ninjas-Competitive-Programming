/*
Maximum Pair Sum
Send Feedback
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12
*/


#include<bits/stdc++.h>
using namespace std;

struct node{
    int maximum;
    int smaximum;
};

void updatetree(int* arr,node* tree,int start,int end,int treenode,int idx,int val){
    if(start == end){
        arr[start] = val;
        tree[treenode].maximum = val;
        tree[treenode].smaximum = INT_MIN;
        return;
    }
    int mid = (start+end)/2;
    if(idx > mid){
        updatetree(arr,tree,mid+1,end,2*treenode+1,idx,val);
    }else{
        updatetree(arr,tree,start,mid,2*treenode,idx,val);
    }
    node right = tree[2*treenode+1];
    node left = tree[2*treenode];
    
    tree[treenode].maximum = max(left.maximum,right.maximum);
    tree[treenode].smaximum = min(max(left.maximum,right.smaximum),max(left.smaximum,right.maximum));
    return;
}

void buildtree(int* arr,node* tree,int start,int end,int treenode){
    if(start == end){
        tree[treenode].maximum = arr[start];
        tree[treenode].smaximum = INT_MIN;
        return;
    }
    int mid = (start+end)/2;
    buildtree(arr,tree,start,mid,2*treenode);
    buildtree(arr,tree,mid+1,end,2*treenode+1);
    
    node left = tree[2*treenode];
    node right = tree[2*treenode+1];
    tree[treenode].maximum = max(left.maximum,right.maximum);
    tree[treenode].smaximum = min(max(left.maximum,right.smaximum),max(left.smaximum,right.maximum));
    return;
      
}

node query(node* tree,int start,int end,int treenode,int left,int right){
    
    if(start > right || end < left){
        node temp;
        temp.maximum = INT_MIN;
        temp.smaximum = INT_MIN;
        return temp;
    }
    
    if(start >= left && end <=right){
        return tree[treenode];
    }
    
    int mid = (start+end)/2;
    node first,second;
    first = query(tree,start,mid,2*treenode,left,right);
    second = query(tree,mid+1,end,2*treenode+1,left,right);
    
    node result;
    result.maximum = max(first.maximum,second.maximum);
    result.smaximum = min(max(first.maximum,second.smaximum),max(first.smaximum,second.maximum));
    return result;  
}

int main() {
    
    std::ios::sync_with_stdio(false);
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
        char type;
        cin >> type;
        if(type == 'Q'){
            int x,y;
            cin >> x >> y;
            node ans = query(tree,0,n-1,1,x-1,y-1);
            cout << (ans.maximum+ans.smaximum) << endl;
            
        }else{
            int idx,val;
            cin >> idx >> val;
            updatetree(arr,tree,0,n-1,1,idx-1,val);
        }
    }
    
    return 0;
}
