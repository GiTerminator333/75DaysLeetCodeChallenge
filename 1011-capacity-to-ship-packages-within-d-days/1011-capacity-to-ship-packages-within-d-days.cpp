class Solution {
public:
    int findDays(vector<int>& v, int cap) {
        int i = 0;
        int sum = 0;
        int days = 1;

        for(int i=0; i<v.size(); i++){
            if(sum + v[i] > cap){
                days++;
                sum = v[i];
            }
            else sum += v[i];
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        //capacity can never be less than max weight
        int lo = INT_MIN; //maxi
        int hi = 0; //sum
        for(int i=0; i<weights.size(); i++){
            if(weights[i] > lo) lo = weights[i];
            hi += weights[i];
        }
        //less capacity -> more days 
        while(lo <= hi){
            int mid = (lo + hi)/2;
            int dayCnt = findDays(weights, mid);

            if(dayCnt <= days){
                hi = mid - 1; //min capacity
            }

            else lo = mid + 1;
        }

        return lo;
    }
};