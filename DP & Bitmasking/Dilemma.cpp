/*
Dilemma
Send Feedback
Abhishek, a blind man recently bought N binary strings all of equal length .A binary string only contains '0's and '1's . The strings are numbered from 1 to N and all are distinct, but Abhishek can only differentiate between these strings by touching them. In one touch Abhishek can identify one character at a position of a string from the set. Find the minimum number of touches T Abhishek has to make so that he learn that all strings are different .
Constraints :
2<=N<=10
1<=|L|<=100 , L is length of the strings .
Input Format:
Line 1 : An Integer N, denoting the number of binary strings .
Next N lines : strings of equal length
Output Format:
Return the minimum number of touches
Sample Input :
2
111010
100100
Sample Output :
2
*/



#include<bits/stdc++.h>
using namespace std;
int dp[105][1 << 12];
int helper(int pos, vector<string> v, int mask)
{
    if (!(mask & (mask - 1)) && mask) //mask&mask-1 == 0 means only one bit set ie means only one string remaining therfore touches=0
        return 0;

    if (pos < 0 || mask == 0) 
        return 100000;  //conflict occurs if we return INT_MAX since at end if both results came as INT_MAX then min(INT_MAX,INT_MAX) problem occurs 

    if (dp[pos][mask])
        return dp[pos][mask];

    int mask1 = 0, mask2 = 0, touches = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (mask & (1<<i)) // (mask >> i) & 1   counting touches for all set bits and do work only if the bit is set 
        {
            touches++;
            if (v[i][pos] == '0') //strings having '0' as first character goes to mask1
            {
                mask1 |= (1 << i); 
            }
            else
            {
                mask2 |= (1 << i);//strings having '1' as first character goes to mask2
            }
        }
    }
	int ans1 = touches + helper(pos-1,v,mask1) + helper(pos-1,v,mask2); //including 0th index and calculating for two masks
    int ans2 = helper(pos-1,v,mask);  //not including 0th index
    int ans = min(ans1,ans2);
    dp[pos][mask] = ans;
    return ans;
}

int minimumTouchesRequired(int n, vector<string> v)
{
    int mask = (1 << n) - 1; //initially all bits set ex: if n=9   : 111111111
    return helper(v[0].size() - 1, v, mask);
}
