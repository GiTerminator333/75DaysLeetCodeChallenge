class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //sliding window doesnt work as arr has -ve val, use prefix sum
        //instead of finding sum = k, find the occurence of (prefix sum - k)
        // preSum = (preSum - k) + k
        //isse yeh hoga ke seedha seedha prefix sum se ham beech wale subarray ki bhi occurences nikal lenge (else bhot difficult hota yeh) ->Striver

        unordered_map<int, int> mp; // (prefix sum, occurence of prefix sum)
        int preSum = 0; //prefix sum
        int count = 0;
        mp[0] = 1;  //inital occurence of 0 sum

        for(int i=0; i<nums.size(); i++){
            preSum += nums[i];
            count += mp[preSum - k];    //finding occurence or k subarr from curr preSum arrangement
            mp[preSum]++;   //curr preSum value occurence 
        }

        return count;
    }
};