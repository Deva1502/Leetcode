class Solution {
public:
int dp[201][201];
int solve(int i,int j,int n,int m,vector<vector<int>>& grid){
    if(dp[i][j]!=-1)return dp[i][j];
    if(i>=n or j>=m)return INT_MAX;
    if(i==n-1 and j==m-1)return grid[i][j];
    int right = INT_MAX, down = INT_MAX;
    if (i + 1 < n) right =grid[i][j]+ solve(i+1,j,n,m,grid);
    if (j + 1 < m) down = grid[i][j]+ solve(i,j+1,n,m,grid);
    return dp[i][j]=min(right,down);
}
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n = grid.size(),m=grid[0].size();
        return solve(0,0,n,m,grid);
    }
};