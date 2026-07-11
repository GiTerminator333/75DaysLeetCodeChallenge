class Solution {
public:
    void helper(vector<string> &ans, string &s, int idx) {
        if(idx == s.length()){
            ans.push_back(s);
            return;
        }

        if(isalpha(s[idx])){
            char og = s[idx];
            
            s[idx] = tolower(s[idx]);
            helper(ans, s, idx + 1);
            s[idx] = og;
            
            s[idx] = toupper(s[idx]);
            helper(ans, s, idx + 1);
            s[idx] = og;
        }
        else{
            helper(ans, s, idx + 1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        helper(ans, s, 0);
        return ans;
    }
};