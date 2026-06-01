class Solution {
public:
    int countSubUpto(vector<int>& nums, int val){
        //finding all valid subarrays with sum <= val
        if(val < 0) return 0;
        int l=0, r=0;
        int count = 0;
        int sum = 0;
        while(r < nums.size()){
            sum += nums[r];
            while(sum > val){
                sum -= nums[l];
                l++;
            }
            
            count += (r-l+1); //count all possible subarrays <= val
            r++;
        }

        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubUpto(nums,goal) - countSubUpto(nums,goal - 1);
        //normal sliding window not possible here as adding 0 doesnt change the subarray sum
        //this leads to extra subarray patterns which are missed in normal aliding window
        //dry run testcase 1
        //hence we will find
        //subarray sum k = (all subarray with sum <= k) - (all subarray with sum <= k - 1)
    }
};