class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<char> st;
        int i = 0;
        while(i < s.length()){
            while(i < s.length() && s[i] == '('){
                st.push(s[i]);
                i++;
            }
            score += (1 << (st.size() - 1));
            while(i < s.length() && s[i] == ')'){
                st.pop();
                i++;
            }
        }

        return score;
    }
};