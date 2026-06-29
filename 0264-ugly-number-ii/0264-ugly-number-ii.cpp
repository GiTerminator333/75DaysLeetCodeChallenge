class Solution {
public:
    int nthUglyNumber(int n) {
        //start with 1
        //mul with all choices 2, 3, 5 ... its like a tree approach
        //put in factors in a minheap...so that u can access factors sequentially ie the min value factors comes to the top to get pop
        // nth min factor is the ans

        unordered_set<long long> st;  //to eliminate duplicate factors
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        pq.push(1);
        st.insert(1);
        vector<int>factors = {2, 3, 5};

        int popCount = 1;
        while(popCount < n){
            int val = pq.top();
            pq.pop();
            popCount++;


            for(int &f : factors){
                if(st.find(1LL * val * f) == st.end()){
                    st.insert(1LL * val * f);
                    pq.push(1LL * val * f);
                }
            }
        }

        return pq.top();
    }
};