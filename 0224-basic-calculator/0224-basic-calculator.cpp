class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1;
        stack<int> st;

        int i = 0;
        while (i < s.length()) {

            if (isdigit(s[i])) {
                unsigned int num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * num;
                continue;         
            }

            if (s[i] == '+')
                sign = 1;
            else if (s[i] == '-')
                sign = -1;
            else if (s[i] == '(') {
                //store result before ( and the sign before (
                st.push(result);
                st.push(sign);
                //reset to cal the brackets separately
                result = 0;
                sign = 1;
            }
            else if (s[i] == ')') {
                int prevSign = st.top(); st.pop();
                int prevResult = st.top(); st.pop();
                result = prevResult + prevSign * result;
            }

            i++;
        }

        return result;
    }
};