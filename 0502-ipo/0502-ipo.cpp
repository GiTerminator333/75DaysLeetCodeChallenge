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
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        for(int i=0; i<profits.size(); i++){
            pq.push({capital[i], profits[i]});
        }

        int aukaat = w; //tracks running net capital

        priority_queue<pi> maxh; //for max profit;
        while(k--){
            while(!pq.empty() && pq.top().first <= aukaat){
                pi p = pq.top();
                pq.pop();
                maxh.push({p.second, p.first});
            }
            
            if(!maxh.empty()){
                aukaat += maxh.top().first;
                maxh.pop();
            }
        }

        return aukaat;
    }
};