class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        //force = diff of pos
        //min force to maximize
        sort(position.begin(), position.end());

        int mini = INT_MAX;
        for(int i=0; i<position.size() - 1; i++){
            if(mini > position[i + 1] - position[i]){
                mini = position[i + 1] - position[i];
            }
        }

        int lo = mini, hi = position[position.size() - 1] - position[0];

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
