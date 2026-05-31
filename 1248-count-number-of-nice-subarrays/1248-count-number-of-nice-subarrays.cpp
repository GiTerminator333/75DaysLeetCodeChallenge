class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            nums[i] = (nums[i]%2);
        }

        unordered_map<int, int> mp;
        int preSum = 0;
        int count = 0;
        mp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            preSum += nums[i];
            count += mp[preSum - k];
            mp[preSum]++;
        }

        return count;
    }
};