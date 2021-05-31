/*

Rod cutting problem
Difficulty: MEDIUM
Avg. time to solve
40 min
Success Rate
75%
Problem Statement
Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod
and selling its pieces.
Note:
The sizes will range from 1 to ‘N’ and will be integers.
The sum of the pieces cut should be equal to ‘N’.
Consider 1-based indexing.
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases.
The next ‘2*T’ lines represent the ‘T’ test cases.

The first line of each test case contains an integer ‘N’ denoting the length of the rod.
The second line of each test case contains a vector ’A’, of size ‘N’ representing the cost of different lengths, 
where each index of the array is the sub-length and the element at that index is the cost for that sub-length.

Note: Since 1-based indexing is considered, the 0th index of the vector will represent sub-length 1 of the rod. 
Hence the ('N'-1)th index would represent the cost for the length ‘N’. 
Output Format
For each test case, print a single line that contains a single integer which is the maximum cost obtained by selling the pieces.
Constraints:
1 <= 'T' <= 50
1 <= 'N' <= 100
1 <= 'A'['I'] <= 100

Where ‘T’ is the total number of test cases, ‘N’ denotes the length of the rod, and 'A'['I'] is the cost of sub-length.

Time limit: 1 second.
Sample Input 1:
2
5
2 5 7 8 10
8
3 5 8 9 10 17 17 20
Sample Output 1:
12
24
Explanation Of Sample Input 1:
Test case 1:

All possible partitions are:
1,1,1,1,1           max_cost=(2+2+2+2+2)=10
1,1,1,2             max_cost=(2+2+2+5)=11
1,1,3               max_cost=(2+2+7)=11
1,4                 max_cost=(2+8)=10
5                   max_cost=(10)=10
2,3                 max_cost=(5+7)=12
1,2,2               max _cost=(1+5+5)=12    

Clearly, if we cut the rod into lengths 1,2,2 or 2,3, we get the maximum cost which is 12.
Test case 2:

Possible partitions are:
1,1,1,1,1,1,1,1         max_cost=(3+3+3+3+3+3+3+3)=24
1,1,1,1,1,1,2           max_cost=(3+3+3+3+3+3+5)=23
1,1,1,1,2,2             max_cost=(3+3+3+3+5+5)=22
and so on….

If we cut the rod into 8 pieces of length 1, for each piece 3 adds up to the cost. Hence for 8 pieces, we get 8*3 = 24.
Sample Input 2:
1
6
3 5 6 7 10 12
Sample Output 2:
18
*/


//KNAPSACK 0-1
//multiple instances can be included (unbounded knapsack)

int cutRod(vector<int> &price, int n) {
    // Write your code here
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j] = 0;
        }
    }
    
    
    //dp[i][j]  indicates what is max profit obtained by cutting rod of lenght "j" with (0 to i) pieces 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j>=i){ //if length of rod greater that current cut size
                dp[i][j] = max(dp[i-1][j] , price[i-1] + dp[i][j-i]); //check same row since , multiple instances are allowed
            }else{ //rod length is less that currect size of cut 
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][n];
}
