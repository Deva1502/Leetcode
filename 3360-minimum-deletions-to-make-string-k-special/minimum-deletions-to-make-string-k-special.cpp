class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<char,int>mp;
        for(auto i:word){
            mp[i]++;
        }
        vector<int>vl;
        for(auto i:mp){
            vl.push_back(i.second);
        }
        int ans = INT_MAX;

        //brute force applying -->tc-->O(26)^2
        for(int i = 0;i<vl.size();i++){
            int cnt = 0;
            for(int j = 0;j<vl.size();j++){
                if(vl[i]>vl[j])cnt += vl[j];
                else if(vl[i]+k<vl[j])cnt += vl[j]-vl[i]-k;
            }
            ans = min(ans,cnt);
        }

        return ans;
    }
};