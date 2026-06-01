class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int res = 0;
        int i= cost.size() - 1;
        while(i + 1 >= 3){
            res += (cost[i] + cost[i-1]);
            i-=3;
        }

        if(i >= 0) res += (i == 0)? cost[0] : (cost[0] + cost[1]);

        return res;
    }
};