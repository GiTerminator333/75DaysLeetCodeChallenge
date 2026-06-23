class Solution {
public:
    const int MOD = 1337;
    int f(long long a, int b){
        long long ans = 1;
        while(b > 0){
            if(b&1){
                ans = ans * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }

        return (int)ans;
    }
    int superPow(int a, vector<int>& b) {
        long long val = a;
        int res = 1;
        int n = b.size();
        //b = [5, 8, 9] ==> 589 ==> ((5*10 + 8)*10)+9
        // (((res * a^5)^10 * a^8)^10 * a^9)
        
        for(int i=0; i<n; i++){
            if(b[i] > 0) res = res * f(val, b[i]) % MOD;
            if(i < n - 1) res = f(res, 10);
        }

        return res;
    }
};