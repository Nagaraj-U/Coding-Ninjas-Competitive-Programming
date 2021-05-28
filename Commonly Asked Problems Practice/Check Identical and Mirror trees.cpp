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


bool isIdentical(node* root1,node* root2)
{
	if(root1 == NULL && root2 == NULL){
		return true;
	}

	if(root1 == NULL || root2 == NULL){
		return false;
	}

	if(root1->data != root2->data){
		return false;
	}

	return isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);
}

bool isMirror(node* root1,node* root2){
	if(root1 == NULL && root2 == NULL){
		return true;
	}

	if(root1 == NULL || root2 == NULL){
		return false;
	}

	if(root1->data != root2->data){
		return false;
	}

	return isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
}





int main()
{


	node* root1 = new node(7);
	root1->left = new node(2);
	root1->right = new node(8);
	root1->left->left = new node(1);
	root1->left->right = new node(5);

	//for identical
	node* root2 = new node(7);
	root2->left = new node(2);
	root2->right = new node(8);
	root2->left->left = new node(1);
	root2->left->right = new node(5);

	//for mirror trees
	// node* root2 = new node(7);
	// root2->left = new node(8);
	// root2->right = new node(2);
	// root2->right->left = new node(5);
	// root2->right->right = new node(1);



	if(isIdentical(root1,root2)){
		cout << "trees are identical " << endl;
	}else{
		cout << "trees are not identical " << endl;
	}

	if(isMirror(root1,root2)){
		cout << "tree are mirror images" << endl;
	}else{
		cout << "trees are not mirror images" << endl;
	}
	
	return 0;
}


/*

	//for identical

			7                           7     

		2 		8					2 		8

	1 		5 					1 		5
 

	
	//for mirror trees



			7                           7     

		2 		8					8 		2

	1 		5 					 		5		1



*/
