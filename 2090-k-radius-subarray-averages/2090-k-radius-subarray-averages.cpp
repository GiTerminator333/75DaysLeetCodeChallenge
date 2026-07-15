class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> avgs(nums.size(), -1);
        int l = 0, r = 0;
        long long sum = 0;
        if(k > nums.size()) return avgs;
        if(k == 0) return nums;

        while(r < nums.size()){
            sum += nums[r];

            if(r - l + 1 > 2*k + 1){
                sum -= nums[l];
                l++;
            }

            if(r - l + 1 == 2*k + 1) avgs[r - k] = sum / (2 * k + 1);
            r++;
        }

        return avgs;
    }
};