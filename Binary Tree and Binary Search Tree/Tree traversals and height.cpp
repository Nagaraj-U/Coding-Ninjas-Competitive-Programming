
#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left, *right;
};

/* Function protoypes */
void printCurrentLevel(node* root, int level);
int height(node* node);
node* newNode(int data);

void levelorder(node* root)
{
    if(root == NULL){
        return;
    }
    
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout << temp->data << endl;
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
    return;
}

int height(node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		/* compute the height of each subtree */
		int lheight = 1+height(node->left);
		int rheight = 1+height(node->right);

        return max(lheight,rheight);
	}
}


node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return(Node);
}

void preorder(node* root)
{
    if(root==NULL){
        return;
    }
    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);
    return;
}

void inorder(node* root)
{
    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
    return;
}


void postorder(node* root)
{
    if(root==NULL){
        return;
    }
   
    postorder(root->left);
    postorder(root->right);
    cout << root->data << endl;
    return;
}


/* Driver code*/
int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	/*
	    BFS : level traversal (queue implementation)
	    DFS : preorder,inorder,postorder
	
	*/

	cout << "Level Order traversal of binary tree is \n";
	levelorder(root);
	cout << "preorder" << endl;
	preorder(root);
	cout << "inorder" << endl;
	inorder(root);
	cout << "postorder" << endl;
	postorder(root);
    cout << "height" << endl;
    cout <<   height(root) << endl;

	return 0;
}

