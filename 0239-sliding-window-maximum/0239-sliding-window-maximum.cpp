class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) return nums;
        deque <int> dq;
        vector <int> ans;

        for(int i = 0; i < nums.size(); i++){
            //eliminate smaller ele
            while(!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
            dq.push_back(i);    //pushing current element
            //eliminate ele idx coming before starting idx of window
            while(dq.front() < i-k+1) dq.pop_front();   
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }

        return ans; 
    }
};