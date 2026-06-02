class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size(), m = waterStartTime.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //meth 1 land -> water
                int m1 = landStartTime[i] + landDuration[i];
                m1 += (waterStartTime[j] <= m1)? waterDuration[j] : (waterStartTime[j] - m1) + waterDuration[j];

                //meth 2 water -> land
                int m2 = waterStartTime[j] + waterDuration[j];
                m2 += (landStartTime[i] <= m2)? landDuration[i] : (landStartTime[i] - m2) + landDuration[i];

                ans = min({ans, m1, m2});
            }
        }

        return ans;
    }
};