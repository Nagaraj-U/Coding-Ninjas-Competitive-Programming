/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int start = 0;
        int end = 0;
        unordered_map<int,int> m;
        int max_len = 0;
        while(end < n){
            if(m.count(s[end]) == 0){ //char not present , add and update length
                m[s[end]]++;
                max_len = max(max_len , end-start+1);
                end++;
            }else{ //curr char is present already ,start poppping all chars from begining unitl previously occured current char is removed
                while(m.count(s[end]) != 0){
                    m.erase(s[start]);
                    start++;
                }
            }
        }
        
        return max_len;
    }
};
