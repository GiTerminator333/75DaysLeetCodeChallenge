class FreqStack {
    unordered_set<int> set;
    stack<int> st;
    unordered_map<int, int> mp;
    int maxFreq = 0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        mp[val]++;
        if(mp[val] < maxFreq) return;
        else if(mp[val] > maxFreq){
            set.clear();
            maxFreq = mp[val];
        }
        // else if(mp[val] == maxFreq){
        // }
        set.insert(val);
    }
    
    int pop() {
        int ans = -1;
        stack<int> temp;
        while(!st.empty()){
            if(set.find(st.top()) != set.end()){
                mp[st.top()]--;
                set.erase(st.top());
                ans = st.top();
                st.pop();
                break;
            }
            temp.push(st.top());
            st.pop();
        }

        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }

        if(set.empty()){
            maxFreq = 0;
            for(auto &[key, freq] : mp){
                if(freq < maxFreq) continue;
                else if(freq > maxFreq){
                    set.clear();
                    maxFreq = freq;
                }
                set.insert(key);
            }
        }

        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */