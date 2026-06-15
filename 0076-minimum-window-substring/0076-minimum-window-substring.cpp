class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(char c : t) mp[c]++;

        int l = 0, r = 0;
        int mini = INT_MAX;
        int start = -1, end = -1;

        //comparator to find all map val < 0
        auto comp = [&](const auto pair){
            return pair.second <= 0;
        };

        while(r < s.length()){
            //expand
            mp[s[r]]--;

            //shrink
            //if map val is ive -> faltu ka word -> remove
            while(mp[s[l]] < 0){
                mp[s[l++]]++;
            }

            //update
            if(mini > r - l + 1 && all_of(mp.begin(), mp.end(), comp)){
                start = l;
                end = r;
                mini = r - l + 1;
            }

            r++;
        }
        if(start == -1){
            //no string assigned
            return "";
        }
        return s.substr(start, end - start + 1);
    }
};