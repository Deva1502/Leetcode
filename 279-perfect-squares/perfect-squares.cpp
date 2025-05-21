class Solution {
public:
    int solve(vector<int>& coins, vector<vector<int>>& dp, int i, int j) {
        if (j == 0)
            return 0;
        if (j < 0 or i >= coins.size())
            return 1e9;
        if (dp[i][j] != -1)
            return dp[i][j];
        int tk = 1e9;
        if (j >= coins[i])
            tk = 1 + solve(coins, dp, i, j - coins[i]);
        int nt = solve(coins, dp, i + 1, j);
        return dp[i][j] = min(tk, nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int x = solve(coins, dp, 0, amount);
        return (x != 1e9) ? x : -1;
    }
    vector<int> vlu(int n) {
        int vl = 1;
        int vll = 1;
        vector<int> ar;
        while (vll <= n) {
            vll = vl * vl;
            if (vll <= n)
                ar.push_back(vll);
            vl++;
        }
        return ar;
    }
    int numSquares(int n) {
        vector<int> vl = vlu(n);
        return coinChange(vl, n);
    }
};