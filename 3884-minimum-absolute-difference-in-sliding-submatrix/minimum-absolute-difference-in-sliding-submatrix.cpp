class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));

        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j <= m - k; j++) {
                vector<int> vals;
                for (int a = 0; a < k; a++) {
                    for (int b = 0; b < k; b++) {
                        vals.push_back(grid[i + a][j + b]);
                        cout<<grid[i + a][j + b]<<" ";
                    }
                }
                cout<<endl;
                sort(vals.begin(), vals.end());
                int minDiff = (vals.size()==1)?0:INT_MAX;
                bool p = true;
                for (int x = 1; x < vals.size(); x++) {
                    if(vals[x] != vals[x - 1])
                    {minDiff = min(minDiff, abs(vals[x] - vals[x - 1]));p = false;}
                }
                ans[i][j] =(p)?0: minDiff;
                // cout<<ans[i][j]<<" ";
            }
        }
        return ans;
    }
};
