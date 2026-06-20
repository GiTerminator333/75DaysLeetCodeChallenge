class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int lo = 0, hi = n - 1;

        int ans = 0;
        while(lo <= hi){
            int mid = (lo + hi)>>1;
            int moreEquals = n - mid;
            if(citations[mid] >= moreEquals){
                ans = moreEquals;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        return ans;
    }
};