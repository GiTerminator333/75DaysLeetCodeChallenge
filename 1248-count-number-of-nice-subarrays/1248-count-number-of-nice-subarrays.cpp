class Solution {
public:
    int countSubUpto(vector<int>& nums, int val){
        //finding all valid subarrays with sum <= val
        if(val < 0) return 0;
        int l=0, r=0;
        int count = 0;
        int tot = 0;

        while(r < nums.size()){
            if(nums[r]%2) tot++;

            while(tot > val){
                if(nums[l]%2) tot--;
                l++;
            }
            
            count += (r-l+1); //count all possible subarrays <= val
            r++;
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countSubUpto(nums,k) - countSubUpto(nums,k - 1);
    }
};