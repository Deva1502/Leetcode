class Solution {
public:
    int dp[100001][2];
    int solve(vector<int>& a, vector<int>& b, int i, int p) {
        if (i == a.size())
            return 0;
        if (dp[i][p] != -1)
            return dp[i][p];
        int ans = INT_MAX;
        int prev1 = a[i - 1], prev2 = b[i - 1];
        if (p)
            swap(prev1, prev2);
        // no swap =
        if (a[i] > prev1 and b[i] > prev2)
            ans = solve(a, b, i + 1, 0);
        // swap
        if (a[i] > prev2 && b[i] > prev1) {
            int sw = solve(a, b, i + 1, 1);
            if (sw != INT_MAX)
                ans = min(ans, 1 + sw);
        }

        return dp[i][p] = ans;
    }

    int minSwap(vector<int>& a, vector<int>& b) {
        int n = a.size();
        a.insert(a.begin(), -1);
        b.insert(b.begin(), -1);
        memset(dp, -1, sizeof(dp));
        return solve(a, b, 1, 0);
    }
};