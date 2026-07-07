class Solution {
public:
    void helper(int n, int zeroes, int ones, vector<string> &v, string& ip){
        if(zeroes + ones > n) return;
        if(zeroes + ones == n){
            if(n >= 2 && ones < 1) return;
            v.push_back(ip);
            return;
        }

        if(!ip.length() || ip.back() != '0'){
            ip.push_back('0');
            helper(n, zeroes + 1, ones, v, ip);
            ip.pop_back();
        }

        ip.push_back('1');
        helper(n, zeroes, ones + 1, v, ip);
        ip.pop_back();
    }
    vector<string> validStrings(int n) {
        vector<string> v;
        string s = "";
        helper(n, 0, 0, v, s);

        return v;
    }
};