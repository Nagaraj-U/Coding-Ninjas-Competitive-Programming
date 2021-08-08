/*
step1 : use level order traversal to get all nodes in vector O(n)
step 2 : sort vector  (n log n)
step 3 : copy values from vector to original tree , using inorder traversal (since inorder of BST is always sorted)  O(n)
*/
//time : O(n * log n)

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(TreeNode* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

void copyNodes(TreeNode* root,vector<int> &path,int &idx){
    if(!root){
        return;
    }
    copyNodes(root->left,path,idx);
    root->data = path[idx++];
    copyNodes(root->right,path,idx);
}

void contructBST(TreeNode* root){
    vector<int> path;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        path.push_back(curr->data);
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }

    sort(path.begin(),path.end());
    int idx = 0;
    copyNodes(root,path,idx);
    return;
}

int main()
{   
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(7);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(12);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(54);
    root->right->right = new TreeNode(44);
    cout << "binary tree inorder " << endl;
    inorder(root);

    cout << "contructing BST from binary tree " << endl;
    contructBST(root);

    cout << "binary search tree inorder " << endl;
    inorder(root);
    return 0;
}


