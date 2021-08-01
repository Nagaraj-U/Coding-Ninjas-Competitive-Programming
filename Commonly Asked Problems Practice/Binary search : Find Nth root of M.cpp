/*
You are given 2 numbers (n , m); the task is to find n√m (nth root of m).
 

Example 1:

Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9
Example 2:

Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not
integer.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function NthRoot() which takes n and m as input parameter and returns the nth root of m. 
If the root is not integer then returns -1.
 

Expected Time Complexity: O(n* log(m))
Expected Space Complexity: O(1)
 

Constraints:
1 <= n <= 30
1 <= m <= 109
*/
class Solution {
	public:
	
	
//time : n * log m

	long power(int val,int n){
	    long ans = 1;
	    for(int i=0;i<n;i++){
	        ans = ans * val;
	        if(ans >= INT_MAX){//since m value is max 10^9 (given)
	            return INT_MAX;
	        }
	    }
	    return ans;
	}
	
	int NthRoot(int n, int m)
	{
	    // Code here.
	    
	    //root always lies between 1 to m
	    int start = 1;
	    int end = m;
	    while(start <= end){
	        int mid = (start+end)/2;
	        long mul = power(mid,n);
	        if(mul == m){
	            return mid;
	        }else if(mul < m){
	            start = mid+1;
	        }else{
	            end = mid-1;
	        }
	    }
	    return -1;
	}




//if the question is to find nearest nth root of number , including double values also
// if we asked to find upto d decimal places
//n * log (m * 10 ^ d)
/*
1 to 3
upto 4 decimal places
1.0000,1.0001 ......1.1111   (total counts : 10^4)

for m values m*10^d
*/

// double power(double val,int n){
// 	    double ans = 1;
// 	    for(int i=0;i<n;i++){
// 	        ans = ans * val;
// 	        if(ans >= INT_MAX){//since m value is max 10^9 (given)
// 	            return INT_MAX;
// 	        }
// 	    }
// 	    return ans;
// }

// int NthRoot(int n, int m)
// 	{
// 	    // Code here.
	    
// 	    //root always lies between 1 to m
// 	    double start = 1;
// 	    double end = m;
// 	    double diff = 1e-4;
// 	    while(end- start >= diff){
// 	        double mid = (start+end)/2;
// 	        double mul = power(mid,n);
	        
// 	        if(mul <= m){
// 	            start = mid;
// 	        }else{
// 	            end = mid;
// 	        }
// 	    }
	    
// 	    cout << "root" << start << " " << power(start,n) << endl;
	    
// 	    return -1;
// 	} 

};
