/*
Ninja has been given a string ‘STR’ containing either ‘{’ or ‘}’. 'STR’ is called valid if all the brackets are balanced. Formally for each opening bracket, there must be a closing bracket right to it.
For Example: “{}{}”, “{{}}”, “{{}{}}” are valid strings while “}{}”, “{}}{{}”, “{{}}}{“ are not valid strings.



Ninja wants to make ‘STR’ valid by performing some operations on it. In one operation, he can convert ‘{’ into ‘}’ or vice versa and the cost of one such operation is 1.
Your task is to help Ninja determine the minimum cost to make ‘STR’ valid.
For Example: Minimum operations to make ‘STR’ = “{{“ valid is 1. In one operation, we can convert ‘{’ at index ‘1’ (0-based indexing) to ‘}’. The ‘STR’ now becomes "{}" which is a valid string.



Note: Return -1 if it is impossible to make ‘STR’ valid.
Input Format:
The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The only line of each test case contains a string 'STR'.
Output Format:
For each test case, print the minimum cost needed to make ‘STR’ valid.

Print -1 if it is impossible to make ‘STR’ valid.

Print the output of each test case in a separate line.
Note:
You are not required to print the expected output, it has already been taken care of. Just implement the function.
Constraints:
1 <= T <= 100
0 <= |STR| <= 10^5
STR[i] = ‘{’ or ‘}’

Where ‘T’ is the number of test cases, ‘STR’ is the given string and |STR| denotes the length of ‘STR’.

Time Limit: 1 sec 
Sample Input 1:
2
{{{}
{{}{}}
Sample Output 1:
1
0
Explanation Of Sample Input 1:
For the first test case:
The two valid strings that can be obtained from  ‘STR’ using minimum operations “{{}}”   and “{}{}”. Ninja can transform ‘STR’ to “{{}}” by performing the following operations:
Convert ‘{’ at index 2 to ‘}’.

Ninja can transform ‘STR’ to “{}{}” by performing the following operations:
Convert ‘{‘ at index 1 to ‘}’.
The minimum number of operations in transforming ‘STR’ to either of the two valid strings is 1.So, the total cost is 1.

For the second test case:
Given ‘STR’ is already valid so the minimum number of 
operations required is 0.
So, the total cost is 0.
Sample Input 2:
3
{}}{}}
{{{{
{{{}}
Sample Output 2:
1
2
-1
Explanation Of Sample Input 2:
For the first test case:
The two valid strings that can be obtained from ‘STR’ using 
minimum operations are “{{}{}}” and “{}{{}}”. 
Ninja can transform ‘STR’ to “{{}{}}” by performing the following 
operations:
Convert ‘}’ at index 1 to ‘{’.

Ninja can transform ‘STR’ to “{}{{}}” by performing the following 
operations:
Convert ‘}’ at index 2 to ‘{’.
The minimum number of operations in transforming ‘STR’ to either of the two valid strings is 1 so, the total cost is 1.


For the second test case:
The two valid strings that can be obtained from ‘STR’ using 
minimum operations are “{}{}” and “{{}}”. Ninja can transform 
‘STR’ to “{}{}” by performing the following operations:
Convert ‘{’ at index 1 to ‘}’.
Convert ‘{’ at index 3 to ‘}’.


Ninja can transform ‘STR’ to “{{}}” by performing the following 
operations:
Replace ‘{’ at index 2 by ‘}’.
Replace ‘{’ at index 3 by ‘}’.
The minimum number of operations in transforming ‘STR’ to either of the two beautiful strings is 2. So, the total cost is 2.

For the third test case:
It is impossible to make ‘STR’ valid so return -1.

*/





/*
APPROACH

1.push all opening brackets to stack

2. when you find closing bracket pop opening bracket from stack , if stack 
is empty then mismatch so change to closing to opening (increase count) and then push to stack

3. if stack is not empty (which contain only opening brackets)
pop 2 elements at a time change one of them to closing and increase count
*/

#include<stack>
int findMinimumCost(string str) {
  // Write your code here
    int n = str.size();
    if(n%2 == 1){
        return -1;
    }
    stack<char> s;
    int count = 0;
    for(int i=0;i<n;i++){
        if(str[i] == '{'){
            s.push('{');
        }else{
            if(s.empty()){
                count++;
                s.push('{');
            }else{
                s.pop();
            }
        }
    }
    while(!s.empty()){
        count++;
        s.pop();
        s.pop();
    }
    return count;
    
}
