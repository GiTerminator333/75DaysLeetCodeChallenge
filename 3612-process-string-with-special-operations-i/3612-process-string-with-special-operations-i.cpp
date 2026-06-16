class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(char &c : s){
            if(c == '*'){
                if(res.size()) res.pop_back();
            }
            else if(c == '#'){
                string temp = res;
                res.append(temp);
            }
            else if(c == '%'){
                reverse(res.begin(), res.end());
            }
            else{
                res.push_back(c);
            }
        }

        return res;
    }
};