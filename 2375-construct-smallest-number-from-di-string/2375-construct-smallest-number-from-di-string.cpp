class Solution {
public:
    string smallestNumber(string pattern) {
        char count = '1';
        string s;
        stack<char> st;
        // st.push(count);
        for(int i=0; i<pattern.size(); i++){
            st.push(count);
            if(pattern[i] == 'I'){
                while(!st.empty()){
                    s.push_back(st.top());
                    st.pop();
                }
            }
            count++;
        }

        st.push(count); //last number

        while(st.size()){
            s.push_back(st.top());
            st.pop();
        }

        return s;
    }
};