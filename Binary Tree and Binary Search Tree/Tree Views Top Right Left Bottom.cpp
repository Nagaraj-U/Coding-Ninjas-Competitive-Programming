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


//inorder traversal and print first element of each level
void leftView(node* root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		
		int size = q.size();
		
		for(int i=1;i<=size;i++){

			auto temp = q.front();
			q.pop();

			if(i==1){
				cout << temp->data << endl;
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


//inorder traversal and print last element of each level
void rightView(node* root)
{
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		int size = q.size();

		for(int i=1;i<=size;i++){
			node* temp = q.front();
			q.pop();
			 if(i == size){
			 	cout << temp->data << endl;
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


//inorder traversal and print elements which have largest horizontal distance from root 
void topView(node* root)
{
	queue<pair<node*,int>> q;
	q.push({root,0});
	map<int,int> m; //map : key = distance , value = node data 
	while(!q.empty()){
		int size = q.size();

		for(int i=1;i<=size;i++){

			auto p = q.front();
			node* temp = p.first;
			int distance = p.second;
			q.pop();
			if(m.count(distance) == 0){ //(if already horizontal distance exist its overlapped by above so dont print)
				m[distance] = temp->data;
			}

			if(temp->left){
				q.push({temp->left,distance-1});
			}

			if(temp->right){
				q.push({temp->right,distance+1});
			}
		}
	}

	//prints :  left most nodes first(-ve) -> root(0) -> righmost most (+ve)
	for(auto i : m){
		cout << i.second << endl;
	}
	return;
}


void bottomView(node* root)
{
	queue<pair<node*,int>> q;
	q.push({root,0});
	map<int,int> m;
	while(!q.empty()){
		int size = q.size();

		for(int i=1;i<=size;i++){
			auto p = q.front();
			q.pop();

			node* temp = p.first;
			int distance = p.second;
			m[distance] = temp->data; //if already exist with same distance then override it (old one is shadows by current)

			if(temp->left){
				q.push({temp->left,distance-1});
			}

			if(temp->right){
				q.push({temp->right,distance+1});
			}
		}
	}

	for(auto i : m){
		cout << i.second << endl;
	}
	return;

}


int main()
{

	node* root = new node(7);
	root->left = new node(2);
	root->right = new node(6);
	root->left->left =new node(3);
	root->right->left =new node(8);
	// root->right->left->left =new node(9);
	// root->right->right = new node(10);

	cout << "left view " << endl;
	leftView(root);

	cout << "right view " << endl;
	rightView(root);

	cout << "top view" << endl;
	topView(root);

	cout << "bottom view" << endl;
	bottomView(root);
	return 0;
}

/*

original tree

		7
	2 		6
3		8



left view = 3,2,7

		7
	2 		
3		


right view = 7,6,8

	7
 		6
	8


top view = 3,2,7,6

		7
	2 		6
3		



bottom view = 3,2,8,6
		
	2 		6
3		8






example 2 : 

		7
	2 		6
3		8		10
	9


left view
7
2
3
9

right view
7
6
10
9

top view
3
2
7
6
10

bottom view
3
9
8
6
10

*/
