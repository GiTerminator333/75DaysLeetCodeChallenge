class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> mp;
        int l = 0, r = 0;

        int maxi = -1;
        while(r < nums.size()){
            mp[nums[r]]++;

            //shrink
            int smallest = mp.begin()->first, largest = (--mp.end())->first;

            while(!mp.empty() && largest - smallest > limit){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                smallest = mp.begin()->first;
                largest = (--mp.end())->first;
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};