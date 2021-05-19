





/*
You are given an array ‘Arr’ consisting of ‘N’ distinct integers. Elements in array ‘Arr’ are sorted in increasing order. Your task is to convert it to a height-balanced binary search tree.
A binary tree is height-balanced when the height of the two subtrees of every node never differs by more than one.
Note:
1. There can be more than one way to convert an array to a height-balanced binary tree. You can find any one of them.
Example:
Consider an array ‘Arr’ = [-10, -5, 2, 4, 5],  one way to convert it to a height-balanced binary tree is -:

Here, You can see that the height of the left and right subtree of the node having the data ‘2’ is  2 and 2 respectively, i.e both are the same, 
and the height of the left and the right tree of the node having the data ‘-10’, is 0, 1 respectively, i.e differ by only 1,  and the height of left and right subtree 
of the node having the data ‘4’, is also 0 and ‘1’ respectively, i.e differ by only ‘1’. Thus this binary search tree is height-balanced.  Also, note that this is not the only 
way to convert this array to a height-balanced binary search tree.
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases, then ‘T’ test cases follow.

The first line of each test case consists of a single integer ‘N’, representing the number of elements in array ‘Arr’.

The second line of each test case consists of ‘N’ space-separated integers, representing array ‘Arr’.
Output Format :
For each test case, in a separate line ‘Correct’ will be printed if you convert the given array in the height-balanced tree correctly, otherwise ‘Incorrect’ will be printed.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 50
1  <= N <= 10^4
-10^9 <= Arr[i] <= 10^9

Where ‘T’ is the total number of test cases, ‘N’ is the number of elements in array ‘Arr’, and ‘Arr[i]  represents the elements of array ‘Arr’.

Time limit: 1 sec
Sample Input 1:
2
1
1
5
-10 -5 2 4 5
Sample Output 1:
Correct
Correct
Explanation Of Sample Input 1:
Test case 1:
There is only one node, so the correct way to convert it to the height-balanced binary search tree is to create a tree having a single node with the data ‘1’

Test case 2:
See the problem statement for an explanation.
Sample Input 2:
2
5
1 2 3 4 5
2
-10 25
Sample Output 2:
Correct
Correct

*/

/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
BinaryTreeNode<int>* construct(vector<int> &arr,int left,int right)
{
    if(left > right){
        return NULL;
    }
    int mid =(left+right)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(arr[mid]);
    root->left = construct(arr,left,mid-1);
    root->right = construct(arr,mid+1,right);
    return root;
}

BinaryTreeNode<int>* minimalTree(vector<int> &arr) {
    // Write your code here.
    BinaryTreeNode<int>* root = construct(arr,0,arr.size()-1);
    return root;
}
