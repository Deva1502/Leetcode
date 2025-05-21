class Solution {
public:
    vector<pair<int, int>> p; 
    int dp[601][101][101];    // 3D DP array for [index][m][n]

    void c01(string s) {
        int c0 = count(s.begin(), s.end(), '0');
        int c1 = s.size() - c0;
        p.push_back({c0, c1});
    }

    int solve(int i, int m, int n) {
        if (i >= p.size())
            return 0;

        if (dp[i][m][n] != -1)
            return dp[i][m][n];

        int nt = solve(i + 1, m, n);

        int tk = 0;
        if (p[i].first <= m && p[i].second <= n) {
            tk = 1 + solve(i + 1, m - p[i].first, n - p[i].second);
        }
        return dp[i][m][n] = max(tk, nt);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        p.clear();
        for (auto i : strs) {
            c01(i);
        }
        memset(dp, -1, sizeof(dp));

        return solve(0, m, n);
    }
};