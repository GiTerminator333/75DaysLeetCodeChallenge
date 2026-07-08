class Solution {
public:
    vector<int> dp;
    int solve(vector<int> &nums, int target){ 
        if(target == 0){
            return dp[0];
        }

        if(dp[target] != -1) return dp[target];

        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            if(target < nums[i]) continue;
            ans += solve(nums, target - nums[i]);
        }

        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target + 1, -1);
        dp[0] = 1;
        return solve(nums, target);
    }
};