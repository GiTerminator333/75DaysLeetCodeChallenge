class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0;
        int maxi = 0;
        for(int i=0; i<gain.size(); i++){
            alt += gain[i];
            maxi = max(maxi, alt);
        }

        return maxi;
    }
};