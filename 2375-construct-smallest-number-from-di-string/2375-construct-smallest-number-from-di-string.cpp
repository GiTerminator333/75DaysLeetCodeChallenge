class Solution {
public:
    int mini = INT_MAX;
    string res;
    void helper(string &pattern, string &s, vector<bool> &visited, int idx){
        if(idx < 0){
            int val = stoi(s);
            if(mini > val){
                mini = val;
                res = s;
            }
            return;
        }

        for(int i=0; i<9; i++){
            if(!visited[i]){
                char c = '1' + i;
                if((pattern[idx] == 'I' && s[0] < c) || (pattern[idx] == 'D' && s[0] > c)) continue;
                visited[i] = true;
                s.insert(s.begin(), c);
                helper(pattern, s, visited, idx - 1);
                s.erase(s.begin());
                visited[i] = false;
            }
        }
    } 
    string smallestNumber(string pattern) {
        vector<bool> visited (9, false);
        string s;

        int n = pattern.length();

        for(int i = 0; i<9; i++){
            visited[i] = true;
            s.push_back('1' + i);
            helper(pattern, s, visited, n - 1);
            s.pop_back();
            visited[i] = false;
        }

        return res;
    }
};