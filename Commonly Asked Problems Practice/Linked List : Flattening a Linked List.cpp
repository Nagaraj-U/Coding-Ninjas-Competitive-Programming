/*
Flattening a Linked List 
Medium Accuracy: 33.91% Submissions: 62928 Points: 4
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.

 

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45

Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
 

Example 2:

Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5->7->8->10->19->20->22->30->50
Explanation:
The resultant linked lists has every
node in a single level.

(Note: | represents the bottom pointer.)
 

Your Task:
You do not need to read input or print anything. Complete the function flatten() that takes the head of the linked list as input parameter and returns 
the head of flattened link list.

 

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)
*/


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* merge(Node* l1 , Node* l2){
    Node* temp = new Node(-1);
    Node* head = temp;
    while(l1 and l2){
        if(l1->data <= l2->data){
            temp->bottom = l1;
            temp = temp->bottom;
            l1 = l1->bottom;
        }else{
            temp->bottom = l2;
            temp = temp->bottom;
            l2 = l2->bottom;
        }
    }
    while(l1){
        temp->bottom = l1;
        temp = temp->bottom;
        l1 = l1->bottom;
    }
    while(l2){
        temp->bottom = l2;
        temp = temp->bottom;
        l2 = l2->bottom;
    }
    return head->bottom;
} 
    
//approach same as merging two lists
/*
merge last two lists into one , then return
then merge prev merged list and third last list , continue the process
note : we need to flatten in bottom manner

result should look :
1 -> NULL
|
2
|
3
|
MULL
*/
Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL or root->next == NULL){
       return root;
   }
   
   root->next = flatten(root->next);
   root = merge(root,root->next);
   root->next = NULL;
   return root;
}
