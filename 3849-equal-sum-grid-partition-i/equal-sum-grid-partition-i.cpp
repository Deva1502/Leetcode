class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long sm = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sm += grid[i][j];
            }
        }
        if (sm % 2) return false;

        vector<long long> rsm, csm;
        for (int i = 0; i < n; i++) {
            long long sm3 = 0;
            for (int j = 0; j < m; j++) {
                sm3 += grid[i][j];
            }
            rsm.push_back(sm3);
        }

        for (int i = 0; i < m; i++) {
            long long sm3 = 0;
            for (int j = 0; j < n; j++) {
                sm3 += grid[j][i];
            }
            csm.push_back(sm3);
        }

        long long sm1 = 0;
        for (int i = 0; i < n - 1; i++) { // row cut between rows
            sm1 += rsm[i];
            if (sm1 * 2 == sm) return true;
        }

        long long sm2 = 0;
        for (int i = 0; i < m - 1; i++) { // col cut between columns
            sm2 += csm[i];
            if (sm2 * 2 == sm) return true;
        }

        return false;
    }
};
