class Solution {
public:
    bool isPossible(vector<int>&houses, vector<int> &heaters, int radius){
        int i = 0, j = 0;

        while(i < houses.size() && j < heaters.size()){
            if(houses[i] > heaters[j] + radius) j++;
            else if(houses[i] < heaters[j] - radius) return false;
            else i++;
        }

        return (i == houses.size() && j <= heaters.size());
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int lo = 0, hi = max((houses.back() - heaters[0]), (heaters.back() - houses[0]));
        

        //if heating possible at curr r go lower
        while(lo <= hi){
            int mid = (lo + hi)>>1;

            if(isPossible(houses, heaters, mid)){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        return lo;
    }
};