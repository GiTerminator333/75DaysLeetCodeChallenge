class Solution {
public:
    int findBouquet(vector<int> &v, int &k, int &day){
        int res = 0;
        int count = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i] > day){
                res += count/k;
                count = 0;
            }
            else count++;
        }
        
        res += count/k;
        return res;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long)bloomDay.size() < 1LL * m * k) return -1;
        
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            //finding no of bouquet for a day
            int nbouquet = findBouquet(bloomDay, k, mid);

            // if(nbouquet == m) return mid;
            if(nbouquet >= m){
                hi = mid - 1;   //min no. of day to make nbouquet = m  <== lower bound
            }
            else{
                lo = mid + 1;
            }
        }

        return lo; 
    }
};