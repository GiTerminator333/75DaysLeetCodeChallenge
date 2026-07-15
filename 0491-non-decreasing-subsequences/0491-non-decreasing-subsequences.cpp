class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> &nums, vector<int> &v, int idx){
        if(idx == nums.size()){
            if(v.size() >= 2){
                ans.push_back(v);
            }
            return;
        }

        //take
        if(v.size() == 0 || nums[idx] >= v.back()){
            v.push_back(nums[idx]);
            helper(ans,nums, v, idx + 1);
            v.pop_back();
        }
        //not take
        if(v.size() == 0 || v.back() != nums[idx]){
            helper(ans,nums, v, idx + 1);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans, nums, v, 0);
        return ans;
    }
};