class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int l=0, r=0;
        int sum = 0;

        int maxi = 0;
        while(r < nums.size()){
            sum += nums[r];

            while(st.find(nums[r]) != st.end()){
                sum -= nums[l];
                st.erase(nums[l]);
                l++;
            }
            
            maxi = max(maxi, sum);
            st.insert(nums[r]);
            r++;
        } 


        return maxi;
    }
};