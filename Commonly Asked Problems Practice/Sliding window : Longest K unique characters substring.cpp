/*
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

Example 1:

Input:
S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest 
substring with K distinct characters.
â€‹Example 2:

Input: 
S = "aaaa", K = 2
Output: -1
Explanation: There's no substring with K
distinct characters.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestKSubstr() which takes the string S and an integer K as input and returns
the length of the longest substring with exactly K distinct characters. If there is no substring with exactly K distinct characters then return -1.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).


Constraints:
1<=|S|<=105
1<=K<=105
*/

class Solution{
    public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<int,int> m;
        int start = 0;
        int end = 0;
        int n = s.length();
        int max_len = -1;
        while(end < n){
            m[s[end]]++;
            
            if(m.size() == k){
                max_len = max(max_len , end-start+1);
            }else if(m.size() > k){ //if number of unique chars are more , start removing elmeents from start
                while(m.size() > k){
                    m[s[start]]--;
                    if(m[s[start]] == 0){
                        m.erase(s[start]);
                    }
                     start++;
                }
            }
            
            end++;
        }
        
        return max_len;
    
    }
};
