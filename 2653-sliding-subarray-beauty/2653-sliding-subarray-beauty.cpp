class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        // priority_queue<pair<int, int>> pq;
        //cannot use priority queue it will give error
        int l = 0, r = 0;
        vector<int> ans;
        map<int, int> mp;

        while(r < n){
            //expand
            mp[nums[r]]++;

            //shrink
            if(r - l + 1 > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }

            if(r - l + 1 == k){
                int beauty = 0;
                int ct = 0;
                for(auto &[key, freq] : mp){
                    ct += freq;
                    if(ct >= x){
                        beauty = key;
                        break;
                    }
                }
                if(beauty >= 0) beauty = 0;
                ans.push_back(beauty);
            }   
            r++;
        }

        return ans;
    }
};