class Solution {
public:
int dp[101][101];
int solve(int i ,int j){
    if(i==0 and j == 0){
        return 1;
    }
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int a = solve(i-1,j);
    int b = solve(i,j-1);
    return dp[i][j] = a+b;
}
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(m-1,n-1);
    }
};