class Solution {
public:
    long long sumMin(vector<int>& arr){
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

        long long sum = 0;
        for(int i=0; i<n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            long long add = (1LL * arr[i] * left * right);
            sum = (sum + add);
        }

        return sum;
    }
    long long sumMax(vector<int>& arr){
        int n = arr.size();
        vector<int> pge(n, -1), nge(n, n);
        stack<int> st;

        //prev greater and equal
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[i] > arr[st.top()]) st.pop();
            if(!st.empty()) pge[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[i] >= arr[st.top()]) st.pop();
            if(!st.empty()) nge[i] = st.top();
            st.push(i);
        }

        long long sum = 0;
        for(int i=0; i<n; i++){
            int left = i - pge[i];
            int right = nge[i] - i;
            long long add = (1LL * arr[i] * left * right);
            sum = (sum + add);
        }

        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums) - sumMin(nums);
        //sum of all subarr max - sum of all subarr min
    }
};