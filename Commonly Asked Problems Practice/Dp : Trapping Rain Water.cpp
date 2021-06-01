

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105
Accepted
*/


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2){
            return 0;
        }
        int* left = new int[n];
        int* right = new int[n];
        left[0] = 0;
        right[n-1] = 0;
        int left_max = height[0];
        for(int i=1;i<n;i++){
            left[i] = left_max;
            left_max = max(height[i],left_max);
        }
        
        int right_max = height[n-1];
        for(int i=n-2;i>=0;i--){           
            right[i] = right_max;
            right_max =max(right_max,height[i]);
        }
        
        int ans = 0;
        for(int i=1;i<n-1;i++){
            if(height[i]<left[i] and height[i]<right[i])
                ans += min(left[i],right[i]) - height[i];
        }
        
        return ans;
    }
};
