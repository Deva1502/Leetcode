class Solution {
public:
    int totalsum=0;
    int solve(vector<int>&stones,int i,int sum){
        //base case
        if(i>=stones.size()){
            int g1=sum;
            int g2=totalsum-sum;
            return abs(g1-g2);
        }
        int ans1=solve(stones,i+1,sum+stones[i]);
        int ans2=solve(stones,i+1,sum);
        return min(ans1,ans2);
    }
    int solveUsingMem(vector<int>&stones,int i,int sum,vector<vector<int>>&dp){
        //base case
        if(i>=stones.size()){
            int g1=sum;
            int g2=totalsum-sum;
            return abs(g1-g2);
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int ans1=solveUsingMem(stones,i+1,sum+stones[i],dp);
        int ans2=solveUsingMem(stones,i+1,sum,dp);
        dp[i][sum]=min(ans1,ans2);
        return dp[i][sum];
    }
    int lastStoneWeightII(vector<int>& stones) {
        for(int i=0;i<stones.size();i++){
            totalsum+=stones[i];
        }
        // return solve(stones,0,0);

        int n=stones.size();
        vector<vector<int>>dp(n+1,vector<int>(totalsum+1,-1));
        return solveUsingMem(stones,0,0,dp);
    }
};