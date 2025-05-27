class Solution {
public:
    int dp[201][10001];
    int solve(vector<int>& nums, int target,int i){
        int n = size(nums);
        if(target==0)return 1;
        if(i==n or target<0)return 0;
        if(dp[i][target]!=-1)return dp[i][target];
        int tk = solve(nums,target-nums[i],0);
        int nott=solve(nums,target,i+1);
        // int c = solve(nums,target,i);
        dp[i][target] = tk+nott;
        return dp[i][target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,target,0);
    }
};