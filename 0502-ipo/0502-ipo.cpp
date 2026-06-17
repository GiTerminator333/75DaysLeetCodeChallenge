class Solution {
public:
    typedef pair<int, int> pi;
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pi> v; //{cap, profit}

        for(int i=0; i<profits.size(); i++){
            v.push_back({capital[i], profits[i]});
        }

        sort(v.begin(), v.end());

        int aukaat = w; //tracks running net capital

        priority_queue<int> maxh; //for max profit;
        int idx = 0; //iterates v
        while(k--){
            while(idx < v.size() && v[idx].first <= aukaat){
                maxh.push(v[idx].second);
                idx++;
            }

            if(!maxh.empty()){
                aukaat += maxh.top();
                maxh.pop();
            }
        }

        return aukaat;
    }
};