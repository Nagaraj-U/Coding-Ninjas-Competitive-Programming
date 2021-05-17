/*

Problem Statement
You have been given a binary tree of integers. You are supposed to serialize and deserialize (refer to notes) the given binary tree. You can choose any algorithm to 
serialize/deserialize the given binary tree. You only have to ensure that the serialized string can be deserialized to the original binary tree.
Note :
Serialization is the process of translating a data structure or object state into a format that can be stored or transmitted (for example, across a computer network) and 
reconstructed later. The opposite operation that is, extracting a data structure from stored information, is deserialization.
Input Format :
The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The only line of each test case contains elements in the level order form. The line consists of values of nodes separated by a single space. In case a node is null,
we take -1 in its place. So -1 would not be a part of the tree nodes.

For example, the input for the tree depicted in the below image will be:

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

The first not-null node(of the previous level) is treated as the parent of the first two nodes of the current level. The second not-null node (of the previous level) is 
treated as the parent node for the next two nodes of the current level and so on.
The input ends when all nodes at the last level are null(-1).
Note :
The above format was just to provide clarity on how the input is formed for a given tree. 
The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
Output Format :
For each test case, print the level order traversal of the deserialized binary tree separated by single spaces, for NULL nodes print -1.

Print the output of each test case in a separate line.
Note :
You don’t need to print anything; It has already been taken care of.
Constraints :
1 <= T <= 100
0 <= N <= 5000
1 <= data <= 10^5 and data != -1

Where ‘T’ is the number of test cases, and ‘N’ is the total number of nodes in the binary tree, and “data” is the value of the binary tree node

Time Limit: 1 sec
Sample Input 1 :
2
1 -1 3 -1 -1
3 4 -1 -1 -1
Sample Output 1 :
1 -1 3 -1 -1 
3 4 -1 -1 -1
Explanation Of Sample Input 1 :
For the first test case, the level order traversal of the given tree will be “1 -1 3 -1 -1” where -1 denotes the null nodes.

For the second test case,  the level order traversal of the given tree will be “3 4 -1 -1 -1” where -1 denotes the null nodes.
Sample Input 2 :
2
1 2 3 -1 4 5 -1 -1 -1 -1 -1
2 1 3 4 -1 -1 5 -1 -1 -1 -1 
Sample Output 2 :
1 2 3 -1 4 5 -1 -1 -1 -1 -1
2 1 3 4 -1 -1 5 -1 -1 -1 -1
Explanation Of Sample Input 2 :
For the first test case, the level order traversal of the given tree will be “1 2 3 -1 4 5 -1 -1 -1 -1 -1” where -1 denotes the null nodes. 

For the second test case,  the level order traversal of the given tree will be “2 1 3 4 -1 -1 5 -1 -1 -1 -1” where -1 denotes the null nodes.


*/










/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    string serialize = "";
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* temp = q.front();
        q.pop();
        if(temp != NULL){
            q.push(temp->left);
            q.push(temp->right);
            
            serialize.append(to_string(temp->data));
            serialize.push_back(',');
        }else{
            serialize.append("-1,");
        }
    }
//     cout << serialize << endl;
    return serialize;
    

}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    int index = 0;
    int n = serialized.length();
    queue<TreeNode<int>*> q;
    string str = "";
    while(index < n && serialized[index] != ','){
        str.push_back(serialized[index]);
        index++;
    }
    index++;
    int data = stoi(str);
    if(data == -1){
        return NULL;
    }
    TreeNode<int>* root = new TreeNode<int>(data);
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* curr = q.front();
        q.pop();
        
        string left = "";
        string right = "";
        while(index < n && serialized[index]!=','){
            left.push_back(serialized[index]);
            index++;
        }
        index++;
        int leftdata = stoi(left);
        
        while(index < n && serialized[index] != ','){
            right.push_back(serialized[index]);
            index++;
        }
        index++;
        
        int rightdata = stoi(right);
        
        if(leftdata != -1){
            curr->left = new TreeNode<int>(leftdata);
            q.push(curr->left);
        }
        if(rightdata != -1){
            curr->right = new TreeNode<int>(rightdata);
            q.push(curr->right);
        }
    }
    return root;

}



