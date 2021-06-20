/*
Given an array arr of n elements which is first increasing and then may be decreasing, find the maximum element in the array.
Note: If the array is increasing then just print then last element will be the maximum value.

Example 1:

Input: 
n = 9
arr[] = {1,15,25,45,42,21,17,12,11}
Output: 45
Explanation: Maximum element is 45.
Example 2:

Input: 
n = 5
arr[] = {1, 45, 47, 50, 5}
Output: 50
Explanation: Maximum element is 50.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function findMaximum() which takes the array arr[], 
and n as parameters and returns an integer denoting the answer.

Expected Time Complexity: O(logn)
Expected Auxiliary Space: O(1)

Constraints:
3 ≤ n ≤ 106
1 ≤ arri ≤ 106

*/


class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    int start = 0;
	    int end = n-1;
	    int ans = -1;
	    while(start <= end){
	        int mid = (start+end)/2;
	        int left = mid-1;
	        int right = mid+1;
	        int leftval,rightval;
	        if(right >= n){
	            rightval = INT_MIN;
	        }else{
	            rightval = arr[right];
	        }
	        if(left < 0){
	            leftval = INT_MIN;
	        }else{
	            leftval = arr[left];
	        }
	        
	        if(arr[mid] > leftval and arr[mid] > rightval){
	            return arr[mid];
	        }else if(arr[mid] > rightval){
	            end = mid-1;
	        }else{
	            start = mid+1;
	        }
	        
	    }
	    
	    return ans;
	}
};
