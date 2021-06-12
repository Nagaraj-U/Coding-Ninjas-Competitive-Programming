/*
Given a Binary Tree where each node has positive and negative values. Convert this to a tree where each node contains the sum of the left and
right sub trees in the original tree. 
*/


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

void sumReplacement(node* root)
{
    if(root == NULL){
        return;
    }
    sumReplacement(root->left);
    sumReplacement(root->right);
    if(root->left){
        root->data = root->data + root->left->data;
    }
    if(root->right){
        root->data = root->data + root->right->data;
    }

    return;
}

void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);
}

int countNodes(node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    node* root = new node(3);
    root->left = new node(4);
    root->right = new node(5);
    root->left->left = new node(6);
    root->left->right = new node(7);
    root->right->right = new node(9);
    sumReplacement(root);
    preorder(root);
    cout << "node count " << countNodes(root) << endl;
    return 0;
}


