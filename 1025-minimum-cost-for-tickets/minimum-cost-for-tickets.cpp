class Solution {
public:
    unordered_map<int,int>mp;
    int dp[366];
    int solve(vector<int>&days,vector<int>&costs,int i){
        if(i > 365) return 0;
        if(mp.find(i)==mp.end()){
            return solve(days,costs,i+1);
        }
        if(dp[i]!=-1)return dp[i];
        if(i>days[days.size()-1])return 0;
        int a = costs[0]+solve(days,costs,i+1);
        int b = costs[1]+solve(days,costs,i+7);
        int c = costs[2]+solve(days,costs,i+30);
        return dp[i]=min({a,b,c});

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(auto i:days){
            mp[i]++;
        }
        memset(dp,-1,sizeof(dp));
        return solve(days,costs,1);
    }
};