/*

Count Binary Substrings


Share
Give a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these 
substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

 

Example 1:

Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:

Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'
*/


class Solution {
public:
    int countBinarySubstrings(string S) {
//         int count = 0;
//         int n = s.length();
//         for(int i=0;i<n-1;i++){
//             int sum = 1;
//             bool flag = true;
//             for(int j=i+1;j<n;j++){
//                 if(s[i] == s[j] && flag){
//                     sum++;
//                 }else{
//                     flag = false;
//                     if(s[i] == s[j] && flag == false){
//                         break;
//                     }
//                     if(flag == false && s[i] != s[j]){
//                         sum -= 1;
//                         if(sum == 0){
//                             count++;
//                             break;
//                         }
//                     }
                    
//                 }
//             }
            
//         }
        
//         return count;
        
        
        
    int ans = 0;
 
    int i = 0;
    int n = S.length();
    // Traversing the string
    while (i < n) {
 
        // Count of consecutive
        // 0's & 1's
        int cnt0 = 0, cnt1 = 0;
 
        // Counting subarrays of
        // type "01"
        if (S[i] == '0') {
 
            // Count the consecutive
            // 0's
            while (i < n && S[i] == '0') {
                cnt0++;
                i++;
            }
 
            // If consecutive 0's
            // ends then check for
            // consecutive 1's
            int j = i;
 
            // Counting consecutive 1's
            while (j < n && S[j] == '1') {
                cnt1++;
                j++;
            }
        }
 
        // Counting subarrays of
        // type "10"
        else {
 
            // Count consecutive 1's
            while (i < n && S[i] == '1') {
                cnt1++;
                i++;
            }
 
            // If consecutive 1's
            // ends then check for
            // consecutive 0's
            int j = i;
 
            // Count consecutive 0's
            while (j < n && S[j] == '0') {
                cnt0++;
                j++;
            }
        }
 
        // Update the total count
        // of substrings with
        // minimum of (cnt0, cnt1)
        ans += min(cnt0, cnt1);
    }
 
    // Return answer
    return ans;
    }
    
};
