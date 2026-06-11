class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return findSubarrays(nums, k) - findSubarrays(nums, k-1);
    }

    unordered_map<int, int> mp;
    int findSubarrays(vector<int> &v, int k){
        int count = 0, l=0, r=0;

        while(r < v.size()){
            mp[v[r]]++;

            while(mp.size() > k){
                mp[v[l]]--;
                if(mp[v[l]] == 0) mp.erase(v[l]);

                l++;
            }

            count += r - l + 1;

            r++;
        }

        mp.clear();

        return count;
    }
};