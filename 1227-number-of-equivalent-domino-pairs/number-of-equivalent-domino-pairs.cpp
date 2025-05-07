class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int>vl(100,0);
        int ans=0;
        int n = dominoes.size();
        for(int i =0;i<n;i++){
           int x = dominoes[i][0];
           int y=dominoes[i][1];
           int p = 10*max(x,y)+min(x,y);
           ans+=vl[p];
           vl[p]++;

        }
        return ans;
    }
};