/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., 
nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
*/

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int start = 0;
        int end= n-1;
        int idx = -1;
        while(start<=end){
            int mid = (start+end)/2;
            if(arr[mid] == target){
                idx = mid;
                return idx;
            }else if(arr[start] <= arr[mid]){
                if( target <= arr[mid] && target >= arr[start]){
                    end = mid-1;
                }else{
                    start = mid+1;
                }
            }else{
                if(target >= arr[mid] && target <= arr[end]){
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }
        }
        
        return idx;
    }
};
