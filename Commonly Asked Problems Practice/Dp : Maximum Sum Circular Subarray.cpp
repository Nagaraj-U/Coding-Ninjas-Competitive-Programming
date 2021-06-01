/*
Given a circular array circ of integers represented by nums, find the maximum possible sum of a non-empty subarray of circ.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, circ[i] = nums[i] when 0 <= i < nums.length, and circ[i+nums.length] = circ[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer nums at most once.  (Formally, for a subarray circ[i], circ[i+1], ..., circ[j], there does not exist i <= k1, k2 <= j with k1 % nums.length = k2 % nums.length.)

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: nums = [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: nums = [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: nums = [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
 

Note:

-30000 <= nums[i] <= 30000
1 <= nums.length <= 30000
*/



class Solution {
public:
    
    int getMaxSubarraySum(vector<int> nums,int n)
    {
        int curr_max = 0;
        int best_max = INT_MIN;
        for(int i=0;i<n;i++){
            curr_max += nums[i];
            if(curr_max <= 0){
                curr_max = 0;
            }
            best_max = max(best_max,curr_max);
        }
        cout <<"best max" << best_max << endl;
        return best_max;
    }
    
    int getMinSubarraySum(vector<int> nums,int n)
    {
        int curr_min = 0;
        int best_min = INT_MAX;
        for(int i=0;i<n;i++){
            curr_min += nums[i];
            if(curr_min >= 0){
                curr_min = 0;
            }
            best_min = min(best_min,curr_min);
        }
        cout << "best min " << best_min << endl;
        return best_min;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        cout << "sum" << sum << endl;
        int minSubarray = getMinSubarraySum(nums,n);
        int maxSubarray = getMaxSubarraySum(nums,n);
        
        int max_min = INT_MIN;
        if(sum == minSubarray){ 
            for(int i=0;i<n;i++){
                max_min = max(max_min,nums[i]); //max negative element among array
            }
            if(maxSubarray == 0){ //all elements are negative
                return max_min;
            }else{   //some positive elements present
                return maxSubarray;
            }
        }
        int ans = max(maxSubarray , sum-minSubarray);
        return ans;
    }
};
