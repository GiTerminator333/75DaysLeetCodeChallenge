class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp;
        stack<int> st;
        mp[nums2.back()] = -1;
        st.push(nums2.back());
        for(int i=nums2.size() - 2; i>=0; i--){
            int nge = -1;
            while(!st.empty() && st.top() <= nums2[i]) st.pop();
            if(!st.empty()) nge = st.top();
            mp[nums2[i]] = nge;
            st.push(nums2[i]);
        }

        for(int i=0; i<nums1.size(); i++){
            nums1[i] = mp[nums1[i]];
        }

        return nums1;
    }
};