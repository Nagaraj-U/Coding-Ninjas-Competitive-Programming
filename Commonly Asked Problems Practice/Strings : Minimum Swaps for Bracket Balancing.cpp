/*
Minimum Swaps for Bracket Balancing 

You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced if it can be represented
in the for S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. 
Calculate the minimum number of swaps necessary to make a string balanced.
Note - Strings S1 and S2 can be empty.

 

Example 1:

Input  : []][][
Output : 2
Explanation :
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

 

Example 2:

Input : [[][]]
Output : 0 
Explanation:
String is already balanced.
 

Your Task:

You don't need to read input or print anything. Your task is to complete the function minimumNumberOfSwaps()
which takes the string S and return minimum number of operations required to balance the bracket sequence.

 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

 

Constraints:

1<=|S|<=100000
*/

class Solution{   
public:
    int minimumNumberOfSwaps(string str){
        // code here 
        vector<int> pos;
        int n = str.length();
        for(int i=0;i<n;i++){
            if(str[i] == '['){//to maintain index of opening brackets
                pos.push_back(i);
            }
        }
        
        int ans = 0;
        int index = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            if(str[i] == '['){
                count++;
                index++;
            }else{
                count--;
                
                if(count < 0){
                    ans += (pos[index] - i);
                    swap(str[i],str[pos[index]]);
                    index++;
                    count = 1;//dont set count to 0 , as we try to match current opening to next closing bracket not for current index closing bracket
                }   //by doing this we are trying to match nearest brackets and minimizing the answer
            }
        }
       
        return ans;
    }
};
