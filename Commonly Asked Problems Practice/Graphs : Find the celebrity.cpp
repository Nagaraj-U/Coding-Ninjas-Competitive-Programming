
/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person.
Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
 

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 

Example 2:

Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.

Your Task:
You don't need to read input or print anything. Complete the function celebrity() which takes the matrix M and its size N as input parameters 
and returns the index of the celebrity. If no such celebrity is present, return -1.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
2 <= N <= 3000
0 <= M[][] <= 1
*/


//USING STACKS
//TIME O(N)


class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) 
    {
        // code here 
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        while(s.size() > 1){
            int n1 = s.top();
            s.pop();
            int n2 = s.top();
            s.pop();

            if(M[n1][n2] == 1){//n1 cannot be celebrity
                s.push(n2);
            }else{
                s.push(n1);//n2 cannot be celebrity
            }
        }
        
   
        //check wether celebrity knows none and everybody knows celebrity
        for(int i=0;i<n;i++){
            if(i != s.top() and (M[s.top()][i] == 1 or M[i][s.top()] == 0)){
                return -1;
            }
        }
        
        return s.top();
    }
};



//USING ADJACENCY LIST
// TIME : O(V + E) , in worst case every vertex may have (n-1) edges ~ (n^2)

/*
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        vector<int> indegree(n,0);
        vector<int> outdegree(n,0);
        
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M.size();j++){
                if(M[i][j] == 1){
                    indegree[j]++;
                    outdegree[i]++;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i] == (n-1) and outdegree[i] == 0){
                return i;
            }
        }
        return -1;
        
    }
};
*/
