class Solution {
public:
int dp[46];
int solve(int n){
    if(n==0)return 1;
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];
    int a = solve(n-1);//climb 1 step
    int b = solve(n-2);//climb 2 step
    dp[n] = a+b;
    return dp[n];
}
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};