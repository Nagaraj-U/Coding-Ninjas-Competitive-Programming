//sum of array elements

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void buildtree(int* arr,int* tree,int start,int end,int treenode){
    if(start == end){
        tree[treenode] = arr[start];
        return;
    }
    int mid = (end + start)/2;
    buildtree(arr,tree,start,mid,2*treenode);
    buildtree(arr,tree,mid+1,end,2*treenode+1);
    tree[treenode] = tree[2*treenode] + tree[2*treenode+1];
    return;
}


void updatetree(int* arr,int* tree,int start,int end,int treenode,int idx,int val){
    if(start == end){
        arr[idx] = val;
        tree[treenode] = val; 
        return;
    }

    int mid = (end+start)/2;
    if(idx > mid){
        updatetree(arr,tree,mid+1,end,2*treenode+1,idx,val);
    }else{
        updatetree(arr,tree,start,mid,2*treenode,idx,val);
    }
    tree[treenode] = tree[2*treenode+1] + tree[2*treenode];
    return;
}




int query(int* tree,int start,int end,int treenode,int left,int right){
    //compeletely outside given range
    if(start > right || end < left){
        return 0;
    }

    //compeletely inside given range
    if(start >= left && end <= right){
        return tree[treenode];
    }

    //partialy inside or partially outside given range

    int mid = (start+end)/2;
    int ans1 = query(tree,start,mid,2*treenode,left,right);
    int ans2 = query(tree,mid+1,end,2*treenode+1,left,right);
    return ans1+ans2;

}

int main(){
    int n;
    cout << "enter size of array" << endl;
    cin >> n;
    int* arr = new int[n];
    int* tree = new int[4*n];
    int* lazy = new int[4*n]();
    for(int i=0;i<n;i++){
        arr[i] = i+1;
    }
    buildtree(arr,tree,0,n-1,1);

    int idx,val;
     cout << "enter index and value to updated" << endl;
    cin >> idx;
    cin >> val;
   
    updatetree(arr,tree,0,n-1,1,idx,val);

    int ans = query(tree,0,4,1,2,4);//ans from range 2-4 
    cout << "query ans is " << ans << endl;
    return 0;
}
