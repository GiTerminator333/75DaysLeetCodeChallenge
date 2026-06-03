class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l=0, r=0;
        long long maxi = 0, sum = 0;
        while(r < nums.size()){
            mp[nums[r]]++;
            sum += (1LL * nums[r]);

            while(r-l+1 > k || mp[nums[r]] > 1){
                sum -= (1LL * nums[l]);
                mp[nums[l]]--;
                l++;
            }
                
            if(r-l+1 == k) maxi = max(maxi, sum);

            r++;
        }

        return maxi;
    }
};