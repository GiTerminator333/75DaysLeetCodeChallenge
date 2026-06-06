class MinStack {
    stack <long long> st;
    long long mini = LONG_MAX;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            mini = value;
            st.push(value);
        }
        else if(mini > value){
            //mini => outdated prev min
            long long x = (2LL*value - mini);
            st.push(x);
            mini = value;
        }
        else{
            st.push(value);
        }
    }
    
    void pop() {
        //2*newMini - prevMini = stack.val
        //==> stack.val < newMini
        if(st.top() < mini){
            mini = 2LL*mini - st.top();
        }
        st.pop();
        if(st.empty()) mini = LONG_MAX; //reset
    }
    
    int top() {
        if(st.top() < mini) return (int)mini;
        else return (int)st.top();
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */