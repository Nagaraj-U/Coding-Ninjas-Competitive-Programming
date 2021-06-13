/*

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

*/




class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        int n = s.length();
        
        //store last occurance of each character
        for(int i=n-1;i>=0;i--){
            if(m.count(s[i]) == 0){
                m[s[i]] = i;
            }
        }
        
        vector<int> ans;
        int curr_max = INT_MIN;
        int start = 0;
        
        //for each character check max last position we encountered so far . if 'i' exceeds curr_max we found on part
        for(int i=0;i<n;i++){
            curr_max = max(curr_max,m[s[i]]);
            if(curr_max == i){
                ans.push_back(i-start+1);
                start = i+1; //to calculate size of next part
                curr_max = INT_MIN;
            }
        }
        
        return ans;
    }
};
