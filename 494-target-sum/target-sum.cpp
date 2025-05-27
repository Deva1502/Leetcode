class Solution {
public:
    int dp[21][40001];
    int vl=20000;
    int solve(vector<int>& nums, int target,int sm, int i, int n) {
        if(i==n){
            if(sm==target)return 1;
            else return 0;
        }
        if(dp[i][sm+vl]!=-1)return dp[i][sm+vl];
        int a = solve(nums,target,sm+nums[i],i+1,n);//adding
        int b = solve(nums,target,sm-nums[i],i+1,n);//sub
        return dp[i][sm+vl] = a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return solve(nums, target, 0,0, n);
    }
};