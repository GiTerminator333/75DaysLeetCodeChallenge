class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int limit = -1;
    KthLargest(int k, vector<int>& nums) {
        for(int &i : nums){
            if(pq.size() == k && i < pq.top()) continue; 
            pq.push(i);
            if(pq.size() > k) pq.pop();
        }
        limit = k;
    }
    
    int add(int val) {
        if(pq.size() == limit && pq.top() < val){
            pq.pop();
            pq.push(val);
        }
        else if(pq.size() < limit){
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */