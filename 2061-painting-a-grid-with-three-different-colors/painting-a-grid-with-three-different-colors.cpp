class Solution {
public:
    int mod = 1e9 + 7;

    vector<vector<int>> generateValidColumns(int m) {
        vector<vector<int>> valid;
        vector<int> path;
        function<void()> dfs = [&]() {
            if (path.size() == m) {
                valid.push_back(path);
                return;
            }
            for (int color = 0; color < 3; ++color) {
                if (!path.empty() && path.back() == color) continue;
                path.push_back(color);
                dfs();
                path.pop_back();
            }
        };
        dfs();
        return valid;
    }

    unordered_map<int, vector<int>> buildTransitions(const vector<vector<int>>& valid) {
        unordered_map<int, vector<int>> compatible;
        int k = valid.size();
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                bool ok = true;
                for (int r = 0; r < valid[0].size(); ++r) {
                    if (valid[i][r] == valid[j][r]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) compatible[i].push_back(j);
            }
        }
        return compatible;
    }

    int colorTheGrid(int m, int n) {
        auto valid = generateValidColumns(m);
        auto transitions = buildTransitions(valid);
        int k = valid.size();

        vector<vector<int>> dp(n, vector<int>(k, 0));
        for (int i = 0; i < k; ++i) dp[0][i] = 1;

        for (int col = 1; col < n; ++col) {
            for (int curr = 0; curr < k; ++curr) {
                for (int prev : transitions[curr]) {
                    dp[col][curr] = (dp[col][curr] + dp[col - 1][prev]) % mod;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < k; ++i) {
            res = (res + dp[n - 1][i]) % mod;
        }
        return res;
    }
};
