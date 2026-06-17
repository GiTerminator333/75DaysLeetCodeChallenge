// struct cmp{
//     bool operator()(cont auto &a, const auto &b){
//         if(a.first != b.first){
//             return a.first > b.first;
//         }
//         return a.second > b.first;
//     }
// }
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

        priority_queue<pi> maxh; //for max profit;
        int idx = 0; //iterates v
        while(k--){
            while(idx < v.size() && v[idx].first <= aukaat){
                pi p = v[idx];
                maxh.push({p.second, p.first});
                idx++;
            }

            if(!maxh.empty()){
                aukaat += maxh.top().first;
                maxh.pop();
            }
        }

        return aukaat;
    }
};