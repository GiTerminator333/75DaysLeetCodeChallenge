class Solution {
public:
    vector<string> addOperators(string s, int target) {
        vector<string> ans;
        // long eval = 0;
        // long lastVal = 0; //eval (op) lastVal = new_eval
        //lastVal needed so that the effect of the last op is reverse so that the multiplication could be done acc to the BODMAS 
        // string path = "";
        solve(ans, s, target, 0, "", 0, 0);

        return ans;
    }

    void solve(vector<string> &ans, string &s, int &target, int idx, const string &path, long eval, long lastVal){
        if(idx == s.length()){
            if(eval == target){
                ans.push_back(path);
            }
            return;
        }

        string currStr = "";
        long num = 0; 

        //loop of merging digits
        for(int i=idx; i<s.length(); i++){
            if(i > idx && s[idx] == '0') return; //case of leading 0 => no need to merge, 0 sirf alkele lenge if its coming before

            currStr += s[i];
            num = num*10 + s[i] - '0';

            if(idx == 0){
                //pehli recursion call for the number ==> take number as it is
                solve(ans, s, target, i+1, path + currStr, num, num); //eval = lastVal
            }
            else{
                solve(ans, s, target, i+1,path + '+' + currStr, eval  + num, num);
                solve(ans, s, target, i+1,path + '-' + currStr, eval  - num, -num);

                solve(ans, s, target, i+1,path + '*' + currStr, (eval - lastVal) + (lastVal * num) , lastVal * num);
                //remove lastVal then multiply and add it back
            }
        }
    }
};