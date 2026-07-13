class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //min subarr with sum = 5
        int l = 0, r = 0;
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        int len = 0;
        bool isPossible = false;
        while(r < nums.size()){
            sum += nums[r];

            while(l < r && tot - sum < x){
                sum -= nums[l++];
            }

            if(tot - sum == x){
                len = max(len, r - l + 1);
            }

            r++;
        }

        // if(len == 0) return -1;
        if(len == 0 && tot != x) return -1;
        return nums.size() - len;
   }
};