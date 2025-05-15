class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& w, vector<int>& g) {
        int n=w.size();
        vector<string>ans;
        ans.push_back(w[0]);
        for(int i = 1;i<g.size();){
            if(g[i]!=g[i-1])ans.push_back(w[i]);
            i++;
        }
        return ans;
        
    }
};