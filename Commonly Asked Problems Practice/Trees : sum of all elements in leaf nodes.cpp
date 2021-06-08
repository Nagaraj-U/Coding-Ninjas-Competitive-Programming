#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;
    node(int val){
        this->data = val;
        left = NULL;
        right = NULL;
    }
    
};

int leafSumIterative(node* root)
{
    if(root == NULL){
        return 0;
    }
    int sum = 0;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp->left == NULL && temp->right == NULL){
            sum += temp->data;
        }else{
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }        
    }
    
    return sum;
}

int leafSumRecursive(node* root)
{
    static int sum = 0;
    if(root == NULL){
        return 0;
    }

    if(!root->left && !root->right){
        sum += root->data;
    }

    leafSumRecursive(root->left);
    leafSumRecursive(root->right);
    return sum;
}

int main()
{
    node* root = new node(3);
    root->left = new node(4);
    root->right = new node(5);
    root->left->left = new node(6);
    root->left->right = new node(7);
    root->right->right = new node(9);
    int leafIterative = leafSumIterative(root);
    int leafRecursive = leafSumRecursive(root);
    cout << "sum of all leaf nodes is : (iterative) " << leafIterative << endl;
    cout << "sum of all leaf nodes is : (recursive) " << leafRecursive << endl;
    return 0;
}
