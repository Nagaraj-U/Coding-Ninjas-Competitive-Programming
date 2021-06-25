class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    
        vector<vector<int>> res;

        int n = pow(2,nums.size());//total range till 2^n

        for(int mask=0;mask<n;mask++){
            vector<int> temp;
            for(int j=0;j<=10;j++){ //max bit required 10 , given is question num<=10
                if(mask & (1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            res.push_back(temp);
        }
        return res;

    }
};




//using backtracking

#include<bits/stdc++.h>
using namespace std;

void helper(string str,int start,string temp,vector<string> &ans){
    
    ans.push_back(temp);

    for(int i=start;i<str.length();i++){
        temp.push_back(str[i]);
        helper(str,i+1,temp,ans);
        temp.pop_back();
    }

    return;
}

int main()
{
    string str;
    cin >> str;
    vector<string> ans;
    string temp = "";
    helper(str,0,temp,ans);
    for(int i=0;i<ans.size();i++){
        string curr = ans[i];
        cout << curr << endl;
    }

    return 0;
}


