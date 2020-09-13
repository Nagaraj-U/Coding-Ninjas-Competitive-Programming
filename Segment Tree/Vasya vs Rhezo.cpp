/*
Vasya vs Rhezo
Send Feedback
Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.
Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
Constraints:
1≤ N,Q ≤10^6
1≤ Ai,Bi ≤10^9
1≤Li≤Ri
Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output
2
2
4
5
*/


#include<bits/stdc++.h>
using namespace std;

struct warrior{
    int a;
    int b;
};

struct node{
    int a;
    int b;
    int index;
};

void buildtree(warrior* arr,node* tree,int start,int end,int treenode){
    if(start == end){
        tree[treenode].a = arr[start].a;
        tree[treenode].b = arr[start].b;
        tree[treenode].index = start;
        return;
    }
    
    int mid = (start+end)/2;
    buildtree(arr,tree,start,mid,2*treenode);
    buildtree(arr,tree,mid+1,end,2*treenode+1);
    
    node left = tree[2*treenode];
    node right = tree[2*treenode+1];
    if(left.a > right.a){
        tree[treenode].a = left.a;
        tree[treenode].b = left.b;
        tree[treenode].index = left.index;
    }else if(right.a > left.a){
        tree[treenode].a = right.a;
        tree[treenode].b = right.b;
        tree[treenode].index = right.index;
    }else{
        if(left.b < right.b){
            tree[treenode].a = left.a;
            tree[treenode].b = left.b;
            tree[treenode].index = left.index;
        }else if(right.b < left.b){
            tree[treenode].a = right.a;
            tree[treenode].b = right.b;
            tree[treenode].index = right.index;
        }else{
            if(left.index < right.index){
                tree[treenode].a = left.a;
                tree[treenode].b = left.b;
                tree[treenode].index = left.index;
            }else{
                tree[treenode].a = right.a;
                tree[treenode].b = right.b;
                tree[treenode].index = right.index;
            }
        }
    }
     return;   
}

node query(node* tree,int start,int end,int treenode,int left,int right){
    
    //completely outside
    if(start > right || end < left){
        node temp;
        temp.a = INT_MIN;
        temp.b = INT_MAX;
        temp.index = INT_MAX;
        return temp;
    }
    
    //comppeletely inside
    if(start >= left && end <= right){
        return tree[treenode];
    }
    
    //partially inside or outside
    int mid = (start+end)/2;
    node first = query(tree,start,mid,2*treenode,left,right);
    node second = query(tree,mid+1,end,2*treenode+1,left,right);
    
    if(first.a > second.a){
        return first;
    }else if(second.a > first.a){
       return second;
    }else{
        if(first.b < second.b){
            return first;
        }else if(second.b < first.a){
           return second;
        }else{
            if(first.index < second.index){
                return first;
            }else{
                return second;
            }
        }
    } 
}

int main() {

	int n;
    cin >> n;
    warrior* arr = new warrior[n];
    for(int i=0;i<n;i++){
        cin >> arr[i].a;
    }
    for(int i=0;i<n;i++){
        cin >> arr[i].b;
    }
    node* tree = new node[4*n];
    
    buildtree(arr,tree,0,n-1,1);
    
    int q;
    cin >> q;
    while(q--){
        int left,right;
        cin >> left >> right;
        node ans = query(tree,0,n-1,1,left-1,right-1);
        cout << (ans.index)+1 << endl;
    }
    return 0;
    
}
