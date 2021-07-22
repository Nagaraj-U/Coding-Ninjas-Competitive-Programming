/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is 
correct else 0 denoting incorrect string returned.
 

Example 1:

Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Example 2:

Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function findOrder() which takes  
the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.


Expected Time Complexity: O(N + K)
Expected Space Compelxity: O(K)


Constraints:
1 ≤ N, M ≤ 300
1 ≤ K ≤ 26
1 ≤ Length of words ≤ 50
*/


class Solution{
    public:
    //custom fun
    void addEdges(vector<vector<int>> &adj,string &w1,string &w2){
        for(int i=0;i<min(w1.length(),w2.length());i++){
            if(w1[i] == w2[i]){
                continue;
            }
            adj[w1[i] - 'a'].push_back(w2[i] - 'a');//abc , aca , we can say (b<c)(2nd idx , but cant say(c<a) (3rd)
            break;
        }
        return;
    }
    
    void topoSort(vector<vector<int>> &adj,int start,bool* visited,string &temp){
        visited[start] = true;
        for(int i=0;i<adj[start].size();i++){
            if(!visited[adj[start][i]]){
                topoSort(adj,adj[start][i],visited,temp);
            }
        }
        char ch = start + 'a';
        temp = ch + temp;//adding chars in reverse order (topo sort property)
        
        return;
    }
    
  //given fun
    string findOrder(string dict[], int n, int k) {
        //code here
        vector<vector<int>> adj(k);//since they given first 'k' chars
        for(int i=0;i<n-1;i++){
            string word1 = dict[i];
            string word2 = dict[i+1];
            addEdges(adj,word1,word2);
        }
        
        bool* visited = new bool[k]();
        string ans = "";
        
        //Note : topological sort on any random vertex gives same results
        for(int i=0;i<k;i++){
            if(!visited[i]){
                string temp = "";
                topoSort(adj,i,visited,temp);
                ans = temp + ans;
            }
        }
        
        return ans;
    }
};
