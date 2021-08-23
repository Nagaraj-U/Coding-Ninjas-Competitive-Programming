/*
Predecessor and Successor 
Easy Accuracy: 46.01% Submissions: 31769 Points: 2
There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. In case,
if the either of predecessor or successor is not found print -1.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains n denoting the number of
edges of the BST. The next line contains the edges of the BST. The last line contains the key.

Output:
Print the predecessor followed by successor for the given key. If the predecessor or successor is not found print -1.

Constraints:
1<=T<=100
1<=n<=100
1<=data of node<=100
1<=key<=100

Example:
Input:
2
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
65
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
100

Output:
60 70
80 -1
*/



void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
    while(root){
        if(root->key == key){ 
            if(root->left){ //left tree rightmost node
                pre = root->left;
                Node* temp = root->left;
                while(temp->right){
                    temp = temp->right;
                }
                pre = temp;
            }
            
            if(root->right){
                suc = root->right; //right tree leftmost node
                Node* temp = root->right;
                while(temp->left){
                    temp = temp->left;
                }
                suc = temp;
            }
            
            return;
        }else if(key < root->key){
            suc = root; //since we moving one step down , and root may be successor store it
            root = root->left;
        }else{
            pre = root;//since we moving one step down , and root may be predecesor store it
            root = root->right;
        }
    }
    return;

}
