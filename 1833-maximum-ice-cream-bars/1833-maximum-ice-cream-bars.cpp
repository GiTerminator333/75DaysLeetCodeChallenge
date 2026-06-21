class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int i = 0;
        int cnt = 0;
        while(i < costs.size() && coins){
            if(coins < costs[i]) break;
            coins -= costs[i];
            cnt++;
            i++;
        }

        return cnt;
    }
};