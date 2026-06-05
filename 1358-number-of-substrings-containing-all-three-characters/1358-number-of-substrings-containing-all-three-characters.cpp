class Solution {
public:
    int countSubarrays(unordered_map<char, int> &mp, string&s, int limit) {
        int l=0, r=0;
        int count = 0;
        while(r < s.size()){
            mp[s[r]]++;

            while(mp.size() > limit){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }

            count += (r - l + 1);
            r++;
        }
        mp.clear();
        return count;
    }
    int numberOfSubstrings(string s) {
       unordered_map<char, int>mp;
       return countSubarrays(mp, s, 3) - countSubarrays(mp, s, 2); 
    }
};