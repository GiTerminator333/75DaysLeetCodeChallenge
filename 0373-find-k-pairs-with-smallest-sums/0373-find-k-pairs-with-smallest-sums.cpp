class Solution {
public:
    typedef pair<int, pair<int, int>> pi;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pi> pq;

        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                int sum = nums1[i] + nums2[j];

                if(pq.size() == k && sum >= pq.top().first) break;

                if(pq.size() <= k || sum <= pq.top().first){
                    pq.push({sum,{nums1[i], nums2[j]}});
                }

                if(pq.size() > k) pq.pop();
            }
        } 

        vector<vector<int>> v;

        while(!pq.empty()){
            pair<int, int> p = pq.top().second;
            pq.pop();

            v.push_back({p.first, p.second});
        }

        return v;
    }
};