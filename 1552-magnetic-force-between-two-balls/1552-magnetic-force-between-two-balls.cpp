class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        //force = diff of pos
        //min force to maximize
        sort(position.begin(), position.end());

        int lo = 1, hi = position.back() - position[0];

        while(lo <= hi){
            int mid = (lo + hi)>>1;

            if(isMinimum(position, mid, m)){
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        return hi;
    }

    bool isMinimum(vector<int> &v, int &target, int &m){
        int ballCount = 1;
        int i = 0;
        int j = 0;
        while(j < v.size()){
            if(v[j] - v[i] >= target){
                ballCount++;
                i = j;
            }
            j++;
        }

        return ballCount >= m;
    }
};
