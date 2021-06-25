//generate all permuataion of number

class Solution {
public:
    
    void helper(vector<int> &nums,int start,vector<vector<int>> &res){
        if(start == nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i=start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            helper(nums,start+1,res);
            swap(nums[start],nums[i]);
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int start = 0;
        helper(nums,start,res);
        return res;
    }
};
