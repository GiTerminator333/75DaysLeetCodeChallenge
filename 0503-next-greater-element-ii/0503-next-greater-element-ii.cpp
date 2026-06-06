class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        for(int i=0; i<n; i++){
            nums.push_back(nums[i]);
        }

        stack<int> st;
        for(int i=nums.size() - 1; i>=0; i--){
            int nge = -1;
            while(!st.empty() && st.top() <= nums[i]) st.pop();
            if(!st.empty()) nge = st.top();
            if(i < n) v[i] = nge;
            st.push(nums[i]);
        }

        return v;
    }
};