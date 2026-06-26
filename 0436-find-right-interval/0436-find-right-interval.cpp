class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> start; //store start
        for(int i=0; i<intervals.size(); i++){
            start.push_back({intervals[i][0], i});
        } 

        sort(start.begin(), start.end());
        vector<int> ans;
        for(int i=0; i<intervals.size(); i++){
            int idx = lowerBoundIdx(start, intervals[i][1]);
            ans.push_back(idx);
        }

        return ans;
    }

    int lowerBoundIdx(vector<pair<int, int>> &v, int &target){
        int lo = 0, hi = v.size() - 1;
        while(lo <= hi){
            int mid = (lo + hi)>>1;
            if(v[mid].first >= target){
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        return (lo < v.size())? v[lo].second : -1;
    }
};