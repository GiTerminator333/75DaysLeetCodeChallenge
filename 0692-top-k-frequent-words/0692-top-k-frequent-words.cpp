struct cmp{
    bool operator()(const auto &a, const auto &b){
        if(a.first != b.first){
            return a.first > b.first;   //minheap
        }
        return a.second < b.second; //maxheap
    }
};
class Solution {
public:
    typedef pair<int, string> pis;
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string s : words){
            mp[s]++;
        }

        priority_queue<pis, vector<pis>, cmp> pq;

        for(const auto &m : mp){
            if(pq.size() == k && pq.top().first > m.second){
                continue;
            }
            int f = m.second;
            string s = m.first;
            pq.push({f, s});
            if(pq.size() > k) pq.pop();
        }

        vector<string> v;
        while(!pq.empty()){
            v.insert(v.begin(),pq.top().second);
            pq.pop();
        }

        return v;
    }
};