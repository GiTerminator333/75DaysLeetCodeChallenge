class TopVotedCandidate {
    vector<int> prefixRes;
    vector<int> T;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        T = times;
        unordered_map<int, int> mp;
        int maxVote = INT_MIN;
        int currWinner = -1; //max voted candidate
        for(int &c : persons){
            mp[c]++;
            if(mp[c] >= maxVote){
                maxVote = mp[c];
                currWinner = c;
            }
            prefixRes.push_back(currWinner);
        }
    }
    
    int q(int t) {
        //finding uppwer bound idx of time
        int n = T.size();
        if(t >= T[n-1]) return prefixRes[n-1];

        int lo = 0, hi = n-1;

        while(lo <= hi){
            int mid = (lo + hi)>>1;
            if(T[mid] > t){
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        return prefixRes[lo - 1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */