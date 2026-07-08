class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26);
        for(int i=0; i<word.length(); i++){
            mp[word[i] - 'a']++;
        }

        auto cmp = [&](int a, int b){
            return a > b;
        };

        sort(mp.begin(), mp.end(), cmp);

        int totClicks = 0;
        int cnt = 0;
        int clicks = 1;

        for(int i=0; i<26; i++){
            if(cnt == 8){
                cnt = 0;
                clicks++;
            }

            totClicks += mp[i] * clicks;
            cnt++;
        }

        return totClicks;
    }
};