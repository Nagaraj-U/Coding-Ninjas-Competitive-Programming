
/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-231 <= nums[i] <= 231 - 1
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/


//Moore Voting algorithm

//It works because major element present more than (n/2) times ,
//worst case 1 : count never became zero
//worst case 2 : major element present at alternate position , then last element should be major

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int major = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] == major){
                count++;
            }else{
                count--;
                if(count == 0){
                    count = 1;
                    major = nums[i];
                }
            }
        }
        
        return major;
    }
};

/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
        priority_queue<pair<int,int>> pq;
        for(auto i : m){
            pq.push({i.second,i.first});
        }
        return pq.top().second;
    }
};
*/
