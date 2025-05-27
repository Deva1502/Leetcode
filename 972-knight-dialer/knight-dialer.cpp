class Solution {
public:
    int mod = 1e9 + 7;
    int dp[5001][10];
    int solve(int n, int i) {
        if (n == 0)
            return 1;
        if (i == 5)
            return 0;
        if (dp[n][i] != -1)
            return dp[n][i];
        int vl = 0;
        if (i == 0)
            vl = (solve(n - 1, 4) + solve(n - 1, 6)) % mod;
        if (i == 1)
            vl = (solve(n - 1, 8) + solve(n - 1, 6)) % mod;
        if (i == 2)
            vl = (solve(n - 1, 7) + solve(n - 1, 9)) % mod;
        if (i == 3)
            vl = (solve(n - 1, 4) + solve(n - 1, 8)) % mod;
        if (i == 4)
            vl = ((solve(n - 1, 0) + solve(n - 1, 3)) % mod + solve(n - 1, 9)) %
                 mod;
        if (i == 6)
            vl = ((solve(n - 1, 0) + solve(n - 1, 1)) % mod + solve(n - 1, 7)) %
                 mod;
        if (i == 7)
            vl = (solve(n - 1, 2) + solve(n - 1, 6)) % mod;
        if (i == 8)
            vl = (solve(n - 1, 1) + solve(n - 1, 3)) % mod;
        if (i == 9)
            vl = (solve(n - 1, 4) + solve(n - 1, 2)) % mod;
        dp[n][i] = vl;
        return dp[n][i];
    }

    int knightDialer(int n) {
        int vl = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 10; i++) {
            vl = (vl + solve(n - 1, i)) % mod;
        }
        return vl;
    }
};