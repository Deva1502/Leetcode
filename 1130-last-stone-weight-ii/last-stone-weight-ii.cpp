bool dp[31][1501];

class Solution {
   public:
    int lastStoneWeightII(std::vector<int>& stones)
    {
        int sum = 0;
        for (auto& num : stones) {
            sum += num;
        }
        int n = stones.size(), m = sum / 2;
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = true;
            int num = stones[i - 1];
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i - 1][j] || (j >= num && dp[i - 1][j - num]);
            }
        }
        for (int k = m; k > 0; --k) {
            if (dp[n][k]) {
                return sum - 2 * k;
            }
        }
        return stones[0];
    }
};