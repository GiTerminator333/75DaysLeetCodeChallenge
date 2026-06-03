class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 1) return nums;
        vector<int> v;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto &[key, val] : mp){
            if(val > nums.size()/3){
                v.push_back(key);
            }
        }

        return v;
    }
};