class Solution {
public:
    bool isValid(vector<int> &v, int &k, int val){
        for(int i=0; i<v.size(); i++){
            if(abs(v[i] - val) == k) return false;
        }

        return true;
    }

    int helper(vector<int> &nums, vector<int> &v, int &k){
        if(nums.size() == 0){
            return 1;
        }

        int count = 0;
        int x = nums[0];
        nums.erase(nums.begin());

        //not take
        count += helper(nums, v, k);
        //take

        if(isValid(v, k, x)){
            v.push_back(x);
            count += helper(nums, v, k);
            v.pop_back();
        }

        nums.insert(nums.begin(), x);

        return count;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> v;
        return helper(nums, v, k) - 1;
    }
};