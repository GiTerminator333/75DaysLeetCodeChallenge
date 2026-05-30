class Solution {
public:
    int findSum(vector<int> &v, int &x, int &t){
        int res = 0;
        for(int i=0; i<v.size(); i++){
            if(res > t) break;
            res += ceil((double)v[i]/x);
        }

        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        if(threshold == nums.size()) return hi;
        //bigger divisor smaller sum
        int ans = INT_MAX;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(findSum(nums,mid,threshold) <= threshold){
                if(ans > mid) ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        return ans;
    }
};