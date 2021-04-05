/*

Problem Statement
You have been given a Binary Tree of “N” nodes where the nodes have integer values and three integers N1, N2, and N3. Find the LCA(Lowest Common Ancestor) of the three nodes represented by the given three(N1, N2, N3) integer values in the Binary Tree.
For Example:

https://files.codingninjas.in/1-5311.png

For the given binary tree: the LCA of (7,8,10) is 1
Note:
All of the node values of the binary tree will be unique.

N1, N2, and N3  will always exist in the binary tree.
Input Format:
The first line of input contains a single integer T, representing the number of test cases or queries to be run. 

Then the T test cases follow. 

The first line of each test case contains three single space-separated integers N1, N2, and N3, denoting the nodes of which LCA is to be calculated.

The second line of each test case contains elements in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place.

For example, the input for the tree depicted in the below image would be :

1
2 3
4 -1 5 6
-1 7 -1 -1 -1 -1
-1 -1
Explanation :
Level 1 :
The root node of the tree is 1

Level 2 :
Left child of 1 = 2
Right child of 1 = 3

Level 3 :
Left child of 2 = 4
Right child of 2 = null (-1)
Left child of 3 = 5
Right child of 3 = 6

Level 4 :
Left child of 4 = null (-1)
Right child of 4 = 7
Left child of 5 = null (-1)
Right child of 5 = null (-1)
Left child of 6 = null (-1)
Right child of 6 = null (-1)

Level 5 :
Left child of 7 = null (-1)
Right child of 7 = null (-1)

The first not-null node (of the previous level) is treated as the parent of the first two nodes of the current level. The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and so on.
The input ends when all nodes at the last level are null (-1).
Note :
The above format was just to provide clarity on how the input is formed for a given tree. 
The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
Output Format:
For each test case,  print the integer value of the node representing LCA. in a single line.
Note
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 10^5
0 <= node data <= 10^9
0 <= N1 <= 10^9
0 <= N2 <= 10^9
0 <= N3 <= 10^9

Time Limit: 1sec
Sample Input 1:
1
8 9 11
1 2 3 4 5 6 7 8 9 -1 -1 -1 -1 -1 -1 10 -1 11 -1 -1 -1 -1 -1
Sample Output 1:
4
Sample Input 2:
2
7 8 2
1 2 3 4 5 6 7 8 9 -1 -1 -1 -1 -1 -1 10 -1 11 -1 -1 -1 -1 -1
5 6 7
1 2 3 4 5 6 7 8 9 -1 -1 -1 -1 -1 -1 10 -1 11 -1 -1 -1 -1 -1
Sample Output 2:
1
1
Explanation To Sample Input 2:
For both inputs, the binary tree will be represented as

For the first test case, the LCA of 7,8,2 in the given tree is 2 

For the second test case. the LCA of 5,6,7 in the given tree is 1,   

*/


/*
APPROACH


By Storing Paths
A simple solution would be to store the path from the root to N1, the path from the root to N2, and the path from the root to N3 in the three auxiliary Lists/Array.
Now, to store the path from the root to any node X we create a recursive function that traverses the different path in the binary tree to find any node X:
If root == null return true
Add the root data to List/Array
If root data = X return true
If X is found in any of the subtrees either left or right then return true
Else remove the current root data from the List/Array and then return false
Then we traverse all lists simultaneously till the values in the list match. The last matched value will be the LCA. If the end of one array is reached then the last seen value is LCA.
Time Complexity
O(N), where N is the total number of nodes in the given binary tree.

In the worst case, the tree is traversed thrice to find paths of N1, N2, and N3 O(N), and then the stored path list O(N) is traversed. Thus a total of O(N).

Space Complexity
O(N), where N is the total number of nodes in the given binary tree.

In the worst case, we will store all the nodes in the list as a path from the root to the node. And we will have all the nodes of the Binary Tree in the recursion stack O(N). Thus a total of O(N).



*/



/**********************************************************
    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
    public :
	    T data;
	    BinaryTreeNode<T> *left;
	    BinaryTreeNode<T> *right;

	    BinaryTreeNode(T data) {
	        this -> data = data;
	        left = NULL;
	        right = NULL;
	    }
    };

***********************************************************/




bool helper(int node,BinaryTreeNode<int>* root, vector<BinaryTreeNode<int>* > &path)
{
    if(root == NULL){
        return false;
    }
    path.push_back(root);
    if(root->data == node){
        return true;
    }
    bool left = helper(node,root->left,path);
    bool right = helper(node,root->right,path);
    if(left || right){
        return true;
    }
    path.pop_back();
    return false;
    
}

BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
    // Write your code here
    vector<BinaryTreeNode<int>*> path1; 
    vector<BinaryTreeNode<int>*> path2; 
    vector<BinaryTreeNode<int>*> path3;
    helper(node1,root,path1);
    helper(node2,root,path2);
    helper(node3,root,path3);
    int i=0;
    for(i=0;i<path1.size() && i < path2.size() && i < path3.size();i++){
        if(path1[i]->data != path2[i]->data || path1[i]->data != path3[i]->data || path2[i]->data != path3[i]->data){
            break;
        }
    }
    return path1[i-1];
    
}
