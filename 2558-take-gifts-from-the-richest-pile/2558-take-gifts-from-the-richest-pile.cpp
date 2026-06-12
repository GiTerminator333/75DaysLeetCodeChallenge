class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for(int x : gifts){
            pq.push(x);
        }

        while(k--){
            int val = pq.top();
            pq.pop();

            int y = (int)sqrt(val);
            pq.push(y);
        }

        long long tot = 0;
        while(pq.size()){
            tot += pq.top();
            pq.pop();
        }

        return tot;
    }
};