class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> pse(n, -1), nse(n, n);
        stack<int> st;

        //prev smaller and equal
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[i] < arr[st.top()]) st.pop();
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[i] <= arr[st.top()]) st.pop();
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        int sum = 0;
        for(int i=0; i<n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            int add = (1LL * arr[i] * left * right)%MOD;
            sum = (sum + add)%MOD;
        }

        return sum;
    }
};