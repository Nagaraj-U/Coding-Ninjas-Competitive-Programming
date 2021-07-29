/*
Share
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
Accepted
219.8K
Submissions
551.2K
*/

/*
for majority element condition :  count(majority) > ceil(n/3) , atmost 2 majority elments present
ex : n = 8 , n/3 = 2 , 1 1 1 2 2 2 3 3 (2 majrity elements)
ex : n = 11 , n/3 = 3 , 1 1 1 1 2 2 2 2 3 3 3 ( 2 majority)

use boyer mores voting algo
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int majority1 = -1 , majority2 = -1;
        int count1 = 0 , count2 = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == majority1){
                count1++;
            }else if(nums[i] == majority2){
                count2++;
            }else if(count1 == 0){
                majority1 = nums[i];
                count1 = 1;
            }else if(count2 == 0){
                majority2 = nums[i];
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
               
        }
        count1 = count2 = 0;
        //check count of both majority since , both of majority 1 and 2 may be poiniting to same elements
        for(int i=0;i<nums.size();i++){
            if(nums[i] == majority1){
                count1++;
            }else if(nums[i] == majority2){
                count2++;
            }
        }
        
        if(count1 > nums.size()/3)
            ans.push_back(majority1);
        if(count2 > nums.size()/3)
            ans.push_back(majority2);
        return ans;
    }
};
