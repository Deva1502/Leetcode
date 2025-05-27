class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sm = accumulate(nums.begin(),nums.end(),0);
        if(sm%2)return false;
        sm/=2;
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sm+1,false));
        for(int i = 0;i<n+1;i++){
            for(int j=0;j<sm+1;j++){
                if(i==0)dp[i][j] = false;
                if(j==0)dp[i][j] = true;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j = 1;j<=sm;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sm];
    }
};