class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mp(26, 0);
        int l=0, r=0, maxlen = 0, maxfreq = 0;

        while(r < s.length()){
            mp[s[r] - 'A']++;

            maxfreq = max(maxfreq, mp[s[r] - 'A']); 

            //shrinking
            // int tot = r - l + 1; //tot letters computed 
            while((r - l + 1) - maxfreq > k){
                mp[s[l] - 'A']--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};