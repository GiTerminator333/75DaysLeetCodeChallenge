class Solution {
public:
    bool canSplit(vector<int>& nums,int largest,int &k) {
        int sum = 0;
        int splitCount = 1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] > largest) return false;
            if(sum + nums[i] > largest){
                splitCount++;
                sum = 0;
                sum += nums[i];
            }
            else{
                sum += nums[i];
            }
        }

        return splitCount <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        //more splits lesser largest sum
        //lowest largest sum = max ele of arr for k = arr.size()
        //highest largest sum = sum of arr for k = 1
        
        int lo = nums[0], hi = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > lo) lo = nums[i];
            hi += nums[i];
        }
        if(k == nums.size()) return lo;
        if(k == 1) return hi;

        int ans = -1;
        while(lo <= hi){
            int mid = (lo + hi)>>1;

            if(canSplit(nums, mid, k)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        return lo;
    }
};