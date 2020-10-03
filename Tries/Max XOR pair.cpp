#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
        Trie* left;
        Trie* right;
};

//In Trie left node = 0 and right node = 1

void insert(Trie* head,int num){
    Trie* curr = head;
    for(int i = 31;i >= 0;i--){ //integer : 32 bits
        int b = (num >> i) & 1;  //if num = (10001010 >> 7) = (00000001) & 1 = (00000001) & (00000001) = 1    [right shift gives ith bit]
        if(b == 1){
            if(!curr -> right){ //number not present 
                curr->right = new Trie();
            }
            curr = curr->right;
        }else{
            if(!curr->left){
                curr->left = new Trie();
            }
            curr = curr ->left;
        }
    }
    return ;
}

int findMaxXOR(int* arr,int n,Trie* head){
    int max_xor = INT_MIN;
    for(int i=0;i<n;i++){//iterating through all array elements
        int value = arr[i];
        int cur_xor = 0;
        Trie* curr = head; //after each iteration set curr to Trie head
        for(int j = 31;j>=0;j--){  //iterating all nodes in trie
            int b = (value >> j) & 1;   //(if num is 101 try to get 010 which gives max XOR)
            if(b == 0){
                if(curr->right){
                    cur_xor += pow(2,j); //if num = 0110 if we get 1 for MSB add pow(2,j) to cur_xor ir cur_xor = 1000 (example for first iteration only)
                    curr = curr->right;
                }else{
                    curr = curr ->left;
                }
            }else{
                if(curr->left){
                    curr = curr->left;
                }else{
                    cur_xor += pow(2,j);
                    curr = curr->right;
                }
            }
        }
        max_xor = max(max_xor,cur_xor);
    }
    return max_xor;
}

int main(){
    Trie* head = new Trie();
    cout << "Enter Number of Elements" << endl;
    int n;
    cin >> n;
    int* arr = new int[n];
    cout << "enter array elements : " << endl;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        arr[i] = num;
        insert(head,num);//inserting each value into tree
    }
    int ans = findMaxXOR(arr,n,head);
    cout << "Max XOR pair value is : " << ans << endl;
    return 0;
}
