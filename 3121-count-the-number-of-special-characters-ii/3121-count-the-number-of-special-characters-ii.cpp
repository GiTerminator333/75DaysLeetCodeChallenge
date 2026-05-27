class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> hash(52, -1);

        for(int i=0; i<word.length(); i++){
            char s = word[i];
            if((s >= 'A' && s <= 'Z') && (hash[s - 'A' + 26] == -1)){
                hash[s - 'A' + 26] = i;
            }
            else if(s >= 'a' && s <= 'z'){
                hash[s - 'a'] = i;
            }
        }

        int res = 0;
        for(int i=0; i<26; i++){
            if(hash[i] == -1) continue;
            if(hash[i] < hash[i + 26]) res++;
        }

        return res;
    }
};