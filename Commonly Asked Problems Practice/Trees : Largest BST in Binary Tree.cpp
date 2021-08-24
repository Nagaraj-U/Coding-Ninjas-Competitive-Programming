/*
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
Example 2:

Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 
Output: 2
Explanation: The following sub-tree is a
BST of size 2: 
       2
    /    \ 
   N      8
Your Task:
You don't need to read input or print anything. Your task is to complete the function largestBst() that takes the root
node of the Binary Tree as its input and returns the size of the largest subtree which is also the BST. If the complete Binary Tree is a BST,
return the size of the complete Binary Tree. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 106
*/

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    struct node{
        bool isBST;//check with current rooted with its subtrees nodes is valid BST
        int max_sub;//max element in subtree
        int min_sub;//min element in subtree
        int count;//total number of nodes in till current subtree
        int result;//max number of nodes present in overall largest BST (actual result)
    };
    
    node helper(Node* root){
        
        //no node
        if(root == NULL){
            return node({true,INT_MIN,INT_MAX,0,0});
        }
        
        //single node
        if(root->left == NULL and root->right == NULL){
            return node({true,root->data,root->data,1,1});
        }
        
        node left = helper(root->left);
        node right = helper(root->right);
        
        
        //filling in bottom up approach
        node ans;
        if(left.isBST and right.isBST and root->data > left.max_sub and root->data < right.min_sub){
            ans.isBST = true;
            ans.count = 1 + left.count + right.count;
            ans.max_sub = max({root->data,left.max_sub,right.max_sub});
            ans.min_sub = min({root->data,left.min_sub,right.min_sub});
            ans.result = 1 + left.result + right.result;
        }else{//current subtree is not BST
            ans.isBST = false;
            ans.count = 1 + left.count + right.count;//number of nodes in left + right
            ans.result = max({left.result,right.result});
            ans.max_sub = max({root->data,left.max_sub,right.max_sub});
            ans.min_sub = min({root->data,left.min_sub,right.min_sub});
        }
        return ans;
        
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	node ans = helper(root);
    	return ans.result;
    }
};
