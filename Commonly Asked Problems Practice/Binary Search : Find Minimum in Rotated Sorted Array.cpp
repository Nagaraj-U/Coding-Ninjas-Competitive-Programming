


/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.
*/







//APPROACH


/*
Note : when a sorted array is rotated by some "k" times ,  for every element in rotated array , one of its\left subarray OR right subarray is sorted

Minimum element : which is lesser than both of its neighbours
Move to left subarray : if right subarray is sorted
Move to right subarry : if left is sorted

At any instance if both left and right subarray are sorted then , return "start"  , example : [3,4,5,6,0,1,2]

Number of times array rotated is given by : index of minimum element (index of min element is 0 in orignal array)
*/

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int ans = -1;
        int ansIndex = -1;
        while(start<=end){
            int mid = (start + end)/2;
            int next = (mid+1)%n;
            int prev = (mid-1+n)%n;//managing index out of bound
            if(arr[mid] < arr[next] && arr[mid] < arr[prev]){
                ans = arr[mid];
                ansIndex = mid;
                break;
            }
            else if(arr[start] <= arr[mid] && arr[mid] <= arr[end]){ //array sorted in both sides
                ans = arr[start];
                ansIndex = start;
                break;
            }
            else if(arr[start] <= arr[mid]){ //left is sorted ? then search in right array
                start = mid+1;
            }else{ //right sorted ? search in left array subarray
                end = mid-1;
            }
        }
        
        cout << "number of times array rotated is : " << ansIndex << endl;
        return ans;
    }
};
