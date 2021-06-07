
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node* left;
        Node* right;
        int data;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void leftView(Node* root)
{
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        bool flag = true;
        for(int i=0;i<n;i++){
            Node* temp = q.front();
            q.pop();
            if(flag){
                cout << temp->data << endl;  //print first element in a particular level
                flag = false;
            }
 
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            
        }
    }
    return;
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(5);
    root->right = new Node(3);
    leftView(root);
    // cout << root->left->data << endl;
    return 0;
}
