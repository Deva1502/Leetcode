// class Solution {
// public:
//     double dp[101][26][26];

//     double solve(int n, int k, int i, int j) {
//         if (i < 0 || i >= n || j < 0 || j >= n) return 0;
//         if (k == 0) return 1;
//         if (dp[k][i][j] != -1.0) return dp[k][i][j];

//         double a = solve(n, k - 1, i - 2, j + 1);
//         double b = solve(n, k - 1, i - 2, j - 1);
//         double c = solve(n, k - 1, i + 2, j + 1);
//         double d = solve(n, k - 1, i + 2, j - 1);
//         double e = solve(n, k - 1, i - 1, j + 2);
//         double f = solve(n, k - 1, i - 1, j - 2);
//         double g = solve(n, k - 1, i + 1, j + 2);
//         double h = solve(n, k - 1, i + 1, j - 2);

//         return dp[k][i][j] = (a + b + c + d + e + f + g + h) / 8.0;
//     }

//     double knightProbability(int n, int k, int row, int column) {
//         // Correct way to initialize a 3D double array with -1.0
//         for (int i = 0; i <= k; ++i)
//             for (int j = 0; j < n; ++j)
//                 for (int l = 0; l < n; ++l)
//                     dp[i][j][l] = -1.0;

//         return solve(n, k, row, column);
//     }
// };


class Solution {
public:
    vector<vector<vector<double>>> dp;

    double solve(int n, int k, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n) return 0;
        if (k == 0) return 1;
        if (dp[k][i][j] != -1.0) return dp[k][i][j];

        double moves = 0;
        vector<pair<int, int>> directions = {
            {-2, 1}, {-2, -1}, {2, 1}, {2, -1},
            {-1, 2}, {-1, -2}, {1, 2}, {1, -2}
        };

        for (auto& d : directions) {
            moves += solve(n, k - 1, i + d.first, j + d.second);
        }

        return dp[k][i][j] = moves / 8.0;
    }

    double knightProbability(int n, int k, int row, int column) {
        dp = vector<vector<vector<double>>>(
            k + 1, vector<vector<double>>(n, vector<double>(n, -1.0))
        );
        return solve(n, k, row, column);
    }
};

