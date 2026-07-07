class Solution {
public:
    void helper(int o, int c, vector<string> &v, string &ip){
        if(o == 0 && c == 0){
            v.push_back(ip);
            return;
        }

        if(o != 0){
            ip.push_back('(');
            helper(o - 1, c, v, ip);
            ip.pop_back();
        }

        if(c > o){
            ip.push_back(')');
            helper(o, c - 1, v, ip);
            ip.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s = "";
        helper(n, n, v, s);
        return v;
    }
};