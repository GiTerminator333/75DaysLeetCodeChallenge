class Solution {
public:
    const int MOD = 1e9 + 7;
    int countGoodNumbers(long long n) {
        long long a = 20, b = n/2;  
        a %= MOD;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }

        // res = res * res % MOD;
        if(n&1) res = res * 5 % MOD;
        return (int)res;
    }
};