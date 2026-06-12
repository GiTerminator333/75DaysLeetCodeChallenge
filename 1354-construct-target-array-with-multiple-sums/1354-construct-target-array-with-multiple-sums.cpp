class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq;
        long long sum = 0;

        for (int x : target) {
            pq.push(x);
            sum += x;
        }

        while (pq.top() > 1) {
            long long maxi = pq.top();
            pq.pop();

            long long rest = sum - maxi;

            if (rest == 1) return true;
            if (rest == 0 || maxi <= rest) return false;

            long long prev = maxi % rest;

            if (prev == 0) return false;

            sum = rest + prev;
            pq.push(prev);
        }

        return true;
    }
};