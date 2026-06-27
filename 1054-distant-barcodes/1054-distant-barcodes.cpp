class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> mp;

        for(int i=0; i<barcodes.size(); i++){
            mp[barcodes[i]]++;
        }

        priority_queue<pair<int, int>> pq;

        for(auto &[key, freq] : mp){
            pq.push({freq, key});
        }

        int i=0, n = barcodes.size();

        while(!pq.empty() && i < n){
            auto p = pq.top();
            pq.pop();
            if(i > 0 && barcodes[i-1] == p.second){
                auto s = pq.top();
                pq.pop();
                barcodes[i] = s.second;
                s.first--;
                if(s.first > 0) pq.push(s);
                pq.push(p);
            }
            else{
                barcodes[i] = p.second;
                p.first--;
                if(p.first > 0) pq.push(p);
            }
            i++;
        }

        return barcodes;
    }
};