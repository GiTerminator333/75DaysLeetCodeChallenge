class Solution {
public:
    vector<int> countBits(int n) {
        int lshift = 0; //check if idx is pow of 2
        // int cnt = 1;
        vector<int> v(n+1, 0);

        for(int i=1; i<n+1; i++){
            if(i == 1<<lshift){
                v[i] = 1;
                lshift++;
            }
            else{
                int prevPow = 1<<(lshift-1);
                int rem = i - prevPow;
                v[i] = v[prevPow] + v[rem];
            }
        }

        return v;
    }
};