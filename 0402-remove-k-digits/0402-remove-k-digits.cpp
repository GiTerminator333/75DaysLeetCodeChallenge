class Solution {
public:
    string removeKdigits(string num, int k) {
        //i am using stack but can directly use string as a stack as well
        if(k == num.length()) return "0";
        stack<char> st;

        for(int i=0; i<num.length(); i++){
            while(!st.empty() && st.top() > num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k > 0){
            //123456
            st.pop();
            k--;
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        //removing front 0
        int i = ans.length() - 1;
        while(ans[i] == '0' && ans.length() > 1){
            // 00000 -> 0
            ans.pop_back();
            i--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};