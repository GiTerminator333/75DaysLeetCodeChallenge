class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int maxSell = 0;
        for(int i = prices.size() - 1; i>=0; i--){
            maxProfit = max(maxProfit, maxSell - prices[i]);
            maxSell = max(maxSell, prices[i]);
        }

        return maxProfit;
    }
};