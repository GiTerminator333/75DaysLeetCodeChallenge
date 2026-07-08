class Solution {
public:
    // vector<int> dp;
    // int solve(vector<int> &nums, int target){ 
    //     if(target == 0){
    //         return dp[0];
    //     }

    //     if(dp[target] != -1) return dp[target];

    //     int ans = 0;
    //     for(int i = 0; i<nums.size(); i++){
    //         if(target < nums[i]) continue;
    //         ans += solve(nums, target - nums[i]);
    //     }

    //     return dp[target] = ans;
    // }
    int combinationSum4(vector<int>& nums, int target) {
        // dp.resize(target + 1, -1);
        // dp[0] = 1;
        // return solve(nums, target);

        vector<unsigned int> dp(target + 1);
        dp[0] = 1;

        for(int i=1; i<dp.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(nums[j] > i) continue;

                dp[i] += dp[i - nums[j]];
            }
        }

        return dp[target];
    }
};