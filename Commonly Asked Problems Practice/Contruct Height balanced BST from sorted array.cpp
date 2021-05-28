//Height balanced tree : difference between left tree height and right tree height should not be greater than 1
//since array is sorted try to equally devide nodes between left and right sub trees , consider mid

#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;
		node(int data){
			this->data = data;
			left = NULL;
			right = NULL;
		}
};


//construct Height balanced BST from sorted array

node* constructBST(int arr[],int start,int end)
{
	if(start > end){
		return NULL;
	}
	int mid = (start+end)/2;
	node* root = new node(arr[mid]);
	root->left = constructBST(arr,start,mid-1);
	root->right = constructBST(arr,mid+1,end);

	return root;
}

void inorder(node* root)
{
	if(root == NULL){
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(node* root)
{
	if(root == NULL){
		return;
	}

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
	
}

int main()
{
	node* root = NULL;
	int arr[6]= {1,2,3,4,5,6};
	cout << "Height Balanced tree : " << endl;
	root = constructBST(arr,0,5);
	cout << "Inorder traversal" << endl;
	inorder(root);

	cout << "preorder traversal" << endl;
	preorder(root);
	return 0;
}

