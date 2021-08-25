/*
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and 
next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal 
(leftmost node in BT) must be the head node of the DLL.

TreeToList

Example 1:

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3 
Explanation: DLL would be 3<=>1<=>2
Example 2:

Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:  DLL would be 
40<=>20<=>60<=>10<=>30.
Your Task:
You don't have to take input. Complete the function bToDLL() that takes root node of the tree as a parameter and returns the head of DLL .
The driver code prints the DLL both ways.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree and this space is used implicitly for the recursion stack.

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105
*/


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 

// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    
    
    //convert to DLL in inorder manner
    void helper(Node* root,Node* &head,Node* &prev){
        if(root == NULL){
            return;
        }
       
        helper(root->left,head,prev);
        
        //left most node is the head of DLL
        if(prev == NULL){
            head = root;
        }else{ //make prev node right point to current node and curernt node left to prev node
            root->left = prev;
            prev->right = root; 
        }
        
        prev = root;//prev changed to curent node
        
        helper(root->right,head,prev);
    }
    
    Node * bToDLL(Node *root)
    {
        // your code here
        Node* head = NULL;
        Node* prev = NULL;
  
        helper(root,head,prev);
        return head;
    }
};
