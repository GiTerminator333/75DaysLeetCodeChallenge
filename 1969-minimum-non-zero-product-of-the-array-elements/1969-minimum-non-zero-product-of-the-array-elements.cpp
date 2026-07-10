class Solution {
    const int MOD = 1e9 + 7;
public:
    long long modPow(long long base, long long exp) {
        long long res = 1;
        base %= MOD;

        while (exp > 0) {
            if (exp & 1)
                res = (res * base) % MOD;

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return res;
    }

    int minNonZeroProduct(int p) {
        //Solved Myself
        //x = 2^p - 1
        // u = x - 1 = 2^(p-1) - 2
        //u/2 = ciel(x/2)
        //u/2 pairs of (1, u)
        //ans = pow(u, u/2) * x

        long long x = (1LL<<p) - 1;

        //pow(u, u/2)
        long long u = x - 1;
        long long exp = u>>1;
        long long ans = 1;

        return (modPow(u, exp) * (x % MOD)) % MOD;
    }
};