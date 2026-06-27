class Solution {
public:
    typedef pair<int, int> pi;
    const int MOD = 1e9 +7;
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pi> buyQ;
        priority_queue<pi, vector<pi>, greater<pi>> sellQ;
        long long totBuy = 0, totSell = 0; 

        for(auto &order : orders){
            int p = order[0], a = order[1];
            if(order[2] == 1){
                //sell
                while(a > 0 && !buyQ.empty() && p <= buyQ.top().first){
                    int bP = buyQ.top().first;
                    int bA = buyQ.top().second;
                    buyQ.pop();
                    
                    if(bA > a){
                        buyQ.push({bP, bA - a});
                        // totBuy = (totBuy - a)%MOD;
                        totBuy -= a;
                        a = 0;
                        break;
                    } 
                    a -= bA;
                    // totBuy = (totBuy - bA)%MOD;
                    totBuy -= bA;
                }

                if(a > 0){
                    sellQ.push({p, a});
                    // totSell = (totSell + a)%MOD;
                    totSell += a;
                }
            }
            else{
                //buy
                while(a > 0 && !sellQ.empty() && p >= sellQ.top().first){
                    int sP = sellQ.top().first;
                    int sA = sellQ.top().second;
                    sellQ.pop();
                    
                    if(sA > a){
                        sellQ.push({sP, sA - a});
                        // totSell = (totSell - a)%MOD;
                        totSell -= a;
                        a = 0;
                        break;
                    } 
                    a -= sA;
                    // totSell = (totSell - sA)%MOD;
                    totSell -= sA;
                }

                if(a > 0){
                    buyQ.push({p, a});
                    // totBuy = (totBuy + a)%MOD;
                    totBuy += a;
                }
            }
        }

        return (int)((totBuy + totSell)%MOD);
    }
};