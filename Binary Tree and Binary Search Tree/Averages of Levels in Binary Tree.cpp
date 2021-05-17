/*
You are given an arbitrary binary tree consisting of N nodes numbered from 1 to N, and each node is associated with some positive integer value, your task is to find the average of all the levels in the given tree, i.e you have to find the average of all the node values present on the level, for each level.
Two nodes of a tree are said to be at the same level ‘k’ if both of them are at equal distance( = k) from the root node. The root node is said to be at level 0.
Note:
1) Two nodes may have the same value associated with it.
2) Average of any level is computed as the sum of the values of all the nodes at that level divided by the number of nodes at that level.
3) The root node will be fixed and will be provided in the function and also you need to return the values in order of levels, i.e first value corresponds to the average of the first level and so on.
4) You need to return the floor value for each average. For eg,  if the average of node values at some level = 3.5 then you have to return 3.
Input Format:
The first line of the input contains a single integer T, representing the number of test cases.

The first line of each test case contains a single integer N denoting the number of nodes in the tree. 

The second line contains the values of the nodes of the tree in the level order form ( -1 for NULL node) Refer to the example for further clarification.
Example: Consider the binary tree 

The Input Of The Tree Depicted In The Image Above Will Be Like:
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

The first not-null node (of the previous level) is treated as the parent of the first two nodes of the current level. 
The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and so on.

The input ends when all nodes at the last level are null (-1).
Output Format:
For each test case, print X space-separated values where X is the number of levels in the given binary tree, where the ith integer will denote the average of node values at 
the ith level. Refer to Sample Input1 for more clarity.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
1 <= N <= 10^4
1 <= nodeVal <= 10^9
Time Limit: 1sec
Sample Input 1:
1
3
1 2 3 -1 -1 -1 -1
Sample Output 1:
1 2
Explanation For Sample Input 1:

This is the tree as described in the input here lo denotes level-0 and l1 denotes level-1. Now the average of nodes at level 0 is (1/1), which is 1.
And the average at level 1 is ((2+3)/2) which is 2.50
Sample Input 2:
1
4
5 6 7 8 -1 -1 -1 -1 -1
Sample Output 2:
5 6 8
Explanation For Sample Input 2:

This is the tree as described in the input here lo denotes level-0 and l1 denotes level-1 and l2 denotes level-2. Now the average of nodes at level 0 is (5/1), which is 5.
And the average at level 1 is ((6+7)/2) which is 6.50, and the average at level-2 is (8/1) which is 8.



*/















/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
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

*************************************************************/
#include<bits/stdc++.h>
vector<long long> averageOfLevels(BinaryTreeNode<int>* root) {
    // Write your code here
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    vector<long long> v;

    while(!q.empty()){
        long long sum = 0;
        int count = q.size();
        int tempcount = count;
        while(tempcount--){//calculate sum of nodes at particular level and push their childs to queue
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            sum += node->data;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        v.push_back(floor(sum/count));
    }
    return v;
}
