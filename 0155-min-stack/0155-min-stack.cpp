class MinStack {
    stack<int> st;
    int mini = INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(mini > value) mini = value;
        st.push(value);
    }
    
    void pop() {
        if(st.top() == mini){
            st.pop();
            stack<int> temp;
            mini = INT_MAX;

            while(st.size()){
                if(mini > st.top()) mini = st.top();
                temp.push(st.top());
                st.pop();
            }

            while(temp.size()){
                st.push(temp.top());
                temp.pop();
            }
        }

        else st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini;
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