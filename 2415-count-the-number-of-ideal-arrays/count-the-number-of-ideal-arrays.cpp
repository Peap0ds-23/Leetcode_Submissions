
using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        int maxK = 0;
        while ((1 << maxK) <= maxValue) ++maxK;
        maxK = min(maxK, n);

        vector<vector<int>> dp(maxK + 1, vector<int>(maxValue + 1));
        for (int v = 1; v <= maxValue; ++v)
            dp[1][v] = 1;

        for (int k = 2; k <= maxK; ++k) {
            for (int v = maxValue; v >= 1; --v) {
                ll sum = 0;
                for (int m = v * 2; m <= maxValue; m += v) {
                    sum += dp[k - 1][m];
                    if (sum >= MOD) sum -= MOD;
                }
                dp[k][v] = sum;
            }
        }

        vector<int> sumdp(maxK + 1);
        for (int k = 1; k <= maxK; ++k) {
            ll s = 0;
            for (int v = 1; v <= maxValue; ++v) {
                s += dp[k][v];
                if (s >= MOD) s -= MOD;
            }
            sumdp[k] = s;
        }

        vector<ll> fact(n + 1, 1), invfact(n + 1, 1);
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        invfact[n] = modInv(fact[n]);
        for (int i = n; i >= 1; --i)
            invfact[i - 1] = invfact[i] * i % MOD;

        auto comb = [&](int N, int R) -> ll {
            if (R < 0 || R > N) return 0;
            return fact[N] * invfact[R] % MOD * invfact[N - R] % MOD;
        };

        ll ans = 0;
        for (int k = 1; k <= maxK; ++k) {
            ans = (ans + comb(n - 1, k - 1) * sumdp[k]) % MOD;
        }
        return (int)ans;
    }

private:
    ll modPow(ll a, ll e = MOD - 2) {
        ll r = 1;
        while (e) {
            if (e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }

    ll modInv(ll a) {
        return modPow(a);
    }
};