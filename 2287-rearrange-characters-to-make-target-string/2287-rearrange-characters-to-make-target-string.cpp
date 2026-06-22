class Solution {
public:
    int rearrangeCharacters(string text, string target) {
        vector<int> freq(26, 0);
        for(int i=0; i<text.size(); i++){
            freq[text[i] - 'a']++;
        }

        vector<int> rep(26, 0);
        for(char &c : target){
            rep[c - 'a']++;
        }

        int ans = INT_MAX;
        for(char &c : target){
            ans = min(ans, freq[c - 'a']/rep[c - 'a']);
        }
        

        return ans;
    }
};