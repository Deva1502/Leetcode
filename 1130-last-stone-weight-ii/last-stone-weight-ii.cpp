class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(), stones.end(), 0);
        int target = total / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int stone : stones) {
            for (int i = target; i >= stone; --i) {
                dp[i] = dp[i] or dp[i - stone];
            }
        }

        for (int i = target; i >= 0; --i) {
            if (dp[i]) {
                return total - (i * 2);
            }
        }

        return -1;
    }
};