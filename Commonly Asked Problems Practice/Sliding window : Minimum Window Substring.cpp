/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included 
in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(); //text
        int m = t.length(); //pattern
        if(m > n){
            return "";
        }
        unordered_map<int,int> mp;
        for(int i=0;i<m;i++){
            mp[t[i]]++;  //store all chars of pattern in map
        }
        int count = mp.size(); //this stores chars still needed at any instant ,if count=0 then we found ans 
        int start = 0;
        int end = 0;
        int min_len = INT_MAX;
        int startIdx = -1; //to check start indx of minimal length string
        
        while(end < n){
    
            if(mp.count(s[end]) != 0){ //if curr char is belong pattern
                mp[s[end]]--;
                if(mp[s[end]] == 0){ //one of the chars requirement satisfied
                    count--;
                }
            }
            
            if(count == 0){ //we got all chars , try removing chars from begin to minimize length
                
                while(count == 0){
                    
                    if(end-start+1 < min_len){ //update everytime min_len
                        min_len = end-start+1;
                        startIdx = start;
                    }
                    
                    if(mp.count(s[start]) != 0){
                        mp[s[start]]++;
                        
                         if(mp[s[start]] > 0){
                            count++;
                        }
                    }                   
                    start++;
                }
              
            }
            
            end++;
        }
        if(min_len == INT_MAX){ //no substring with all chars found
            return "";
        }
        return s.substr(startIdx,min_len);
    }
};
