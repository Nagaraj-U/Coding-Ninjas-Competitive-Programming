#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node *left;
    struct node *right;
};

node *createNode(int num)
{
    node *temp = new node();
    temp->data = num;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node *insertNode(int key, node *root)
{
    if (root == NULL)
    {
        node *temp = new node();
        temp->data = key;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
        return root;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        //checking for particular wether left or right child is empty and then inserting
        if (temp->left != NULL)
        {
            temp = temp->left;
        }
        else
        {
            node *newNode = new node();
            newNode->data = key;
            temp->left = newNode;
            return root;
        }

        if (temp->right != NULL)
        {
            temp = temp->right;
        }
        else
        {
            node *newNode = new node();
            newNode->data = key;
            temp->right = newNode;
            return root;
        }
    }
}

int main()
{
    node *root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(12);
    root->right = createNode(13);
    root->right->right = createNode(14);
    inorder(root);
    cout << " enter the element to insert " << endl;
    int key;
    cin >> key;
    root = insertNode(key, root);
    inorder(root);
    return 0;
}
