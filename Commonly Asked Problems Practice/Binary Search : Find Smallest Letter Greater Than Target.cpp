/*
Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.

Note that the letters wrap around.

For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.
 

Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Example 3:

Input: letters = ["c","f","j"], target = "d"
Output: "f"
Example 4:

Input: letters = ["c","f","j"], target = "g"
Output: "j"
Example 5:

Input: letters = ["c","f","j"], target = "j"
Output: "c"
 

Constraints:

2 <= letters.length <= 104
letters[i] is a lowercase English letter.
letters is sorted in non-decreasing order.
letters contains at least two different characters.
target is a lowercase English letter.
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char target) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int ans = -1;
        while(start<=end){
            int mid = (start+end)/2;
            if(arr[mid] > target){
                ans = arr[mid];
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        
        if(ans == -1){ //if target is last element in array , wrap it
            ans = arr[0];
        }
        
        return (char)ans;
    }
};
